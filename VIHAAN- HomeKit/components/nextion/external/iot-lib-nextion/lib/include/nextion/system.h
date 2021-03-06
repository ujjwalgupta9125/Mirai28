#ifndef __NEXTION_OP_SYSTEM_H__
#define __NEXTION_OP_SYSTEM_H__

#include <stdint.h>
#include <stdbool.h>
#include "base/codes.h"
#include "base/types.h"

#ifdef __cplusplus
extern "C"
{
#endif

    /**
     * @brief Sends a command that retrieves a null-terminated string.
     *
     * @details It's the caller responsibility to allocate a buffer big enough to
     * hold the text returned.
     *
     * @param handle Nextion context pointer.
     * @param command A null-terminated string with the command to be sent.
     * @param command_length Command length.
     * @param[in] text Location where the retrieved text will be stored. Must take the null-terminator into account.
     * @param expected_text_length Expected text length that might be retrieved.
     * @param[in] text_length Location where the text length will be stored.
     *
     * @return NEX_OK or NEX_DVC_ERR_INVALID_VARIABLE_OR_ATTRIBUTE.
     */
    nex_err_t nextion_system_get_text(nextion_handle_t handle,
                                      const char *command,
                                      size_t command_length,
                                      char *text,
                                      size_t expected_text_length,
                                      size_t *text_length);

    /**
     * @brief Sends a command that retrieves a signed number.
     *
     * @param handle Nextion context pointer.
     * @param command A null-terminated string with the command to be sent.
     * @param command_length Command length.
     * @param[in] number Location where the retrieved number will be stored.
     *
     * @return NEX_OK or NEX_DVC_ERR_INVALID_VARIABLE_OR_ATTRIBUTE.
     */
    nex_err_t nextion_system_get_number(nextion_handle_t handle,
                                        const char *command,
                                        size_t command_length,
                                        int32_t *number);

    /**
     * @brief Resets the display, losing all volatile configurations.
     * @note It's mandatory, after 100 ms, to call "nextion_init" after calling this function.
     * @return NEX_OK or NEX_FAIL.
     */
    nex_err_t nextion_system_reset(nextion_handle_t handle);

    /**
     * @brief Get the display brightness.
     *
     * @param handle Nextion context pointer.
     * @param persisted If will read the persisted or transient value.
     * @param percentage Brightness level, in percentage (0-100).
     *
     * @return NEX_OK or NEX_FAIL.
     */
    nex_err_t nextion_system_get_brightness(nextion_handle_t handle, bool persisted, uint8_t *percentage);

    /**
     * @brief Set the display brightness.
     *
     * @param handle Nextion context pointer.
     * @param percentage Brightness level, in percentage (0-100).
     * @param persist If the value must persist between resets.
     *
     * @return NEX_OK or NEX_FAIL.
     */
    nex_err_t nextion_system_set_brightness(nextion_handle_t handle, uint8_t percentage, bool persist);

    /**
     * @brief Set how long the display will be on after
     * the last touch.
     * @note Not persisted through resets.
     *
     * @param handle Nextion context pointer.
     * @param seconds Seconds to wait. Range: 0 (disabled) to 65535 (18h 12m 15s).
     *
     * @return NEX_OK or NEX_FAIL.
     */
    nex_err_t nextion_system_set_sleep_no_touch(nextion_handle_t handle, uint16_t seconds);

    /**
     * @brief Set if the display will turn on when touched.
     * @note Not persisted through resets.
     *
     * @param handle Nextion context pointer.
     * @param wake_on_touch If will turn on or not when touched.
     *
     * @return NEX_OK or NEX_FAIL.
     */
    nex_err_t nextion_system_set_wake_on_touch(nextion_handle_t handle, bool wake_on_touch);

#ifdef __cplusplus
}
#endif

#endif //__NEXTION_OP_SYSTEM_H__