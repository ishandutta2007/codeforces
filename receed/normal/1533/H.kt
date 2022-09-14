private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLong() = readLn().toLong()
private fun readLongs() = readStrings().map { it.toLong() }

fun main() {
    val (n, m) = readInts()
    val a = List(n) { readLn().map { it - 'A' } }
    val k = 5
    val pw = 1 shl k
    val left = MutableList(m) { 0 }
    val md = MutableList(m) { 0 }
    val dp = (0 until pw).map { mask ->
        md.fill(0)
        var ca = 0L
        for (i in 0 until n) {
            for (j in 0 until m) {
                if (((mask shr a[i][j]) and 1) == 1)
                    md[j]++
                else
                    md[j] = 0
            }
            left.fill(0)
            val st = mutableListOf<Int>()
            for (j in 0 until m) {
                while (st.isNotEmpty() && md[st.last()] >= md[j])
                    st.removeLast()
                left[j] = st.lastOrNull() ?: -1
                st.add(j)
            }
            st.clear()
            for (j in m-1 downTo 0) {
                while (st.isNotEmpty() && md[st.last()] > md[j])
                    st.removeLast()
                val right = st.lastOrNull() ?: m
                ca += (right - j).toLong() * (j - left[j]) * md[j]
                st.add(j)
            }
        }
        ca
    }.toMutableList()
    val ans = MutableList(k) {0L}
    for (i in 1 until pw) {

        for (j in 0 until i)
            if ((i and j) == j)
                dp[i] -= dp[j]
        val pc = (0 until k).map { (i shr it) and 1}.sum()
        ans[pc - 1] += dp[i]
    }
    println(ans.joinToString(" "))
}