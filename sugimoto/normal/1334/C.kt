import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val monsters = Array(n) {
            val line = jin.readLine()
            val six = line.indexOf(' ')
            Monster(line.substring(0, six).toLong(), line.substring(six + 1).toLong())
        }
        var answer = 0L
        for (j in 0 until n) {
            answer += max(0L, monsters[(j + 1) % n].health - monsters[j].explosion)
        }
        var minStart = Long.MAX_VALUE
        for (j in 0 until n) {
            minStart = min(minStart, monsters[(j + 1) % n].health - max(0L, monsters[(j + 1) % n].health - monsters[j].explosion))
        }
        out.appendln(answer + minStart)
    }
    print(out)
}

data class Monster(val health: Long, val explosion: Long)