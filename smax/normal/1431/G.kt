import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map{it.toInt()}

const val INF = 1e9.toInt()

fun main() {
    var (n, k) = readInts()
    var a = readInts().sorted()

    var pref = IntArray(n + 1)
    for (i in 0 until n)
        pref[i+1] = pref[i] + a[i]

    fun query(l: Int, r: Int): Int {
        return pref[r] - pref[l-1]
    }

    var dp = Array(n + 1) {IntArray(n + 1) {-INF}}
    dp[0][0] = 0
    for (i in 0 until n)
        for (j in 0 .. k) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j])
            for (l in i + 2 .. n step 2)
                if (j + (l - i) / 2 <= k)
                    dp[l][j+(l-i)/2] = max(dp[l][j+(l-i)/2], dp[i][j] + query(i + (l - i) / 2 + 1, l) - query(i + 1, i + (l - i) / 2))
        }
    println(dp[n][k])
}