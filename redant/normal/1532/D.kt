import java.util.*

/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

fun main() {
    val n = readLine()!!.toInt()
    val nums = readLine()!!.split(" ").map{ it.toInt() }
    Collections.sort(nums)
    println((0..n).filter { it % 2 == 1 }.map{ nums[it] - nums[it-1] }.sum())
}