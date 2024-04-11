import java.io.PrintWriter
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun runTest() {
    val (a, b) = readInts()
    println(a + b)
}

fun main() {
    val tests = readInt()
    for (test in 1..tests) {
        runTest()
    }
}