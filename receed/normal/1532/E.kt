private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val n = readInt()
    val a = readLongs().withIndex().sortedBy { it.value }
    val s = a.sumOf { it.value }
    val res = a.withIndex().filter { (index, value) ->
      val last = if (index + 1 == n) a[n - 2] else a.last()
       val sum = s - value.value
       last.value * 2 == sum
    }.map { it.value.index + 1 }.toList()
    println(res.size)
    println(res.joinToString(" "))
}