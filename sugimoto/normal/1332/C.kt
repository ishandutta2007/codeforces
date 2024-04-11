import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val tokenizer = StringTokenizer(jin.readLine())
        val n = tokenizer.nextToken().toInt()
        val k = tokenizer.nextToken().toInt()
        val s = jin.readLine()
        var answer = n
        val seen = BooleanArray(k)
        for (x in 0 until k) {
            if (!seen[x]) {
                seen[x] = true
                val residues = mutableListOf(x)
                val stack = Stack<Int>()
                stack.push(x)
                while (stack.isNotEmpty()) {
                    val y = stack.pop()
                    val z = (n - 1 - y) % k
                    if (!seen[z]) {
                        seen[z] = true
                        residues.add(z)
                        stack.push(z)
                    }
                }
                val freq = IntArray(26)
                for (y in residues) {
                    var j = y
                    while (j < n) {
                        freq[s[j] - 'a']++
                        j += k
                    }
                }
                answer -= freq.max()!!
            }
        }
        out.appendln(answer)
    }
    print(out)
}