private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var n = readInt()
    var a = readInts()

    var tot = 0L
    var mx = 0
    var mx2 = 0
    for (x in a) {
        tot += x
        if (x >= mx) {
            mx2 = mx
            mx = x
        } else if (x > mx2) {
            mx2 = x
        }
    }

    var ret = mutableListOf<Int>()
    for (i in 0 until n) {
        if ((tot - a[i]) % 2 == 0L && (tot - a[i]) / 2 == (if (a[i] == mx) mx2 else mx).toLong()) {
            ret.add(i)
        }
    }

    println(ret.size)
    println(ret.joinToString(" ") { (it + 1).toString() })
}