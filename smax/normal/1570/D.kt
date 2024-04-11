private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var n = readInt()
    var st = HashSet<Int>()
    while (!st.contains(n)) {
        st.add(n++)
        while (n % 10 == 0) {
            n /= 10
        }
    }
    println(st.size)
}