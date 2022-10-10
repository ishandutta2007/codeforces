private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var n = readInt()
    var a = readInts()
    var p = IntArray(n) { it }.sortedByDescending { a[it] }
    var ret = 0
    for (i in 0 until n) {
        ret += a[p[i]] * i + 1
    }
    println(ret)
    println(p.joinToString(" ") { (it + 1).toString() })
}