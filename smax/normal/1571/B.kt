import kotlin.math.max

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var t = readInt()
    repeat(t) {
        var n = readInt()
        var (a, va) = readInts()
        var (c, vc) = readInts()
        var b = readInt()
        println(max(va, vc - (c - b)))
    }
}