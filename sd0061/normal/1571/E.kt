import kotlin.math.max

fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    for (ca in 1..t) {
        val n = readLine()!!.toInt()
        var s = readLine()!!.toString()
        var p = readLine()!!.toString()

        val f = Array(2) { IntArray(16) }
        var cur = 0
        var nxt = 1
        f[cur].fill(n + 1)
        f[cur][0] = 0
        for (i in 0 until n) {
            f[nxt].fill(n + 1)
            for (j in 0..15) {
                if (f[cur][j] > n) {
                    continue
                }
                for (k in 0..1) {
                    val delta = (k == 1) xor (s[i] == ')')
                    val l = ((j shl 1) and 15) or k
                    if (i >= 3 && ((p[i - 3] == '1') && (l != 0b0101 && l != 0b0011))) {
                        continue
                    }
                    f[nxt][l] = f[nxt][l].coerceAtMost(f[cur][j] + (if (delta) 1 else 0))
                }
            }
            nxt = cur.also { cur = nxt }
        }
        val res = f[cur].minOf { it }
        println(if(res > n) -1 else res)
    }
}