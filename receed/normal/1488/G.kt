import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val n = readInt()
    val a = MutableList(n + 1) { n / max(it, 1) - 1 }
    val del = MutableList(n + 1) { false }
    val li = List(n * 2 + 1) { mutableListOf<Int>()}
    for (i in 1..n)
        li[n + a[i]].add(i)
    var res = 0
    val result = MutableList(n) { 0 }
    var pos = li.size - 1
    for (i in n - 2 downTo 0) {
        var v = -1
        while (true) {
            while (!li[pos].isEmpty() && (del[li[pos].last()] || a[li[pos].last()] != pos - n)) {
                li[pos].removeLast()
            }
            if (li[pos].isEmpty())
                pos -= 1
            else {
                v = li[pos].last()
                break
            }
        }
        res += a[v]
        del[v] = true
        for (j in v * 2..n step v) {
            if (!del[j]) {
                a[j] -= 1
                li[a[j] + n].add(j)
            }
        }
        result[i] = res
    }
    println(result.joinToString(" "))
}