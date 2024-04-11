private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val n = readInt()
    val a = generateSequence { readLn() }.take(n).toList().sortedBy { it.length }
    if (a.zipWithNext().all { (s1, s2) -> s2.contains(s1) }) {
        println("YES")
        println(a.joinToString("\n"))
    }
    else
        println("NO")
}