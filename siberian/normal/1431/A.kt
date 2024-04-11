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
    var a = readLongs()
    var ans : Long = 0.toLong()
    for (i in a) {
        var cnt = 0
        for (j in a) {
            if (j >= i) {
                cnt++
            }
        }
        if (ans < cnt.toLong() * i) {
            ans = cnt.toLong() * i
        }
    }
    println(ans)
}

fun main() {
    var t = readInt()
    for (i in 0 until t) {
        solve()
    }
}