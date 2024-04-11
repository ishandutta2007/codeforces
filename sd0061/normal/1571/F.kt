import kotlin.math.max

fun main(args: Array<String>) {
    val (n, m) = readLine()!!.split(' ').map {it.toInt()}
    val a = IntArray(n)
    val t = IntArray(n)
    val res = IntArray(n)
    var sumOne = 0
    var sumTwo = 0
    val f = Array(n + 1) { BooleanArray(m + 1) }
    f[0][0] = true
    for (i in 0 until n) {
        val (x, y) = readLine()!!.split(' ').map {it.toInt()}
        a[i] = x
        t[i] = y
        for (j in 0..m) {
            f[i + 1][j] = f[i][j]
        }
        if (t[i] == 2) {
            sumTwo += a[i]
            for (j in x..m) {
                f[i + 1][j] = f[i + 1][j] or f[i][j - x]
            }
        } else {
            sumOne += a[i]
        }
    }
    var found = -1
    for (i in 0..m) {
        if (f[n][i]) {
            var j = sumTwo - i
            var slot = if (i == j) i + j else max(i, j) * 2 - 1
            if (slot + sumOne <= m) {
                found = i
                break
            }
        }
    }
    if (found == -1) {
        println(-1)
    } else {
        var cur = found
        var odd = 1
        var even = 2
        var back = m
        var i = n - 1
        while (i >= 0) {
            if (t[i] == 1) {
                back -= a[i]
                res[i] = back + 1
            } else if (f[i][cur]) {
                res[i] = odd
                odd += a[i] * 2
            } else {
                res[i] = even
                even += a[i] * 2
                cur -= a[i]
            }
            i --
        }
        println(res.joinToString(separator= ' '.toString()))
    }
}