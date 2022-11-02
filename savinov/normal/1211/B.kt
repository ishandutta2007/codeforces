private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val n = readInt()

    val a = readInts()

    val mx = a.max()!!

    val lastPos = a.lastIndexOf(mx)

    println((mx - 1L) * n + lastPos + 1)
}