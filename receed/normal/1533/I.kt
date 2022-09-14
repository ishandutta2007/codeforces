import kotlin.math.min

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

@kotlin.ExperimentalStdlibApi
fun main() {
    val (n1, n2, m) = readInts()
    val a = readInts()
    val g = MutableList(n1 + n2) { mutableListOf<Int>() }
    repeat(m) {
        var (v1, v2) = readInts()
        v1--
        v2 += n1 - 1
        g[v1].add(v2)
        g[v2].add(v1)
    }
    val used = MutableList(n1 + n2) { false }
    val inf = 1e9.toInt()
    val dfs = DeepRecursiveFunction<Pair<Int, Int>, Int> { (v, p) ->
        used[v] = true
        var ans = 1e9.toInt()
        min(
            g[v].map {
                when {
                    it == p -> inf
                    used[it] -> 0
                    else -> callRecursive(Pair(it, v))
                }
            }.minOrNull() ?: inf,
            if (v < n1) a[v] else inf
        )
    }
    println((0 until n1).asSequence().filterNot { used[it] }.map { dfs(Pair(it, -1)) }.sum())
}