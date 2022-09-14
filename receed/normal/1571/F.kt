import kotlin.math.max

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val (n, m) = readInts()
    val ans = MutableList(n) { -1 }
    var s = 0
    val pr = Array(n + 1) { Array(m + 1) { false } }
    pr[0][0] = true
    val a = List(n) { readInts() }
    var es = 0
    for (i in 0 until n) {
        val (k, t) = a[i]
        for (j in 0..m)
            pr[i + 1][j] = pr[i][j]
        if (t == 1) {
            ans[i] = s
            s += k
        } else {
            es += k
            for (j in 0..m-k)
                if (pr[i][j]) {
                        pr[i + 1][j + k] = true
                }

        }
    }
    var s1 = -1
    for (i in 0..m)
        if (pr[n][i] && s + (i - 1) * 2 < m && s + 1 + (es - i - 1) * 2 < m) {
            s1 = i
            break
        }
    if (s1 == -1) {
        println(-1)
        return
    }
    var cs2 = s + 1
    for (i in n - 1 downTo 0) {
        if (pr[i][s1]) {
            if (ans[i] == -1) {
                ans[i] = cs2
                cs2 += 2 * a[i][0]
            }
        } else {
            ans[i] = s
            s += 2 * a[i][0]
            s1 -= a[i][0]
        }
    }
    println(ans.joinToString(" ") { (it + 1).toString() })
}