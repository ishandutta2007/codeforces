private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    repeat(readInt()) {
        var n = readInt()
        var x = readInts()
        var ok = false
        for (i in 1 until n) {
            if ((x[i] - x[i-1]) % 2 == 0) {
                ok = true
                break
            }
        }
        println(if (ok) "YES" else "NO")
    }
}