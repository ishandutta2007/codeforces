import kotlin.math.max

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }


private class Tree {
    val n = 1 shl 20
    val inf = 1e18.toLong()
    val t = MutableList<Long>(n * 2) { -inf }

    fun mx(cl: Int, cr: Int, v: Int, l: Int, r: Int):Long {
        if (cr <= l || r <= cl)
            return -inf
        if (cl <= l && r <= cr)
            return t[v]
        return max(mx(cl, cr, v * 2, l, (l + r) / 2), mx(cl, cr, v * 2 + 1, (l + r) / 2, r))
    }

    fun add(v: Int, d: Long) {
        var cur = n + v
        while (cur > 0) {
            t[cur] = max(t[cur], d)
            cur = cur / 2
        }
    }
}

fun main() {
    val (n, m) = readInts()
    val st = Tree()
    st.add(m, 0)
    println(max((1..n).flatMap { i ->
        readInt()
        readInts().zip(readInts()).map { (a, b) ->
            listOf(-b, i + b, a)
        }
    }.sortedWith(compareBy<List<Int>> {it[0] }.thenBy {it[1]})
        .map { (_, y, w) ->
        val cur = st.mx(0, y, 1, 0, st.n) + w
        st.add(y, cur)
        cur
    }.maxOrNull()!!, 0L))
}