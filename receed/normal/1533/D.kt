private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val (n, m) = readInts()
    val a = List(n) {readLn()}.toSet()
    val q = readInt()
    repeat(q) {
        val s = readLn()
        println(s.indices.map {
            s.substring(0, it) + s.substring(it + 1)
        }.toSet().count { a.contains(it) })
    }
}