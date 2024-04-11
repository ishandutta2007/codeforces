private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var n = readInt()
    var a = readInts().sorted()
    var ret = 0
    for (i in 0 until n step 2) {
        ret += a[i+1] - a[i]
    }
    println(ret)
}