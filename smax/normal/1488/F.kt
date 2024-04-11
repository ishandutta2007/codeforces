private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var n = readInt()
    var c = readInts()
    var q = readInt()
    var queries = Array<MutableList<Pair<Int, Int>>>(n) { mutableListOf() }
    for (i in 0 until q) {
        var (l, r) = readInts()
        l--
        r--
        queries[r].add(Pair(l, i))
    }

    var stk = mutableListOf<Int>()
    var st = SegmentTree(n)
    var ret = LongArray(q)
    for (r in 0 until n) {
        while (stk.isNotEmpty() && c[stk.last()] <= c[r]) {
            st.update(stk.removeLast(), 0)
        }
        st.update(r, (r - (if (stk.isEmpty()) -1 else stk.last())).toLong() * c[r])
        stk.add(r)
        for ((l, i) in queries[r]) {
            var lo = 0
            var hi = stk.size
            while (lo < hi) {
                var mid = (lo + hi) / 2
                if (stk[mid] >= l)
                    hi = mid
                else
                    lo = mid + 1
            }
            ret[i] = st.query(stk[lo] + 1, r) + (stk[lo] - l + 1).toLong() * c[stk[lo]]
        }
    }
    println(ret.joinToString(" "))
}

class SegmentTree(_n: Int) {
    var n: Int
    var st: LongArray

    init {
        n = _n
        st = LongArray(4 * n) { 0 }
    }

    fun query(i: Int, j: Int, p: Int = 1, l: Int = 0, r: Int = n - 1): Long {
        if (i <= l && r <= j) {
            return st[p]
        }
        if (i > j || i > r || j < l) {
            return 0
        }
        var m = (l + r) / 2
        return query(i, j, 2 * p, l, m) + query(i, j, 2 * p + 1, m + 1, r)
    }

    fun update(i: Int, v: Long, p: Int = 1, l: Int = 0, r: Int = n - 1) {
        if (l == r) {
            st[p] = v
            return
        }
        var m = (l + r) / 2
        if (i <= m) {
            update(i, v, 2 * p, l, m)
        } else {
            update(i, v, 2 * p + 1, m + 1, r)
        }
        st[p] = st[2 * p] + st[2 * p + 1]
    }
}