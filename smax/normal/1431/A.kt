import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map{it.toInt()}

fun main() {
    var t = readInt()
    repeat(t) {
        var n = readInt()
        var a = readStrings().map{it.toLong()}.sorted()
        var ret = 0L
        for (i in 0 until n) {
            ret = max(ret, a[i] * (n - i))
        }
        println(ret)
    }
}