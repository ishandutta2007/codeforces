import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var (n, m) = readInts()
    var k = IntArray(n)
    var t = IntArray(n)
    var tot = 0
    var totOne = 0
    var totTwo = 0
    var numTwo = 0
    var dp = Array<BooleanArray>(n + 1) { BooleanArray(m + 1) }
    var par = Array<BooleanArray>(n + 1) { BooleanArray(m + 1) }
    var twoIndices = ArrayList<Int>()
    dp[0][0] = true
    for (i in 0 until n) {
        var (ki, ti) = readInts()
        k[i] = ki
        t[i] = ti
        tot += k[i]
        if (t[i] == 2) {
            for (j in 0..m) {
                if (dp[numTwo][j]) {
                    dp[numTwo + 1][j] = true
                    par[numTwo + 1][j] = false
                    if (j + k[i] <= m) {
                        dp[numTwo + 1][j + k[i]] = true
                        par[numTwo + 1][j + k[i]] = true
                    }
                }
            }
            totTwo += k[i]
            numTwo++
            twoIndices.add(i)
        } else {
            totOne += k[i]
        }
    }
    if (tot > m) {
        println(-1)
        return
    }
    for (j in 0..totTwo) {
        var fin = max(2 * j, 2 * (totTwo - j) + 1)
        if (dp[numTwo][j] && 2 * j - 1 <= m && 2 * (totTwo - j) <= m && m - fin + 1 >= totOne) {
            var x = j
            var odd = 1
            var even = 2
            var ret = IntArray(n)
            for (i in numTwo downTo 1) {
                if (par[i][x]) {
                    ret[twoIndices[i - 1]] = odd
                    odd += k[twoIndices[i - 1]] * 2
                    x -= k[twoIndices[i - 1]]
                } else {
                    ret[twoIndices[i - 1]] = even
                    even += k[twoIndices[i - 1]] * 2
                }
            }
            var nxt = fin
            for (i in 0 until n) {
                if (t[i] == 1) {
                    ret[i] = nxt
                    nxt += k[i]
                }
            }
            println(ret.joinToString(" "))
            return
        }
    }
    println(-1)
}