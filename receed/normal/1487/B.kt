private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val t = readInt()
    repeat(t) {
        var (n, k) = readLongs()
        k--
        var pb = k % n
        if (n % 2 == 1L)
            pb = (pb + k / (n / 2)) % n
        println(pb + 1)
    }
}