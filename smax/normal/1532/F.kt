private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
    var n = readInt()
    var s = Array(2 * n - 2) { readLn() }
    var idx = IntArray(2 * n - 2) { it }.sortedBy { s[it].length }

    var cand = mutableListOf<String>()
    if (s[idx[2 * n - 3]].substring(1, n - 1) == s[idx[2 * n - 4]].substring(0, n - 2)) {
        cand.add(s[idx[2 * n - 3]] + s[idx[2 * n - 4]][n - 2])
    }
    if (s[idx[2 * n - 4]].substring(1, n - 1) == s[idx[2 * n - 3]].substring(0, n - 2)) {
        cand.add(s[idx[2 * n - 4]] + s[idx[2 * n - 3]][n - 2])
    }

    for (str in cand) {
        var ret = CharArray(2 * n - 2)
        var ok = true
        for (i in 0 until n - 1) {
            if (str.substring(0, i + 1) == s[idx[2 * i]] && str.substring(n - i - 1, n) == s[idx[2 * i + 1]]) {
                ret[idx[2 * i]] = 'P'
                ret[idx[2 * i + 1]] = 'S'
            } else if (str.substring(0, i + 1) == s[idx[2 * i + 1]] && str.substring(n - i - 1, n) == s[idx[2 * i]]) {
                ret[idx[2 * i]] = 'S'
                ret[idx[2 * i + 1]] = 'P'
            } else {
                ok = false
                break
            }
        }
        if (ok) {
            println(ret.joinToString(""))
            break
        }
    }
}