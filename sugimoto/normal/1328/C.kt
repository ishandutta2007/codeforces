import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val x = jin.readLine()
        val a = StringBuilder()
        val b = StringBuilder()
        var seen = false
        for (j in 1..n) {
            when (x[j - 1] - '0') {
                0 -> {
                    a.append(0)
                    b.append(0)
                }
                1 -> {
                    if (seen) {
                        a.append(0)
                        b.append(1)
                    } else {
                        a.append(1)
                        b.append(0)
                        seen = true
                    }
                }
                2 -> {
                    if (seen) {
                        a.append(0)
                        b.append(2)
                    } else {
                        a.append(1)
                        b.append(1)
                    }
                }
            }
        }
        out.appendln(a)
        out.appendln(b)
    }
    print(out)
}