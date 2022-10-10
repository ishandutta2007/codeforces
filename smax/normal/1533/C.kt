private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    repeat(readInt()) {
        var (n, k) = readInts()
        var s = readLn()

        var par = IntArray(n) { it }

        fun find(u: Int): Int {
            if (par[u] != u) {
                par[u] = find(par[u])
            }
            return par[u]
        }

        var cnt = s.count { it == '1' }
        var ret = 0
        var pos = n - k
        var vis = BooleanArray(n)
        while (cnt > 0) {
            for (i in 0 until k) {
                pos = find((pos + 1) % n)
            }
            ret++
            vis[pos] = true
            par[pos] = (pos + 1) % n
            if (s[pos] == '1') {
                cnt--
            }
        }
        println(ret)
    }
}