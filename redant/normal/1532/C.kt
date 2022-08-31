/**
 * Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
 */

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        println(CharArray(n) { 'a' + it % k })
    }
}