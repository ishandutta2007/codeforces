private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val result = mutableListOf<Int>()
        for (i in 1..n)
            for (j in i + 1..n) {
                val x = (j - i) * 2 - n
                if (x > 0) result.add(1)
                else if (x < 0) result.add(-1)
                else result.add(0)
            }
        println(result.joinToString(" "))
    }
}