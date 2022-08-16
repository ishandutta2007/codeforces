/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        var nums = readLine()!!.split(" ").map { it.toInt() }.take(2)
        var res = nums[0] + nums[1]
        println(res)
    }
}