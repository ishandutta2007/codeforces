import java.lang.AssertionError
import java.util.*
import kotlin.math.*

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
    var n : Int = readInt()
    var g = MutableList<MutableList<Int>> (n, { MutableList(0, {0})})
    for (i in 0 until n - 1) {
        var (u, v) = readInts()
        --u
        --v
        g[u].add(v)
        g[v].add(u)
    }
    fun getCentroids() : MutableList<Int> {
        var sz = MutableList<Int> (n, {0})
        var mx = MutableList<Int> (n, {0})
        fun dfsSz(v : Int, p : Int)  {
            sz[v] = 1
            mx[v] = 0
            for (i in g[v]) {
                if (i == p) continue
                dfsSz(i, v)
                mx[v] = max(mx[v], sz[i])
                sz[v] += sz[i]
            }
            mx[v] = max(mx[v], n - sz[v])
        }

        dfsSz(0, 0)
        var ans = MutableList<Int>(0, {0})

        for (i in 0 until n) {
            // println("ans = ${ans.joinToString()}")
            if (ans.size == 0) {
                ans.add(i)
            } else if (mx[i] < mx[ans[ans.size - 1]]) {
                ans = MutableList<Int>(1, { i })
            } else if (mx[i] > mx[ans[ans.size - 1]]) {
                continue
            } else {
                ans.add(i)
            }
        }
        return ans
    }

    var have = getCentroids()

    //println("have = ${have.joinToString()}")

    myAssert(have.size in 1..2)
    if (have.size == 1) {
        for (i in 0 until n) {
            myAssert(g.isNotEmpty())
            println("${g[i][0] + 1} ${i + 1}")
            println("${g[i][0] + 1} ${i + 1}")
            return
        }
    }

    fun dfsV(v : Int, p : Int, ban : Int) : Int {
        if (g[v].size == 1) {
            return v
        }
        for (i in g[v]) {
            if (i == p || i == ban) {
                continue
            }
            var ans = dfsV(i, v, ban)
            if (ans != -1) {
                return ans
            }
        }
        return -1
    }

    fun findV(v : Int, ban : Int) : Int {
        var ans = dfsV(v, -1, ban)
        myAssert(ans != - 1)
        return ans
    }

    var v = findV(have[1], have[0])
    // println("v = $v")
    myAssert(g[v].size == 1)
    println("${g[v][0] + 1} ${v + 1}")
    println("${have[0] + 1} ${v + 1}")
}


fun main() {
    var t : Int = readInt()
    for (te in 0 until t) {
        solve()
    }
}