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
        val (n, s) = readLongs()
        var l = 1L
        var r = s + 1
        while (r - l > 1) {
            val m = (l + r) / 2
            var cs = 0L
            var cc = 0L
            var cm = m
            while (cm > 1 && cc < n) {
                cs += cm
                cc++
                cm = (cm + 1) / 2
            }
            cs += n - cc
            if (cs <= s)
                l = m
            else
                r = m
        }
        println(l)
    }
}