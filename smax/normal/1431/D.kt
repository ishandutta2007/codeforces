private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(' ')
private fun readInts() = readStrings().map{it.toInt()}

fun main() {
    var t = readInt()
    repeat(t) {
        var n = readInt()
        var a = readInts()
        var b = Array<Pair<Int, Int>>(n){i -> Pair(a[i], i)}
        b.sortWith(Comparator<Pair<Int, Int>> { p, q ->
            when {
                p.first != q.first -> p.first.compareTo(q.first)
                else -> p.second.compareTo(q.second)
            }
        })
        var i = 0
        var j = n - 1
        var cnt = 0
        var ret = mutableListOf<Int>()
        while (i <= j) {
            while (cnt < b[i].first && i <= j) {
                cnt++
                ret.add(b[j--].second + 1)
            }
            if (i <= j) {
                cnt = 1
                ret.add(b[i++].second + 1)
            }
        }
        println(ret.joinToString(" "))
    }
}