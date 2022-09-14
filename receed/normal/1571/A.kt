import kotlin.math.max

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val t = readInt()
    repeat(t) {
        val a = readLn().replace("=", "")
        if (a.isEmpty())
            println("=")
        else if (">" !in a)
            println("<")
        else if ("<" !in a)
            println(">")
        else
            println("?")
    }
}