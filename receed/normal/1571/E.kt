import kotlin.math.max
import kotlin.math.min

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun String.diff(b: String) = zip(b).count { (x, y) -> x != y}

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val s = readLn()
        val a = readLn().map { it == '1' }
        if (a.zipWithNext().any { it.first && it.second }) {
            println(-1)
            return@repeat
        }
        var ans = 0
        for (i in a.indices) {
            if (!a[i])
                continue
            if (i + 2 < a.size && a[i + 2])
                ans += s.substring(i, i + 2).diff("()")
            else if (i - 2 >= 0 && a[i - 2])
                ans += s.substring(i, i + 4).diff("()()")
            else
                ans += min(s.substring(i, i + 4).diff("()()"), s.substring(i, i + 4).diff("(())"))
        }
        println(ans)
    }
}