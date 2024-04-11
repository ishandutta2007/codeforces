private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var t = readInt()
    repeat(t) {
        var s = readLn()
        var n = s.length
        var lessThan = false
        var greaterThan = false
        for (i in 0 until n) {
            if (s[i] == '<') lessThan = true;
            else if (s[i] == '>') greaterThan = true;
        }
        if (lessThan) {
            if (greaterThan)
                println("?")
            else
                println("<")
        } else if (greaterThan) {
            println(">")
        } else {
            println("=")
        }
    }
}