import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        var tokenizer = StringTokenizer(readLine()!!)
        val a = IntArray(n) { tokenizer.nextToken().toInt() }
        tokenizer = StringTokenizer(readLine()!!)
        val b = IntArray(n) { tokenizer.nextToken().toInt() }
        var is1 = false
        var isNeg = false
        var answer = true
        for (j in 0 until n) {
            if (a[j] < b[j]) {
                if (!is1) {
                    answer = false
                    break
                }
            } else if (a[j] > b[j]) {
                if (!isNeg) {
                    answer = false
                    break
                }
            }
            if (a[j] == 1) {
                is1 = true
            } else if (a[j] == -1) {
                isNeg = true
            }
        }
        println(if (answer) "yEs" else "nO")
    }
}