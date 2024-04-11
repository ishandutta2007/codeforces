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
    var s = readLn()
    var ans = 0
    var len = 0
    for (i in s) {
        if (i == 'w') {
            ans += len / 2
            ans++
            len = 0
        } else {
            len++
        }
    }
    ans += len / 2
    println(ans)
}

fun main() {
    var t = readInt()
    for (i in 0 until t) {
        solve()
    }
}