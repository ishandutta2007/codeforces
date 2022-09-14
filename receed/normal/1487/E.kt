private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val n = readInts()
    val a = MutableList(4) { readLongs().toMutableList() }
    val inf = 1e10.toLong()
    for (i in 1..3) {
        val m = readInt()
        val e = List(m) { readInts() }.groupBy({ it[1] - 1 }) { a[i - 1][it[0] - 1] }.mapValues { it.value.sorted() }
        a[i - 1].sort()
        a[i] = a[i].withIndex().map { (index, value) ->
            val del = e.getOrDefault(index, listOf()) + {-1}
            value + (del.zip(a[i - 1]).firstOrNull {it.first != it.second}?.second ?: inf)
        }.toMutableList()
    }
    val res = a[3].minOrNull()
    println(if (res == null || res >= inf) -1 else res)
}