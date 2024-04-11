import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (n, k) = readInts()

    val b = IntArray(n)
    val c = IntArray(n)

    var cost = 0L
    var have = 0L
    var atMost = 0L

    for (i in 0 until n) {
        val (aa, bb, cc) = readInts()
        have += aa
        atMost += bb

        cost += cc * 1L * aa

        b[i] = bb - aa
        c[i] = cc
    }

    if (have > k || atMost < k) {
        println("-1")
        return
    }

    val indices = b.indices.toList()

    val sindices = indices.sortedBy { it -> c[it] }

    for (i in sindices) {
        val take = min(k - have, 1L * b[i])
        cost += take * c[i]
        have += take
    }

    println(cost)
}