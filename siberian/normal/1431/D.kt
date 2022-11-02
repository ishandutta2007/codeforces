import java.lang.AssertionError
import java.util.*
import kotlin.math.*
import java.util.LinkedHashSet

val scan = java.util.Scanner(System.`in`)

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun solve() {
    var n = readInt()
    var x = readInts()
    var a : MutableList<Pair<Int, Int>> = MutableList(0, {Pair(0, 0)})
    for (i in 0 until n) {
        a.add(Pair(x[i], i + 1))
    }
    a.sortWith(compareBy({it.first}, {it.second}))
    var l = 0
    var r = n - 1
    var cnt = 0
    var ans : MutableList<Int> = MutableList(0, {0})
    for (i in 0 until n) {
        if (a[l].first == cnt) {
            ans.add(a[l].second)
            l++
            cnt = 0
        } else {
            ans.add(a[r].second)
            r--
        }
        cnt++
    }
    println(ans.joinToString(" "))
}

fun main() {
    var t = readInt()
    for (i in 0 until t) {
        solve()
    }
}