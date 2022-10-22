import java.lang.Integer.*
import java.util.*


fun main(args : Array<String>) {
    var a1 = readLine()!!.toInt()
    var a2 = readLine()!!.toInt()
    var k1 = readLine()!!.toInt()
    var k2 = readLine()!!.toInt()
    var n = readLine()!!.toInt()

    if(k1 < k2) {
        a1 += a2
        a2 = a1 - a2
        a1 -= a2

        k1 += k2
        k2 = k1 - k2
        k1 -= k2
    }

    var mx = 0

    if(n >= a2 * k2)
        mx = a2 + (n - a2 * k2) / k1
    else
        mx = n / k2


    var mn = max(0, n - a2 * (k2 - 1) - a1 * (k1 - 1))

    println("$mn $mx")
}

/*fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(_case in 1..t) {
        var (a, b) = readLine()!!.split(" ").map({it.toInt()})
        println("${a + b}")
    }
}*/