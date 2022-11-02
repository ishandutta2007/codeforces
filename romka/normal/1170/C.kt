fun main() {
    var n = readLine()!!.toInt() // read integer from the input
    while (n > 0) {
        n--
        var s1 = readLine()!!
        var s2 = readLine()!!
        var i1 = 0
        var i2 = 0
        var fail = false
        while (i1 < s1.length && i2 < s2.length) {
            if (s1[i1] == s2[i2]) {
                i1++
                i2++
            } else
                if (s1[i1] == '+') {
                    fail = true
                    break
                } else if (i1 + 1 == s1.length || s1[i1 + 1] != '-') {
                    fail = true
                    break
                } else {
                    i1 += 2
                    i2++
                }
        }
        fail = fail || (i1 != s1.length || i2 != s2.length)
        if (fail) println("NO")
        else println("YES")
    }
}