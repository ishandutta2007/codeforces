import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    repeat(readInt()) {
        var (n, k) = readInts()
        var ret = 0
        for (i in 0 until n) {
            var (l, r) = readInts()
            if (l <= k && k <= r) {
                ret = max(ret, r - k + 1)
            }
        }
        println(ret)
    }
}