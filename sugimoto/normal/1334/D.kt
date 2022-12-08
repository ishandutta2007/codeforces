import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val tokenizer = StringTokenizer(readLine()!!)
        val n = tokenizer.nextToken().toInt()
        var l = tokenizer.nextToken().toLong()
        var r = tokenizer.nextToken().toLong()
        val joiner = StringJoiner(" ")
        for (k in 1..n) {
            val amt = (n - k).toLong() * 2L
            if (l > amt) {
                l -= amt
                r -= amt
            } else {
                if (r > amt) {
                    while (l <= amt) {
                        if (l % 2L == 1L) {
                            joiner.add(k.toString())
                        } else {
                            joiner.add(((l / 2L) + k.toLong()).toString())
                        }
                        l++
                    }
                    l -= amt
                    r -= amt
                } else {
                    while (l <= r) {
                        if (l % 2L == 1L) {
                            joiner.add(k.toString())
                        } else {
                            joiner.add(((l / 2L) + k.toLong()).toString())
                        }
                        l++
                    }
                    l = 0
                    r = 0
                    break
                }
            }
        }
        if (r == 1L) {
            joiner.add("1")
        }
        println(joiner)
    }
}