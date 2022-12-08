import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val nu = jin.readLine().toInt()
    val strings = Array(nu) {
        val s = jin.readLine()
        String(it, s.count { it == 'B' }, s.count { it == 'N' })
    }
    val minB = strings.minBy { it.b }!!.b
    val maxB = strings.maxBy { it.b }!!.b
    val minN = strings.minBy { it.n }!!.n
    val maxN = strings.maxBy { it.n }!!.n
    strings.sortBy { it.b }
    var k = 0
    var answer = Int.MAX_VALUE
    var bestB = 0
    var bestN = 0
    val below = TreeSet<String>(compareBy({ it.b - it.n }, { it.ix }))
    val above = TreeSet<String>(compareBy({ it.b - it.n }, { it.ix }))
    above.addAll(strings)
    for (b in minB..maxB) {
        while (k < nu && strings[k].b <= b) {
            above.remove(strings[k])
            below.add(strings[k])
            k++
        }
        val last = if (above.isEmpty()) null else above.last()
        val limBelow = if (last == null) minN else min(minN, b - last.b + last.n)
        val first = if (below.isEmpty()) null else below.first()
        val limAbove = if (first == null) maxN else max(maxN, b - first.b + first.n)
        val pos = max(max(0, (limAbove - limBelow + 1) / 2), max(b - minB, maxB - b))
        if (pos < answer && (b != 0 || (limBelow + limAbove + 1) / 2 != 0)) {
            answer = pos
            bestB = b
            bestN = (limBelow + limAbove + 1) / 2
        }
    }
    println(answer)
    println("B".repeat(bestB) + "N".repeat(bestN))
}

data class String(val ix: Int, val b: Int, val n: Int)