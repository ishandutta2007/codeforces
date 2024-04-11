import kotlin.math.max

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val n = readInt()
    val a = readLongs().sorted()
    val b = readLongs().sorted()
    val inf = 1e10.toLong()
    val m1 = a.zip(b).map { it.second - it.first }.runningFold(-inf, ::max)
    val m2 = a.reversed().zip(b.reversed()).map { it.second - it.first }.runningFold(-inf, ::max)
    val q = readInt()
    print(readLongs().map {
        var pos = a.binarySearch(it)
        if (pos < 0)
            pos = -pos - 1
        max(m1[pos], max(m2[n - pos], b[pos] - it))
    }.joinToString(" "))
}