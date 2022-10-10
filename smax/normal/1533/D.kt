private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var (n, m) = readInts()
    var mp = HashMap<String, Int>()
    for (i in 0 until n) {
        var s = readLn()
        mp.put(s, mp.getOrDefault(s, 0) + 1)
    }

    var q = readInt()
    for (i in 0 until q) {
        var t = readLn()
        var st = HashSet<String>()
        st.add(t.substring(0, m))
        st.add(t.substring(1))
        for (j in 1 until m) {
            st.add(t.substring(0, j) + t.substring(j + 1))
        }
        var ret = 0
        for (s in st) {
            ret += mp.getOrDefault(s, 0)
        }
        println(ret)
    }
}