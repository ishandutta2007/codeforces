import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    repeat(readInt()) {
        var (n, k) = readInts()
        var s = readLn()

        var bal = 0
        var pieces = 0
        var extra = 0
        for (c in s) {
            if (c == '(') {
                bal++
            } else {
                bal--
                if (bal == 0) {
                    pieces++
                } else {
                    extra++
                }
            }
        }
        println(pieces + min(extra, k))
    }
}