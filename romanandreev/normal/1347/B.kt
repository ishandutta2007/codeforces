private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun runTest() {
    val (a1, b1) = readInts().sorted()
    val (a2, b2) = readInts().sorted()
    if (b1 == b2 && a1 + a2 == b1) println("Yes") else println("No")
}

fun main() {
    val tests = readInt()
    for (test in 1..tests) {
        runTest()
    }
}