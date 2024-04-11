private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    repeat(readInt()) {
        var (a, b, k) = readStrings().map { it.toLong() }
        println(a * ((k + 1) / 2) - b * (k / 2))
    }
}