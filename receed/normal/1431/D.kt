fun main() {
    val t = readLine()!!.toInt()
    for (z in 1..t) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map {it.toInt() }.withIndex().sortedBy {it.value}
        var ans = mutableListOf<Int>()
        var r = n
        for (i in 0..n-1) {
            if (i >= r)
                break
            val cnt = if (i == 0) a[i].value else a[i].value - 1
            if (i + 1 + cnt <= r) {
                for (j in 1..cnt) {
                    ans.add(a[r - 1].index + 1)
                    r -= 1
                }
            }
            ans.add(a[i].index + 1)
        }
        println(ans.joinToString(" "))
    }
}