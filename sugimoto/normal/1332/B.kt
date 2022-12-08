import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val PRIMES = arrayOf(2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31)

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val tokenizer = StringTokenizer(jin.readLine())
        val array = IntArray(n) { tokenizer.nextToken().toInt() }
        val answer = IntArray(n)
        var color = 1
        for (p in PRIMES) {
            var used = false
            for (j in 0 until n) {
                if (array[j] > 0 && array[j] % p == 0) {
                    used = true
                    answer[j] = color
                    array[j] *= -1
                }
            }
            if (used) {
                color++
            }
        }
        println(color - 1)
        println(answer.joinToString(" "))
    }
}