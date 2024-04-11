import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    repeat(readInt()) {
        var (n, x, y) = readInts()
        if (x > y) {
            x = y.also { y = x }
        }

        var ret = Int.MAX_VALUE
        for (i in x until y) {
            ret = min(ret, max(i - 1 + min(x - 1, i - x), n - i - 1 + min(y - i - 1, n - y)))
        }
        println(ret)
    }
}