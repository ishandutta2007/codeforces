import java.io.BufferedInputStream
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = FastScanner()
    val n = jin.nextInt()
    val d = jin.nextInt()
    val m = jin.nextInt().toLong()
    val funs = Array(n) { jin.nextInt().toLong() }
    funs.sort()
    val sums = LongArray(n + 1)
    for (j in 1..n) {
        sums[j] = sums[j - 1] + funs[j - 1]
    }
    var x = 0
    for (f in funs) {
        if (f > m) {
            x++
        }
    }
    var answer = 0L
    for (j in (x + d) / (d + 1)..min(x, (n + d) / (d + 1))) {
        val pos = if (((d + 1) * j) - d <= x) {
            sums[n - x]
        } else {
            sums[n - x] - sums[((d + 1) * j) - d - x]
        } + (sums[n] - sums[n - j])
        answer = max(answer, pos)
    }
    println(answer)
}

class FastScanner {
    private val BS = 1 shl 16
    private val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC
    private var `in`: BufferedInputStream? = null

    constructor() {
        `in` = BufferedInputStream(System.`in`, BS)
    }

    private val char: Char
        private get() {
            while (bId == size) {
                size = try {
                    `in`!!.read(buf)
                } catch (e: Exception) {
                    return NC
                }
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toChar()
        }

    fun nextInt(): Int {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0
        while (c >= '0' && c <= '9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
}