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
    //var s = TreeSet<Pair<Int, Int>>(compareBy({it.first}, {it.second}))
    //s.add(Pair(1, 1))
    //s.add(Pair(2, 1))
    var (n, k, x) = readInts()

    if (k == n) {
        println(0)
        return
    }

    var a = readInts()

    if (k + x >= n) {
        var b = a.toMutableList()
        b.sort()
        var ans : Long = 0
        n -= k
        for (i in 0 until n) {
            ans += b[i]
        }
        println(ans)
        return
    }

    var b = a.toMutableList()
    b.sort()

    var l : Long = -1
    var r : Long = 0
    //for (i in a) {
    //    r += i.toLong()
    //}
    for (i in 0 until x) {
        r += b[n - 1 - i]
    }

    var setik = TreeSet<Pair<Int, Int>>(compareBy({it.first}, {it.second}))

    fun check(sum : Long) : Boolean {
        var l = 0
        var cnt = 0
        while (l < n) {
            setik.clear()
            var sumNow : Long = 0
            var r = l
            while (r - l < x && r < n) {
                sumNow += a[r]
                setik.add(Pair(a[r], r))
                ++r
            }
            while (sumNow > sum) {
                var x = setik.last()
                setik.remove(x)
                sumNow -= x.first
                cnt++
                if (cnt > k) {
                    return false
                }
                if (r < n) {
                    sumNow += a[r]
                    setik.add(Pair(a[r], r))
                    ++r
                }
            }
            l = r
        }
        return cnt <= k
    }

    while (l < r - 1) {
        var mid = (r + l) / 2
        if (check(mid)) {
            r = mid
        } else {
            l = mid
        }
    }
    println(r)
}

fun main() {

    //var t = readInt()
    var t = 1
    for (i in 0 until t) {
        solve()
    }
}