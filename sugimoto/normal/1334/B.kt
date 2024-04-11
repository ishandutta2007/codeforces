import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        var tokenizer = StringTokenizer(jin.readLine())
        val n = tokenizer.nextToken().toInt()
        val x = tokenizer.nextToken().toLong()
        tokenizer = StringTokenizer(jin.readLine())
        val savings = Array(n) { tokenizer.nextToken().toLong() }
        savings.sortDescending()
        var upper = n
        var lower = 0
        while (upper > lower) {
            val mid = (upper + lower + 1) / 2
            var total = 0L
            for (j in 0 until mid) {
                total += savings[j]
            }
            if (total >= x * mid.toLong()) {
                lower = mid
            } else {
                upper = mid - 1
            }
        }
        println(upper)
    }
}