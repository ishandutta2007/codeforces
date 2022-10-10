private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    repeat(readInt()) {
        var (n, k) = readStrings().map { it.toLong() }
        for (i in 0 until n) {
            print((i % k + 'a'.toInt()).toChar())
        }
        println()
    }
}