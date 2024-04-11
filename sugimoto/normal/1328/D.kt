import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        var tokenizer = StringTokenizer(jin.readLine())
        val types = IntArray(n) { tokenizer.nextToken().toInt() }
        val answer = IntArray(n)
        answer[0] = 1
        var sameInstance = -1
        for (j in 1 until n) {
            if (types[j] == types[j - 1]) {
                answer[j] = answer[j - 1]
                sameInstance = j
            } else {
                answer[j] = 3 - answer[j - 1]
            }
        }
        if (answer.max() == 1) {
            out.appendln(1)
        } else {
            if (types[0] == types[n - 1] || answer[0] != answer[n - 1]) {
                out.appendln(2)
            } else {
                if (sameInstance == -1) {
                    answer[0] = 3
                    out.appendln(3)
                } else {
                    for (k in sameInstance until n) {
                        answer[k] = 3 - answer[k]
                    }
                    out.appendln(2)
                }
            }
        }
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}