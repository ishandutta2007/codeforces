private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun runTest() {
    var n = readInt()
    var mul = 1
    val ls = mutableListOf<Int>()
    while (n > 0) {
        val o = n % 10
        if (o != 0) {
            ls.add(o * mul)
        }
        mul *= 10
        n /= 10
    }
    println(ls.size)
    for (x in ls) {
        print(x)
        print(" ")
    }
    println()
}

fun main() {
    val tests = readInt()
    for (test in 1..tests) {
        runTest()
    }
}