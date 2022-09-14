import kotlin.math.max
import kotlin.math.min

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val n = readInt()
    var l = 1
    var r = 0
    val mn = mutableMapOf<Int, Int>()
    val mx = mutableMapOf<Int, Int>()
    repeat(n) {
        val (t, sx) = readStrings()
        val x = sx.toInt()
        if (t == "?")
            println(min(r - mx[x]!!, mn[x]!! - l))
        else {
            val pos = if (t == "L") --l else ++r
            mn[x] = min(mn.getOrDefault(x, pos), pos)
            mx[x] = max(mx.getOrDefault(x, pos), pos)
        }
    }
}