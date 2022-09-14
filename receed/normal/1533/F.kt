private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val a = readLn().map { it - '0' }
    val n = a.size
    val inf = 1e9.toInt()
    val ps = (0..1).map { d ->
        a.runningFold(0) { x, y -> x + (if (d == y) 1 else 0) }
    }
    val mp = (0..1).map { d -> a.withIndex().filter { it.value == d }.map { it.index } }
    println((1..n).map { k ->
        var pos = 0
        var ans = 0
        while (pos < n) {
            pos = (0..1).map { d ->
                if (ps[d][pos] + k < mp[d].size)
                    mp[d][ps[d][pos] + k]
                else
                    n
            }.maxOrNull()!!
            ans++
        }
        ans
    }.joinToString(" "))
}