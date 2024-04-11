private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun getParent(parents: MutableList<Int>, v: Int): Int {
    if (parents[v] != v)
        parents[v] = getParent(parents, parents[v])
    return parents[v]
}

fun main() {
    val (n, m) = readInts()
    val a = readLongs()
    val mn = a.withIndex().minByOrNull { it.value }!!
    val e = (List(m) { val (u, v, w) = readLongs(); listOf(u - 1, v - 1, w) } + a.withIndex().map { listOf(it.index.toLong(), mn.index.toLong(), it.value + mn.value) }).sortedBy { it[2] }
    val parents = MutableList(n) { it }
    var ans = 0L
    for ((u, v, w) in e) {
        val (pu, pv) = listOf(u, v).map {getParent(parents, it.toInt())}
        if (pu != pv) {
            ans += w
            parents[pu] = pv
        }
    }
    println(ans)
}