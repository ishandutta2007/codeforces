import java.util.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map{it.toInt()}

fun main() {
    var (n, k, x) = readInts()
    var a = readInts()
    var l = 0L
    var r = 1e11.toLong()
    while (l < r) {
        var m = (l + r) / 2
        var sum = 0L
        var rem = 0
        var pq = PriorityQueue<Int>(compareBy<Int>{-it})
        for (i in 0 until n) {
            sum += a[i]
            pq.add(a[i])
            if (sum > m) {
                sum -= pq.poll()
                rem++
            }
            if (pq.size == x) {
                sum = 0
                pq.clear()
            }
        }
        if (rem > k)
            l = m + 1
        else
            r = m
    }
    println(l)
}