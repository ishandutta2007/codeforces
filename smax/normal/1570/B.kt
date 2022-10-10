import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun calc(a1: Int, a2: Int, k1: Int, k2: Int, n: Int): Int {
    var mn = min(a1 * k1, n)
    return mn / k1 + min((n - mn) / k2, a2)
}

fun main() {
    var a1 = readInt()
    var a2 = readInt()
    var k1 = readInt()
    var k2 = readInt()
    var n = readInt()
    println("${max(min(n - a1 * (k1 - 1) - a2 * (k2 - 1), a1 + a2), 0)} ${max(calc(a1, a2, k1, k2, n), calc(a2, a1, k2, k1, n))}")
}