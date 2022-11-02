fun main() {
    var (n, m, k) = readLine()!!.split(" ").map { it.toInt() }
    var ba = readLine()!!.split(" ").map { it.toLong() }
    var a = ArrayList<Long>()
    for (e in ba) a.add(e)
    a.sort()

    var s = ArrayList<Long>()
    s.add(0)
    var ss: Long = 0
    var i = 0
    while (i < n) {
        ss += a[i]
        s.add(ss)
        i++
    }

    i = 0
    var ans: Long = -1
    while (i + m <= n) {
        var med = i + (m - 1) / 2

        var l = i
        var r = med

        while (r - l > 1) {
            var mm = (l + r) / 2

            var sm = a[mm] * (mm - i + 1) - (s[mm + 1] - s[i])
            if (sm <= k) l = mm
            else r = mm
        }

        var mm = r
        var sm = a[mm] * (mm - i + 1) - (s[mm + 1] - s[i])
        if (sm <= k) l = mm

        var lim = a[l]
        var left = k - (a[l] * (l - i + 1) - (s[l + 1] - s[i]))
        if (l < med) lim = lim + left / (l - i + 1)

        var tm: Long = lim * (l - i + 1) - (s[l + 1] - s[i])
        var rr = i + m - 1
        tm = tm + (s[rr + 1] - s[l + 1]) - lim * (rr - l)

        // println("============")
        // println("i = " + i.toString() + ", lim = " + lim.toString() + ", tm = " + tm.toString() + ", l = " + l.toString())

        if (tm < ans || ans == -1L) ans = tm
        i++
    }
    println(ans)
}