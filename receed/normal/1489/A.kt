private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    val n = readInt()
    val a = readInts().reversed()
    val s = mutableSetOf<Int>()
    val res = a.mapNotNull {
        if (s.contains(it))
            null
        else {
            s.add(it)
            it
        }
    }.reversed()
    println(res.size)
    println(res.joinToString(" "))
}