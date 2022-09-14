fun main() {
    val t = readLine()!!.toInt()
    for (i in 1..t) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(' ').map { it.toLong() }.sorted()
        var ans: Long = 0
        for (j in 0..n-1) {
            if (a[j] * (n-j) > ans)
                ans = a[j] * (n-j)
        }
        println(ans)
    }
}