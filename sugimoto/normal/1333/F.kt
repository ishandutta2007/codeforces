fun main() {
    val n = readLine()!!.toInt()
    val allowed = IntArray(n + 1)
    val answer = IntArray(n + 1)
    var k = 1
    for (f in 1..n) {
        var m = 2 * f
        while (m <= n) {
            allowed[m]++
            m += f
        }
    }
    for (im in 1..n) {
        var m = 2 * im
        while (m <= n) {
            allowed[m]--
            if (allowed[m] == 0) {
                k++
                answer[k] = im
            }
            m += im
        }
    }
    println(answer.joinToString(" ").substring(4))
}