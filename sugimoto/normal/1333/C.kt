import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    val array = LongArray(n) { tokenizer.nextToken().toLong() }
    val sums = LongArray(n + 1)
    for (j in 1..n) {
        sums[j] = sums[j - 1] + array[j - 1]
    }
    val seen = mutableSetOf<Long>()
    var answer = 0L
    var r = 0
    for (l in 0 until n) {
        seen.add(sums[l])
        if (r < l) {
            r = l
        }
        while (r < n && sums[r + 1] !in seen) {
            r++
            seen.add(sums[r])
        }
        answer += (r - l).toLong()
        seen.remove(sums[l])
    }
    println(answer)
}