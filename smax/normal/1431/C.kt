import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map{it.toInt()}

fun main() {
    var t = readInt()
    repeat(t) {
        var (n, k) = readInts()
        var p = readInts()
        var j = n - 1
        var ret = 0
        var sum = 0
        for (i in n - 1 downTo 0) {
            sum += p[i]
            while (j - i + 1 > (n - i) / k)
                sum -= p[j--]
            ret = max(ret, sum)
        }
        println(ret)
    }
}