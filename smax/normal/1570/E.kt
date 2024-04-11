private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var t = readInt()
    repeat(t) {
        var s = readLn()
        var n = s.length
        var l = 0
        var r = n - 1
        while (l < n && s[l] == '0')
            l++
        while (r >= 0 && s[r] == '0')
            r--
        var ret = 0
        for (i in l..r)
            if (s[i] == '0')
                ret++
        println(ret)
    }
}