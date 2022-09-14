private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val n = readInt()
    val s = List(2 * (n - 1)) { readLn() }
    for (first in s.filter { it.length == n - 1 })
        for (last in s.filter { it.length == 1 }) {
            val a = first + last
            val used = MutableList(n) { MutableList(2) { false } }
            val res = s.mapNotNull {
                when {
                    a.startsWith(it) && !used[it.length][0] -> {
                        used[it.length][0] = true
                        'P'
                    }
                    a.endsWith(it) && !used[it.length][1] -> {
                        used[it.length][1] = true
                        'S'
                    }
                    else -> null
                }
            }.joinToString("")
            if (res.length == (n - 1) * 2) {
                println(res)
                return
            }
        }
}