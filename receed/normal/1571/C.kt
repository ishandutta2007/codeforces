import kotlin.math.max
import kotlin.math.min

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        var l = 0
        var r = 1e6.toInt()
        repeat(n) {
            var (a, b, q) = readStrings()
            a = a.reversed()
            b = b.reversed()
            var k = 0
            while (k < a.length && k < b.length && a[k] == b[k])
                k++
            if (q == "1")
                r = Math.min(r, k)
            else
                l = Math.max(l, k + 1)
        }
        if (l > r) {
            println(0)
            return@repeat
        }
        val ans = (l..r).toList()
        println(ans.size)
        println(ans.joinToString(" "))
    }
}