import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val MOD = 998244353L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val adj = Array(n + 1) { mutableSetOf<Int>() }
    for (j in 2..n) {
        val line = jin.readLine()
        val six = line.indexOf(' ')
        val a = line.substring(0, six).toInt()
        val b = line.substring(six + 1).toInt()
        adj[a].add(b)
        adj[b].add(a)
    }
    val dpNo = LongArray(n + 1) { 1L }
    val dpYes = LongArray(n + 1) { 1L }
    val dpAll = LongArray(n + 1) { 1L }
    val stack = Stack<Int>()
    stack.push(-1)
    while (stack.isNotEmpty()) {
        var a = stack.pop()
        if (a < 0) {
            a *= -1
            stack.push(a)
            for (b in adj[a]) {
                adj[b].remove(a)
                stack.push(-b)
            }
        } else {
            for (b in adj[a]) {
                dpNo[a] *= ((2L * dpNo[b]) + (2L * dpYes[b]) + dpAll[b]) % MOD
                dpNo[a] %= MOD
                dpYes[a] *= ((2L * dpNo[b]) + dpYes[b]) % MOD
                dpYes[a] %= MOD
                dpAll[a] *= (dpNo[b] + dpYes[b]) % MOD
                dpAll[a] %= MOD
            }
            dpYes[a] -= dpAll[a]
            dpYes[a] %= MOD
            //println("a = $a, dpNo = ${dpNo[a]}, dpYes = ${dpYes[a]}, dpAll = ${dpAll[a]}")
        }
    }
    val answer = (((dpNo[1] + dpYes[1] - 1L) % MOD) + MOD) % MOD
    println(answer)
}