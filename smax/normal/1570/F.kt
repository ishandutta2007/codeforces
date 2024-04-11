private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var (n, m) = readInts()
    var a = Array<List<Int>>(n) { readInts() }
    var b = Array<IntArray>(n) { IntArray(m) }
    var ret = ArrayList<Pair<Int, Int>>()
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (i < n - 1 && j < m - 1 && a[i][j] == 1 && a[i+1][j] == 1 && a[i][j+1] == 1 && a[i+1][j+1] == 1) {
                b[i][j] = 1
                b[i+1][j] = 1
                b[i][j+1] = 1
                b[i+1][j+1] = 1
                ret.add(Pair(i, j))
            }
            if (a[i][j] != b[i][j]) {
                println(-1)
                return
            }
        }
    }
    println(ret.size)
    println(ret.joinToString("\n") { "${it.first + 1} ${it.second + 1}" })
}