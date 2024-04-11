fun main() {
    val t = readLine()!!.toInt()
    for (z in 1..t) {
        val (n, k) = readLine()!!.split(' ').map {it.toInt() }
        val a = readLine()!!.split(' ').map {it.toInt() }
        val ps = a.runningFold(0) {x, y -> x+y }
        var ans = 0
        for (i in 1..n) {
            var cur = ps[n - i + i / k] - ps[n - i]
            if (cur > ans)
                ans = cur
        }
        println(ans)
    }
}