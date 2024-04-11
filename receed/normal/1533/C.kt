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
        val a = readLn().map { it == '1' }.toMutableList()
        var pos = 0
        var ans = 0
        while (a.any { it }) {
            ans++
            a.removeAt(pos)
            if (a.isNotEmpty())
                pos = (pos + k - 1) % a.size
        }
        println(ans)
    }
}