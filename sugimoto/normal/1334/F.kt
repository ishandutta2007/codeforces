import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

const val MAX_VALUE = 1000000000000000L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    var tokenizer = StringTokenizer(jin.readLine())
    val array = intArrayOf(0) + IntArray(n) { tokenizer.nextToken().toInt() }
    tokenizer = StringTokenizer(jin.readLine())
    val p = longArrayOf(0L) + LongArray(n) { tokenizer.nextToken().toLong() }
    val m = jin.readLine().toInt()
    tokenizer = StringTokenizer(jin.readLine())
    val brray = intArrayOf(0) + IntArray(m) { tokenizer.nextToken().toInt() }
    val binv = IntArray(n + 1)
    val treeMap = TreeMap<Int, Int>()
    for (j in 1..m) {
        binv[brray[j]] = j
        treeMap[brray[j]] = j
    }
    val bit = BinaryIndexTree(0, m + 1)
    bit.update(1, 2L * MAX_VALUE)
    for (j in 1..n) {
        var prev = MAX_VALUE
        if (binv[array[j]] != 0) {
            prev = bit[binv[array[j]] - 1]
        }
        bit.update(0, p[j])
        if (p[j] > 0L) {
            val entry = treeMap.ceilingEntry(array[j])
            if (entry != null) {
                bit.update(entry.value, -p[j])
            }
        }
        if (prev != MAX_VALUE) {
            val curr = bit[binv[array[j]]]
            if (prev < curr) {
                bit.update(binv[array[j]], prev - curr)
                bit.update(binv[array[j]] + 1, curr - prev)
            }
        }
    }
    val answer = bit[m]
    if (answer < MAX_VALUE) {
        println("YES")
        println(answer)
    } else {
        println("NO")
    }
}

class BinaryIndexTree(val treeFrom: Int, treeTo: Int) {
    val value = LongArray(treeTo - treeFrom + 2)

    fun update(index: Int, delta: Long) {
        var i = index + 1 - treeFrom
        while (i < value.size) {
            value[i] += delta
            i += i and -i
        }
    }

    operator fun get(to: Int): Long {
        var res = 0L
        var i = to + 1 - treeFrom
        while (i > 0) {
            res += value[i]
            i -= i and -i
        }
        return res
    }
}