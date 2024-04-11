private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

val N = 1 shl 18
val mod = Array(N * 2) {0L}
val tr = Array(N * 2) {0L}

fun push(v: Int, l: Int, r: Int) {
    if (mod[v] == 0L)
        return
    if (v < N) {
        mod[v * 2] = mod[v]
        mod[v * 2 + 1] = mod[v]
    }
    tr[v] = (r - l) * mod[v]
    mod[v] = 0
}

fun rel(v: Int) {
    tr[v] = tr[v * 2] + tr[v * 2 + 1]
}

fun add(cl: Int, cr: Int, d: Long, v: Int = 1, l: Int = 0, r: Int = N) {
    if (cr <= l || r <= cl) {
        push(v, l, r)
        return
    }
    if (cl <= l && r <= cr) {
        mod[v] = d
        push(v, l, r)
        return
    }
    push(v, l, r)
    add(cl, cr, d, v * 2, l, (l + r) / 2)
    add(cl, cr, d, v * 2 + 1, (l + r) / 2, r)
    rel(v)
}

fun gets(cl: Int, cr: Int, v: Int = 1, l: Int = 0, r: Int = N): Long {
    push(v, l, r)
    if (cr <= l || r <= cl)
        return 0L
    if (cl <= l && r <= cr)
        return tr[v]
    return gets(cl, cr, v * 2, l, (l + r) / 2) + gets(cl, cr, v * 2 + 1, (l + r) / 2, r)
}

fun main() {
    val n = readInt()
    val c = readLongs()
    val q = readInt()
    val ql = List(q) { readInts() }.withIndex().sortedBy { it.value[1] }
    val st = mutableListOf<Int>(-1)
    val result = MutableList(q) {0L}
    var pos = 0
    for (i in 0 until n) {
        while (st.size > 1 && c[st.last()] < c[i])
            st.removeLast()
        add(st.last() + 1, i + 1, c[i])
        while (pos < ql.size && ql[pos].value[1] == i + 1) {
            result[ql[pos].index] = gets(ql[pos].value[0] - 1, ql[pos].value[1])
            ++pos
        }
        st.add(i)
    }
    println(result.joinToString(" "))
}