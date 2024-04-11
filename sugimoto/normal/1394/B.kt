import java.io.BufferedInputStream

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val m = jin.nextInt()
    val k = jin.nextInt()
    val adj = Array(n + 1) { mutableListOf<Edge>() }
    val rev = Array(n + 1) { mutableListOf<Edge>() }
    for (j in 1..m) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        val w = jin.nextInt()
        val edge = Edge(a, b, w)
        adj[a].add(edge)
        rev[b].add(edge)
    }
    for (a in 1..n) {
        adj[a].sortBy { it.weight }
        for (j in 1..adj[a].size) {
            adj[a][j - 1].ix = j
        }
    }
    val disallowed = Array(k + 1) { Array(k + 1) { mutableSetOf<Pair<Int, Int>>() } }
    for (a in 1..n) {
        val once = mutableSetOf<Pair<Int, Int>>()
        for (edge in rev[a]) {
            val p = Pair(adj[edge.from].size, edge.ix)
            if (p in once) {
                disallowed[p.first][p.second].add(Pair(0, 0))
            } else {
                once.add(p)
            }
        }
        for (x in once) {
            for (y in once) {
                if (x != y) {
                    disallowed[x.first][x.second].add(y)
                }
            }
        }
    }
    val curr = IntArray(k + 1)
    var answer = 0
    fun recur(j: Int) {
        if (j > k) {
            answer++
        } else {
            for (j2 in 1..j) {
                var works = true
                for (j3 in 0 until j) {
                    if (Pair(j3, curr[j3]) in disallowed[j][j2]) {
                        works = false
                        break
                    }
                }
                if (works) {
                    curr[j] = j2
                    recur(j + 1)
                }
            }
            curr[j] = 0
        }
    }
    recur(1)
    println(answer)
}

class Edge(val from: Int, val to: Int, val weight: Int) {
    var ix = 0
    override fun toString(): String {
        return "Edge(from=$from, to=$to, weight=$weight, ix=$ix)"
    }
}

class FastScanner {
    private val BS = 1 shl 16
    private val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC
    private var `in`: BufferedInputStream? = null

    constructor() {
        `in` = BufferedInputStream(System.`in`, BS)
    }

    private val char: Char
        private get() {
            while (bId == size) {
                size = try {
                    `in`!!.read(buf)
                } catch (e: Exception) {
                    return NC
                }
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toChar()
        }

    fun nextInt(): Int {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0
        while (c >= '0' && c <= '9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
}