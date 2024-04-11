import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.util.*

/*
2
1 2
 */
const val mod: Long = 1000000007

fun main(args: Array<String>) {
    val fs = FastScanner()
    val n = fs.nextInt()
    val nodes = arrayOfNulls<Node>(n)
    for (i in 0 until n) nodes[i] = Node(i)
    for (i in 1 until n) {
        val a = fs.nextInt() - 1
        val b = fs.nextInt() - 1
        nodes[a]!!.adj.add(nodes[b])
        nodes[b]!!.adj.add(nodes[a])
    }
    dp = Array(n + 1) { LongArray(n + 1) }
    for (i in dp.indices) Arrays.fill(dp[i], -1)
    var expectedInversions: Long = 0
    for (i in 0 until n) {
        for (j in i + 1 until n) {
            val end1 = nodes[i]
            val end2 = nodes[j]
            bfs(nodes, end2)
            for (nn in nodes) nn!!.dist2 = nn.dist1
            bfs(nodes, end1)
            val diam = end1!!.dist2
            for (k in 0 until n) {
                val nn = nodes[k]
                val kDist = nn!!.dist1 + nn.dist2
                val toSub = (kDist - diam) / 2
                nn.dist1 -= toSub
                nn.dist2 -= toSub
                val ways = countWays(nn.dist2, nn.dist1)
                //we want the chance we hit j before i
                expectedInversions = add(expectedInversions, ways)
            }
        }
    }
    //need to divide by n
//		long nC2=n*(n+1)/2;
    println(mul(add(expectedInversions, 0), inv(n.toLong())))
}

var HALF = inv(2)
lateinit var dp: Array<LongArray>
fun countWays(nGood: Int, nBad: Int): Long {
    if (nGood == 0) return 1
    if (nBad == 0) return 0
    return if (dp[nGood][nBad] != -1L) dp[nGood][nBad] else mul(HALF, add(countWays(nGood - 1, nBad), countWays(nGood, nBad - 1))).also { dp[nGood][nBad] = it }
}

fun bfs(nodes: Array<Node?>, from: Node?) {
    for (n in nodes) n!!.dist1 = -1
    from!!.dist1 = 0
    val bfs = ArrayDeque<Node?>()
    bfs.add(from)
    while (!bfs.isEmpty()) {
        val next = bfs.removeFirst()
        for (nn in next!!.adj) {
            if (nn!!.dist1 == -1) {
                nn.dist1 = next!!.dist1 + 1
                bfs.addLast(nn)
            }
        }
    }
}

fun sort(a: IntArray) {
    val l = ArrayList<Int>()
    for (i in a) l.add(i)
    Collections.sort(l)
    for (i in a.indices) a[i] = l[i]
}

fun add(a: Long, b: Long): Long {
    return ((a + b) % mod + mod) % mod
}

fun mul(a: Long, b: Long): Long {
    return a * b % mod
}

fun pow(base: Long, exp: Long): Long {
    if (exp == 0L) return 1
    val half = pow(base, exp / 2)
    return if (exp % 2 == 0L) mul(half, half) else mul(half, mul(half, base))
}

fun inv(x: Long): Long {
    return pow(x, mod - 2)
}

var facts = LongArray(100000)
var factsInv = LongArray(100000)
fun precomp() {
    facts[0] = 1
    for (i in 1 until facts.size) facts[i] = mul(facts[i - 1], i.toLong())
    for (i in factsInv.indices) factsInv[i] = inv(facts[i])
}

fun nCk(n: Int, k: Int): Long {
    return mul(facts[n], mul(factsInv[k], factsInv[n - k]))
}

class Node(var id: Int) {
    var adj = ArrayList<Node?>()
    var dist1 = 0
    var dist2 = 0
}

internal class FastScanner {
    var br = BufferedReader(InputStreamReader(System.`in`))
    var st = StringTokenizer("")
    operator fun next(): String {
        while (!st.hasMoreTokens()) try {
            st = StringTokenizer(br.readLine())
        } catch (e: IOException) {
            e.printStackTrace()
        }
        return st.nextToken()
    }

    fun nextInt(): Int {
        return next().toInt()
    }

    fun readArray(n: Int): IntArray {
        val a = IntArray(n)
        for (i in 0 until n) a[i] = nextInt()
        return a
    }

    fun nextLong(): Long {
        return next().toLong()
    }
}