import kotlin.math.max

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var (n, m) = readInts()
    var f = IntArray(m)
    var l = IntArray(m)
    var cntF = IntArray(n + 1)
    var cntL = IntArray(n + 1)
    var mp = HashMap<Pair<Int, Int>, Int>()
    for (i in 0 until m) {
        var (fi, li) = readInts()
        f[i] = fi
        l[i] = li
        cntF[fi]++
        cntL[li]++
        var p = Pair(fi, li)
        mp[p] = mp.getOrDefault(p, 0) + 1
    }
    var ret = 1
    for (first in 1..n) {
        for (last in 1..n) {
            if (first != last) {
                if (f[0] == first && l[0] == last) {
                    ret = max(ret, 1)
                } else if (f[0] == first || l[0] == last) {
                    ret = max(ret, mp.getOrDefault(Pair(first, last), 0) + 1)
                } else {
                    var both = mp.getOrDefault(Pair(first, last), 0)
                    ret = max(ret, cntF[first] + cntL[last] - both + 1)
                }
            }
        }
    }
    println(ret)
}