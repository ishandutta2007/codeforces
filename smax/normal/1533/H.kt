private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var (n, m) = readInts()
    var s = Array<String>(n) { readLn() }

    var a = Array<BooleanArray>(n) { BooleanArray(m) }
    var tot = LongArray(1 shl 5)
    for (mask in 1 until (1 shl 5)) {
        for (i in 0 until n) {
            for (j in 0 until m) {
                a[i][j] = (mask and (1 shl (s[i][j] - 'A'))) > 0
            }
        }
        var h = IntArray(m)
        for (i in 0 until n) {
            for (j in 0 until m) {
                if (a[i][j]) {
                    h[j]++
                } else {
                    h[j] = 0
                }
            }
            var stk = mutableListOf<Int>()
            var curTot = 0L
            for (j in 0 until m) {
                var prev = j
                while (stk.isNotEmpty() && h[stk.last()] >= h[j]) {
                    var k = stk.removeLast()
                    var backIdx = if (stk.isEmpty()) -1 else stk.last()
                    curTot -= (prev - backIdx - 1) * h[k]
                    prev = backIdx + 1
                }
                var backIdx = if (stk.isEmpty()) -1 else stk.last()
                curTot += (j - backIdx) * h[j]
                stk.add(j)
                tot[mask] += curTot
            }
        }
    }

    var dp = LongArray(1 shl 5)
    var ret = LongArray(5)
    for (mask in 1 until (1 shl 5)) {
        var cnt = 0
        for (i in 0 until 5) {
            if ((mask and (1 shl i)) != 0) {
                cnt++
            }
        }
        dp[mask] = tot[mask]
        for (mask2 in 1 until mask) {
            if ((mask and mask2) == mask2) {
                dp[mask] -= dp[mask2]
            }
        }
        ret[cnt - 1] += dp[mask]
    }
    println(ret.joinToString(" "))
}