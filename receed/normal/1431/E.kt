fun main() {
    val t = readLine()!!.toInt()
    for (z in 1..t) {
        val n = readLine()!!.toInt()

        val a = readLine()!!.split(' ').map {it.toInt() }.withIndex().sortedBy {it.value}
        val b = readLine()!!.split(' ').map {it.toInt() }.withIndex().sortedBy {it.value}
        var ans = -1
        var pos = 0
        for (i in 0..n) {
            var ca = 1000000000
            for (j in 0..i-1) {
                val na = Math.abs(a[j].value - b[n - i + j].value)
                if (na < ca)
                    ca = na
            }
            for (j in i..n-1) {
                val na = Math.abs(a[j].value - b[j - i].value)
                if (na < ca)
                    ca = na
            }
            if (ca > ans) {
                ans = ca
                pos = i
            }
        }
        var res = MutableList<Int>(n) {0}
        for (i in 0..pos-1)
            res[a[i].index] = b[n - pos + i].index + 1
        for (i in pos..n-1)
            res[a[i].index] = b[i - pos].index + 1
        println(res.joinToString(" "))
    }
}