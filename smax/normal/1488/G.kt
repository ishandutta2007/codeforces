import java.util.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var n = readInt()
    var cnt = IntArray(n + 1)
    var st = TreeSet<Int>(object : Comparator<Int> {
        override fun compare(o1: Int, o2: Int): Int {
            if (cnt[o1] == cnt[o2]) {
                return o1 - o2
            }
            return cnt[o1] - cnt[o2]
        }
    })
    for (x in 2..n) {
        var i = 1
        while (i * i <= x) {
            if (x % i == 0) {
                cnt[x]++
                if (i > 1 && x / i != i) {
                    cnt[x]++
                }
            }
            i++
        }
        st.add(x)
    }

    var ret = 0
    var retList = mutableListOf<Int>()
    repeat(n) {
        var x = st.pollLast()
        ret += cnt[x]
        retList.add(ret)
        var i = 1
        while (i * i <= x) {
            if (x % i == 0) {
                st.remove(i)
                cnt[i]--
                st.add(i)
                if (i > 1 && x / i != i) {
                    st.remove(x / i)
                    cnt[x / i]--
                    st.add(x / i)
                }
            }
            i++
        }
    }
    println(retList.joinToString(" "))
}