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

fun main(args: Array<String>) {
    var (n, m, d) = readInts()
    var a = readInts()
    var sum = 0
    for (i in a) {
        sum += i
    }
    var ans = IntArray(n, {0})
    var pos = -1
    var ind = 0
    for (i in a) {
        ++ind
        var now = pos + 1
        while (now - pos < d && now + 1 + sum <= n) {
            //println("now = $now, sum = $sum, n = $n")
            ++now
        }
        //println("$sum, $n, $now")
        for (x in 0 until i) {
            ans[x + now] = ind
        }
        sum -= i
        pos = now + i - 1
    }
    var ok = false
    if (d > n) {
        ok = true
    }
    for (i in n - 1 downTo Math.max(0, n - d)) {
        if (ans[i] != 0) {
            ok = true
        }
    }
    if (!ok) {
        println("NO")
    } else {
        println("YES")
        println(ans.joinToString(" "))
    }
}