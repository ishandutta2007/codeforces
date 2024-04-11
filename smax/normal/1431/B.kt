private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map{it.toInt()}

fun main() {
    var t = readInt()
    repeat(t) {
        var s = readLn()
        var n = s.length
        var ret = 0
        var run = 0
        for (i in 0 until n) {
            if (s[i] == 'v') {
                run++
            } else if (s[i] == 'w') {
                ret += run / 2 + 1
                run = 0
            }
        }
        ret += run / 2
        println(ret)
    }
}