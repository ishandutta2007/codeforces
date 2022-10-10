private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var s = readLn()
    var n = s.length

    var pref0 = IntArray(n)
    var pref1 = IntArray(n)
    for (i in 0 until n) {
        pref0[i] = if (s[i] == '0') 1 else 0
        pref1[i] = if (s[i] == '1') 1 else 0
        if (i > 0) {
            pref0[i] += pref0[i - 1]
            pref1[i] += pref1[i - 1]
        }
    }

    fun query0(l: Int, r: Int): Int {
        return pref0[r] - if (l > 0) pref0[l - 1] else 0
    }

    fun query1(l: Int, r: Int): Int {
        return pref1[r] - if (l > 0) pref1[l - 1] else 0
    }

    var ret = mutableListOf<Int>()
    for (k in 1..n) {
        var i = 0
        var cur = 0
        while (i < n) {
            var l = i
            var r = n
            while (l < r) {
                var m = (l + r) / 2
                if (query0(i, m) <= k || query1(i, m) <= k) {
                    l = m + 1
                } else {
                    r = m
                }
            }
            cur++
            i = l
        }
        ret.add(cur)
    }
    println(ret.joinToString(" "))
}