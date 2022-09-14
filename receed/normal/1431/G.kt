fun main() {
    val (n, k) = readLine()!!.split(' ').map { it.toInt() }
    val a = readLine()!!.split(' ').map {it.toInt() }.sorted()
    val ps = a.runningFold(0) {x, y -> x + y}
    val dp = MutableList(k+1) { MutableList(n + 1) {0} }
    for (i in 0..k)
        for (j in 0..n-1) {
            if (dp[i][j + 1] < dp[i][j])
                dp[i][j + 1] = dp[i][j]
            for (d in 1..((n - j) / 2)) {
                if (i + d > k)
                    break
                val nd = dp[i][j] + ps[j + 2 * d] - ps[j + d] - (ps[j + d] - ps[j])
                if (dp[i + d][j + d * 2] < nd)
                    dp[i + d][j + d * 2] = nd
            }
        }
    println(dp[k][n])
}