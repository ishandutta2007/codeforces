import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var t = readInt()
    repeat(t) {
        var n = readInt()
        var mn = 0
        var mx = 1e9.toInt()
        repeat(n) {
            var (s, t, r) = readStrings()
            var k = 0
            while (k < min(s.length, t.length) && s[s.length-k-1] == t[t.length-k-1])
                k++
            if (r == "1")
                mx = min(mx, k)
            else
                mn = max(mn, k + 1)
        }
        println(max(mx - mn + 1, 0))
        for (k in mn..mx)
            print("$k ")
        println()
    }
}