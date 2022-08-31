/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val nums = readLine()!!.split(" ").map { it.toLong() }
        var a = nums[0]
        var b = nums[1]
        var c = nums[2]
//        println("Test $it: $a $b $c")
        var res = (a - b) * (c / 2)
        if ((c % 2) != 0L)
            res += a
        println(res)
    }
}