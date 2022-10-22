import kotlin.math.max
import kotlin.math.min

fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    for (case in 1..t) {
        var begin = 0;
        var end = 1000000
        val n = readLine()!!.toInt()
        for (i in 1..n) {
            val (s,t,f: String) = readLine()!!.split(' ')
            val ls = s.length
            val lt = t.length
            val mn = min(ls, lt)
            val lcp = (0 until mn).firstOrNull { s[ls - it - 1] != t[lt - it - 1] } ?: mn
            if (f[0] == '0') {
                // k > lcp
                begin = max(begin, lcp + 1)
            } else {
                // k <= lcp
                end = min(end, lcp)
            }
        }
        if (begin > end) {
            println(0)
        } else {
            println(end - begin + 1)
            println((begin..end).joinToString(separator = " "))
        }
    }
}