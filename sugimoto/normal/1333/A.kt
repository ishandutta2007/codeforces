import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val tokenizer = StringTokenizer(readLine()!!)
        val n = tokenizer.nextToken().toInt()
        val m = tokenizer.nextToken().toInt()
        print('W')
        for (j in 2..m) {
            print('B')
        }
        println()
        for (k in 2..n) {
            for (j in 1..m) {
                print('B')
            }
            println()
        }
    }
}