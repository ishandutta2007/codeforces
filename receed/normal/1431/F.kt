
class C: Comparator<Pair<Long, Int>>{
    override fun compare(o1: Pair<Long, Int>?, o2: Pair<Long, Int>?): Int {
        if (o1!!.first == o2!!.first)
            return o1!!.second.compareTo(o2.second)
        return o1!!.first.compareTo(o2!!.first)
    }
}


fun main() {
    val (n, k, x) = readLine()!!.split(' ').map { it.toInt() }
    val a = readLine()!!.split(' ').map {it.toLong() }
    var l: Long = -1
    var r: Long = 30000000000
    while (r - l > 1) {
        val m = (l + r) / 2
        val s1 = sortedSetOf<Pair<Long, Int>>(C())
        var cs: Long = 0
        var dd = 0
        for (i in 0..n-1) {
            s1.add(a[i] to i)
            cs += a[i]
            while (cs > m) {
                dd += 1
                cs -= s1.last().first
                s1.remove(s1.last())
            }
            if (i == n - 1 || s1.size == x) {
                s1.clear()
                cs = 0
            }
        }
        if (dd <= k)
            r = m
        else
            l = m
    }
    println(r)
}