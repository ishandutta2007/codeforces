import kotlin.math.max

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

class Attack(val a: Int, val b: Int, val i: Int) : Comparable<Attack> {
    override fun compareTo(other: Attack): Int {
        if (b + i == other.b + other.i)
            return other.i.compareTo(i)
        return (b + i).compareTo(other.b + other.i)
    }
}

class SegmentTree(val n: Int) {
    val st = LongArray(4 * n) { (-1e18).toLong() }

    fun query(i: Int, j: Int, p: Int = 1, l: Int = 0, r: Int = n - 1): Long {
        if (i > r || j < l)
            return 0
        if (i <= l && r <= j)
            return st[p]
        var m = (l + r) / 2
        return max(query(i, j, 2 * p, l, m), query(i, j, 2 * p + 1, m + 1, r))
    }

    fun update(i: Int, v: Long, p: Int = 1, l: Int = 0, r: Int = n - 1) {
        if (l == r) {
            st[p] = max(st[p], v)
            return
        }
        var m = (l + r) / 2
        if (i <= m)
            update(i, v, 2 * p, l, m)
        else
            update(i, v, 2 * p + 1, m + 1, r)
        st[p] = max(st[2 * p], st[2 * p + 1])
    }
}

fun main() {
    var (n, m) = readInts()
    var pts = ArrayList<Attack>()
    for (i in 0 until n) {
        var k = readInt()
        var a = readInts()
        var b = readInts()
        for (j in 0 until k) {
            pts.add(Attack(a[j], b[j], i))
        }
    }
    var st = SegmentTree(m + 1)
    st.update(m, 0)
    pts.sort()
    pts.forEach {
        if (it.b + it.i >= m) {
            st.update(it.b, st.query(it.b, m) + it.a)
        }
    }
    println(st.query(0, m))
}