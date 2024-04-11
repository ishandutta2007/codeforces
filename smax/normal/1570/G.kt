private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    print("?")
    for (x in 1..100) {
        print(" $x")
    }
    println()
    var x = readInt()
    var ret = x and (((1 shl 7) - 1) shl 7)
    print("?")
    for (x in 0 until 100) {
        print(" ${x shl 7}")
    }
    println()
    x = readInt()
    ret += x and ((1 shl 7) - 1)
    println("! $ret")
}