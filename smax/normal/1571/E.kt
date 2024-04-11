import kotlin.math.min

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun isValid(mask: Int): Boolean {
    var bal = 0
    for (i in 0 until 4) {
        if (((mask shr i) and 1) == 0) {
            bal++
        } else {
            bal--
            if (bal < 0)
                return false
        }
    }
    return bal == 0
}

var valid = BooleanArray(16) { isValid(it) }

fun main() {
    var t = readInt()
    repeat(t) {
        var n = readInt()
        var s = readLn()
        var t = readLn()
        var dp = Array<IntArray>(n - 2) { IntArray(8) { 1e9.toInt() } }
        for (mask in 0 until 8) {
            dp[0][mask] = 0
            for (i in 0 until 3)
                if ((s[i] == ')') != (((mask shr i) and 1) != 0))
                    dp[0][mask]++
        }
        for (i in 0 until n - 3) {
            for (mask in 0 until 8) {
                for (nxt in 0..1) {
                    if (t[i] == '0' || valid[mask + (nxt shl 3)]) {
                        var cost = if ((s[i+3] == '(') == (nxt == 0)) 0 else 1
                        var nmask = (mask + (nxt shl 3)) shr 1
                        dp[i+1][nmask] = min(dp[i+1][nmask], dp[i][mask] + cost)
                    }
                }
            }
        }
        var ret = 1e9.toInt()
        for (mask in 0 until 8)
            ret = min(ret, dp[n-3][mask])
        println(if (ret == 1e9.toInt()) -1 else ret)
    }
}