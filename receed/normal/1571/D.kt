import kotlin.math.max

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val (n, m) = readInts()
    val a = List(m) { readInts() }
    val c1 = a.groupingBy { it[0] }.eachCount()
    val c2 = a.groupingBy { it[1] }.eachCount()
    val c3 = a.groupingBy { it }.eachCount()
    var ans = 0
    for (i in 1..n) {
        for (j in 1..n) {
            if (i == j || i == a[0][0] || j == a[0][1])
                continue
            ans = max(ans, (-(c3[listOf(i, j)] ?: 0) + (c1[i] ?: 0) + (c2[j] ?: 0)))
        }
    }
    println(ans + 1)
}