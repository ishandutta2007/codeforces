import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine()
    val six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    val m = line.substring(six + 1).toInt()
    val adj = Array(n + 1) { mutableListOf<Int>() }
    for (j in 2..n) {
        val line = jin.readLine()
        val six = line.indexOf(' ')
        val a = line.substring(0, six).toInt()
        val b = line.substring(six + 1).toInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val parent = IntArray(n + 1)
    val depth = IntArray(n + 1)
    val l = IntArray(n + 1)
    val r = IntArray(n + 1)
    var k = 0
    val stack = Stack<Int>()
    stack.push(-1)
    while (stack.isNotEmpty()) {
        var a = stack.pop()
        if (a < 0) {
            a *= -1
            stack.push(a)
            k++
            l[a] = k
            for (b in adj[a]) {
                if (b != parent[a]) {
                    parent[b] = a
                    depth[b] = depth[a] + 1
                    stack.push(-b)
                }
            }
        } else {
            r[a] = k
        }
    }
    val out = StringBuilder()
    parent[1] = 1
    for (j in 1..m) {
        var tokenizer = StringTokenizer(jin.readLine())
        val query = Array(tokenizer.nextToken().toInt()) { parent[tokenizer.nextToken().toInt()] }
        query.sortBy { depth[it] }
        var works = true
        for (j in 1 until query.size) {
            if (l[query[j]] < l[query[j - 1]] || r[query[j]] > r[query[j - 1]]) {
                works = false
                break
            }
        }
        out.appendln(if (works) "YES" else "NO")
    }
    print(out)
}