private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    repeat(readInt()) {
        var (x, y) = readInts()

        var pw = 1
        while (pw * 10 <= y / x) {
            pw *= 10
        }

        var ret = 0
        while (pw > 0) {
            ret += y / (pw * x)
            y %= pw * x
            pw /= 10
        }
        println(ret + y)
    }
}