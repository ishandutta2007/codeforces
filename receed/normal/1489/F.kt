private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val (n, m, k) = readLongs()
    val a = readLongs().reversed()
    var sum = 0L
    var cnt = m
    println(a.takeWhile {
        if (it > sum) {
            sum = k
            cnt--
        }
        sum -= it
        cnt >= 0 && sum >= 0
    }.size)
}