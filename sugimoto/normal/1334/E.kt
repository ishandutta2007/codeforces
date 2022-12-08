import java.io.BufferedReader
import java.io.InputStreamReader

val MOD = 998244353L

fun main() {
    val factorial = LongArray(50) { it.toLong() }
    factorial[0] = 1L
    for (j in 1..49) {
        factorial[j] *= factorial[j - 1]
        factorial[j] %= MOD
    }
    val factorialInv = LongArray(50) { factorial[it] pow -1 }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val d = jin.readLine().toLong()
    val primeFactors = mutableListOf<Long>()
    var dt = d
    if (dt % 2L == 0L) {
        primeFactors.add(2L)
        while (dt % 2L == 0L) {
            dt /= 2L
        }
    }
    var f = 3L
    while (f <= 31622776L) {
        if (dt % f == 0L) {
            primeFactors.add(f)
            while (dt % f == 0L) {
                dt /= f
            }
        }
        f += 2L
    }
    if (dt != 1L) {
        primeFactors.add(dt)
    }
    fun calc(u: Long): Long {
        var u = u
        var res = 1L
        var total = 0
        for (p in primeFactors) {
            var e = 0
            while (u % p == 0L) {
                u /= p
                e++
            }
            total += e
            res *= factorialInv[e]
            res %= MOD
        }
        res *= factorial[total]
        res %= MOD
        return res
    }
    val out = StringBuilder()
    for (j in 1..jin.readLine().toInt()) {
        val line = jin.readLine()
        val six = line.indexOf(' ')
        var u = line.substring(0, six).toLong()
        var v = line.substring(six + 1).toLong()
        val g = gcd(u, v)
        u /= g
        v /= g
        val answer = (calc(u) * calc(v)) % MOD
        out.appendln(answer)
    }
    print(out)
}

fun gcd(a: Long, b: Long): Long {
    var a = a
    var b = b
    while (b != 0L) {
        a %= b
        val c = a
        a = b
        b = c
    }
    return a
}

val MOD_TOTIENT = (MOD - 1).toInt()

infix fun Long.pow(power: Int): Long {
    var e = power
    e %= MOD_TOTIENT
    if (e < 0) {
        e += MOD_TOTIENT
    }
    if (e == 0 && this == 0L) {
        return this
    }
    var b = this % MOD
    var res = 1L
    while (e > 0) {
        if (e and 1 != 0) {
            res *= b
            res %= MOD
        }
        b *= b
        b %= MOD
        e = e shr 1
    }
    return res
}