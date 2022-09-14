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
        println((0 until n).map { 'a' + it % k}.joinToString(""))
    }
}