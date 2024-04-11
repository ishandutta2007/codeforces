import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}
fun solve() {
    var (x, k) = readLongs()
    var n = x.toInt()
    var s = readLn()
    //println("|$s|")
    var r = 0
    var ans = CharArray(n)
    for (i in 0 until n) {
        ans[i] = s[i]
    }
    for (l in 0 until n) {
        //for (i in ans) {
        //    print(i)
        //}
        //println()

        if (k == 0.toLong()) {
            break
        }
        while (r < n && ans[r] == '1') {
            ++r
        }
        if (r == n) {
            break
        }
        if (l == r) {
            ++r
            continue
        }
        if (r - l <= k) {
            ans[l] = '0'
            ans[r] = '1'
            k -= r - l;
            ++r
        } else {
            var pos = l
            while (r - pos > k) {
                ++pos
            }
            ans[pos] = '0'
            ans[r] = '1'
            break
        }
    }
    println(ans.joinToString(""))
}

fun main(args: Array<String>) {
    var t = readInt()
    for (i in 0 until t) {
        solve()
    }
}