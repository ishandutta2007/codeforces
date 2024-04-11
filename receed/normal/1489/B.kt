import kotlin.math.min

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val q = readInt()
    repeat(q) {
        var (n, a, b) = readLongs()
        b = min(a * 2, b)
        println(n / 2 * b + n % 2 * a)
    }
}