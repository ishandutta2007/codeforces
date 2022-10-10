import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    repeat(readInt()) {
        var n = readInt()
        var a = readInts()
        var st = SegmentTree(n)
        var pos = IntArray(n + 1) { -1 }
        for (i in 0 until n) {
            if (pos[a[i]] == -1) {
                pos[a[i]] = i
            } else {
                st.update(pos[a[i]], st.query(pos[a[i]] + 1, i - 1) + 2)
            }
        }
        println(st.query(0, n - 1))
    }
}

class SegmentTree(_n: Int) {
    var n: Int
    var st: IntArray

    init {
        n = _n
        st = IntArray(4 * n) { 1 }
    }

    fun query(i: Int, j: Int, p: Int = 1, l: Int = 0, r: Int = n - 1): Int {
        if (i <= l && r <= j) {
            return st[p]
        }
        if (i > j || i > r || j < l) {
            return 0
        }
        var m = (l + r) / 2
        return max(query(i, j, 2 * p, l, m), query(i, j, 2 * p + 1, m + 1, r))
    }

    fun update(i: Int, v: Int, p: Int = 1, l: Int = 0, r: Int = n - 1) {
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
        st[p] = max(st[2 * p], st[2 * p + 1])
    }
}