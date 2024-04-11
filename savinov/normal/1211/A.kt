private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val n = readInt()

    val a = readInts()

    val min = a.min()
    val max = a.max()

    if (min == max) {
        println("-1 -1 -1")
        return
    }
    
    val minPos = a.indexOfFirst { it == min }
    val maxPos = a.indexOfFirst {it == max}
    val other = a.indexOfFirst {it != min && it != max}
    
    if (other == -1) {
        println("-1 -1 -1")
        return
    }
    
    println("${minPos + 1} ${other + 1} ${maxPos + 1}")
}