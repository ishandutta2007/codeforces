import kotlin.math.max

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val t = readInt()
    repeat(t) {
        val (n, k) = readInts()
        val ans = List(n) { readInts() }.filter { it[0] <= k }.maxOfOrNull {it[1]} ?: 0
        println(max(ans - k + 1, 0))
    }
}