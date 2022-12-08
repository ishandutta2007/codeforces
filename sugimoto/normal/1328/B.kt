import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine()
        val six = line.indexOf(' ')
        val n = line.substring(0, six).toLong()
        var k = line.substring(six + 1).toLong()
        var rem = 2
        for (j in 1L..n) {
            if (rem == 2) {
                val next = ((n - j) * (n - j - 1L)) / 2L
                if (k > next) {
                    out.append('b')
                    k -= next
                    rem--
                } else {
                    out.append('a')
                }
            } else if (rem == 1) {
                val next = n - j
                if (k > next) {
                    out.append('b')
                    k -= next
                    rem--
                } else {
                    out.append('a')
                }
            } else {
                out.append('a')
            }
        }
        out.appendln()
    }
    print(out)
}