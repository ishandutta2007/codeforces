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
        val (n, k) = readInts()
        val s = readLn().map{ if (it == '(') 1 else -1}
        var t = 0
        var c = 0
        for (i in s) {
            t += i
            if (t == 0)
                c++
        }
        println(min(n / 2, k + c))
    }
}