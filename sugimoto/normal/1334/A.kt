fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        var p1 = 0
        var c1 = 0
        var answer = true
        for (j in 1..n) {
            val line = readLine()!!
            val six = line.indexOf(' ')
            val p2 = line.substring(0, six).toInt()
            val c2 = line.substring(six + 1).toInt()
            if (c2 - c1 > p2 - p1 || p2 < p1 || c2 < c1) {
                answer = false
            }
            c1 = c2
            p1 = p2
        }
        println(if (answer) "YES" else "NO")
    }
}