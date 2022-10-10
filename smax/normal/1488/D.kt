import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    repeat(readInt()) {
        var (n, s) = readStrings().map { it.toLong() }

        fun check(x: Long): Boolean {
            var tot = 0L
            var num = x
            var cnt = 0
            while (num > 1 && cnt < n) {
                tot += num
                num = (num + 1) / 2
                cnt++
                if (tot > s) {
                    return false
                }
            }
            tot += n - cnt
            return tot <= s
        }

        var l = 1L
        var r = s + 1
        while (l < r) {
            var m = (l + r) / 2
            if (check(m)) {
                l = m + 1
            } else {
                r = m
            }
        }
        println(l - 1)
    }
}