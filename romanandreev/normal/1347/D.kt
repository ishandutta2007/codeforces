private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun runTest() {
    val n = readInt()
    val ls = readInts().toIntArray()
    var l = 1
    var r = n - 1
    var turn = 1
    var sum1 = ls[0]
    var sum2 = 0
    var lastSum = ls[0]
    while (l <= r) {
        turn++
        var curSum = 0
        while (curSum <= lastSum && l <= r) {
            if (turn % 2 == 0) {
                curSum += ls[r]
                sum2 += ls[r]
                r--
            } else {
                curSum += ls[l]
                sum1 += ls[l]
                l++
            }
        }
        lastSum = curSum
    }
    println("$turn $sum1 $sum2")
}

fun main() {
    val tests = readInt()
    for (test in 1..tests) {
        runTest()
    }
}