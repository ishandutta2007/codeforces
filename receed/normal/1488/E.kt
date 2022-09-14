import kotlin.math.max

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val a = readInts()
        val s = sortedMapOf<Int, Int>()
        val pos = mutableMapOf<Int, Int>()
        var res = 1
//        val dp = Array(n) { Array(n) { 0 } }
//        for (i in n - 1 downTo 0)
//            for (j in i until n) {
//                if (i == j)
//                    dp[i][j] = 1
//                else if (a[i] == a[j])
//                    dp[i][j] = dp[i + 1][j - 1] + 2
//                else
//                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
//            }
        for (i in 0 until n) {
            if (a[i] !in pos) {
                pos[a[i]] = i
                s[i] = 1
                continue
            }
            val lp = pos[a[i]]!!
            var mx = 2
            val x = s.tailMap(lp + 1)
            if (!x.isEmpty())
                mx = x[x.firstKey()]!! + 2
            val fm = s.headMap(lp + 1)
            while (!fm.isEmpty() && fm[fm.lastKey()]!! <= mx) {
                fm.remove(fm.lastKey())
            }
            s[lp] = mx
            res = max(res, mx)
            s[i] = 1
        }
        println(res)
    }
}