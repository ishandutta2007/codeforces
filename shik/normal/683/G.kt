import java.util.Scanner
import java.util.Arrays

fun gcd(a: Int, b: Int): Int {
    if (b == 0) return a
    else return gcd(b, a % b)
}

fun main(args: Array<String>) {
    var s = readLine()!!.split("(")
    var sa = s[0].substring(2)
    var a = ("0" + sa).toInt()
    var sb = s[1].split(")")[0]
    var b = sb.toInt()
    var q = 1
    for (i in 1..sb.length) q *= 10
    q--
    for (i in 1..sa.length) q *= 10
    var p = a
    for (i in 1..sb.length) p *= 10
    p += b - a
    var g = gcd(p, q)
    p /= g
    q /= g
    println("$p/$q")
}