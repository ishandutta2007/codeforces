private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val n = readInt()
    val s = readLn()
    var cnt = 0
    var ans = 0
    for (c in s) {
        if (c != 'x')
            cnt = 0
        else if (++cnt >= 3)
            ans++
    }
    println(ans)
}