fun main() {
    var (n, qm) = readLine()!!.split(" ").map { it.toInt() }
    var a = readLine()!!.split(" ").map { it.toInt() }
    var s = ArrayList<Int>()
    s.add(0)
    var ss = 0
    var i = 0
    while (i < n) {
        ss += a[i]
        s.add(ss)
        i++
    }
    // println(s.joinToString(" "))

    var qq = readLine()!!.toInt()
    var qa = ArrayList<String>()
    while (qq > 0) {
        qq--
        var ssw = readLine()!!.split(" ").map { it.toInt() }
        var b = ssw.toCollection(ArrayList())
        b.add(qm + 1)
        var ci = 0
        var pd = 0
        var first = true
        for (di in b) {
            var space = di - pd - 1
            if (first) {
                first = false
                continue
            }
            pd = di

            var l = ci
            var r = n
            while (r - l > 1) {
                var m = (l + r) / 2
                if (s[m] - s[ci] > space) r = m
                else l = m
            }
            if (s[r] - s[ci] <= space) l = r
            ci = l
            // println("after " + di.toString() + " ci = " + ci.toString())
        }
        if (ci == n) qa.add("YES")
        else qa.add("NO")
    }
    println(qa.joinToString("\n"))
}