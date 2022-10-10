import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var n = readInt()
    var a = readInts().sorted()
    var b = readInts().sorted()

    var pref = IntArray(n)
    for (i in 0 until n) {
        pref[i] = b[i] - a[i]
        if (i > 0) {
            pref[i] = max(pref[i], pref[i - 1])
        }
    }
    var suff = IntArray(n + 1)
    for (i in n downTo 1) {
        suff[i] = b[i] - a[i - 1]
        if (i + 1 <= n) {
            suff[i] = max(suff[i], suff[i + 1])
        }
    }

    var m = readInt()
    var c = readInts()
    var ret = mutableListOf<Int>()
    for (i in 0 until m) {
        var l = 0
        var r = n
        while (l < r) {
            var x = (l + r) / 2
            if (a[x] >= c[i]) {
                r = x
            } else {
                l = x + 1
            }
        }
        ret.add(maxOf(b[l] - c[i], if (l > 0) pref[l - 1] else Int.MIN_VALUE, if (l + 1 <= n) suff[l + 1] else Int.MIN_VALUE))
    }
    println(ret.joinToString(" "))
}