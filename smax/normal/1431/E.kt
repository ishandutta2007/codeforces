import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map{it.toInt()}

const val INF = 1000000000

fun main() {
    var t = readInt()
    repeat(t) {
        var n = readInt()
        var a = readInts()
        var b = readInts()
        var mx = -INF
        var mxIdx = -1
        for (i in 0 until n) {
            var mn = INF
            for (j in i until n)
                mn = min(mn, abs(a[j - i] - b[j]))
            for (j in 0 until i)
                mn = min(mn, abs(a[n - i + j] - b[j]))
            if (mn > mx) {
                mx = mn
                mxIdx = i
            }
        }
        for (i in mxIdx until n) {
            print(i + 1)
            print(' ')
        }
        for (i in 0 until mxIdx) {
            print(i + 1)
            print(' ')
        }
        println()
    }
}