import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val t =readInt()
    repeat(t) {
        val (n, a, b) = readInts()
        val x = min(a, b)
        val y = max(a, b)
        println((x until y).map {
            val d1 = it + min(x - 1, it - x) - 1
            val d2 = n - (it + 1) + min(y - (it + 1), n - y)
            max(d1, d2)
        }.minOrNull()!!)
    }
}