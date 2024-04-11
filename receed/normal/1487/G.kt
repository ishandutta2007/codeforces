import kotlin.math.min

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val MOD = 998244353
    val n = readInt()
    val a = readInts()
    var result = 26L * 26;
    repeat(n - 2) { result = result * 25 % MOD }
    val m = (n + 2) / 2
    val dp = Array(2) { Array(m + 2) { Array(m + 2) { Array(3) { Array(3) { 0L } } } } }
    dp[0][0][0][0][0] = 1
    for (i in 0 until n) {
        val ci = i % 2
        val ni = 1 - ci
        for (c1 in 0..(i + 2) / 2)
            for (c2 in 0..min(i - c1, (i + 2) / 2))
                for (d1 in 0..2)
                    for (d2 in 0..2)
                        dp[ni][c1][c2][d1][d2] = 0
        for (c1 in 0..(i + 2) / 2)
            for (c2 in 0..min(i - c1, (i + 2) / 2))
                for (d1 in 0..2)
                    for (d2 in 0..2)
                        for (d3 in 0..2)
                            if (d1 != d3 || d1 == 0) {
                                val n1 = c1 + d3 % 2
                                val n2 = c2 + if (d3 == 2) 1 else 0
                                val mul = if (d3 > 0) 1 else if (d1 > 0 || i <= 1) 24 else 23
                                dp[ni][n1][n2][d2][d3] = (dp[ni][n1][n2][d2][d3] + dp[ci][c1][c2][d1][d2] * mul) % MOD
                            }
    }
    val d2 = dp[n % 2].map { it.map { it.sumOf { it.sum() % MOD } % MOD } }
    val d1 = d2.map { it.sum() % MOD }
    for (i in a)
        for (j in i + 1..m)
            result = (result + MOD - d1[j]) % MOD
    for (i in 0..25)
        for (j in 0 until i)
            for (c1 in a[i] + 1..m)
                for (c2 in a[j] + 1..m)
                    result = (result + d2[c1][c2]) % MOD
    println(result)
}