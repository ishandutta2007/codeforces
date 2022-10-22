import java.util.*


fun main(args : Array<String>) {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map({it.toInt()}).toIntArray()

    a.sort()

    /*for(i in 0 until n) {
        print("${a[i]}")
    }
    println()*/

    var ans = 0
    var i = 0
    while(i < n) {
        ans += a[i + 1] - a[i]
        i += 2
    }

    println("$ans")

    /*var t = readLine()!!.toInt()
    for(ind in 0 until t) {
        var (n, k) = readLine()!!.split(' ').map({it.toInt()})
        for(i in 0 until n) {
            print("${'a' + i % k}")
        }
        println()
    }*/

    /*var t = readLine()!!.toInt()
    for(ind in 0 until t) {
        var (a, b, k) = readLine()!!.split(' ').map({it.toInt()})
        println("${(k + 1) / 2 * 1L * a - k / 2 * 1L * b}")
    }*/

    /*var t = readLine()!!.toInt()
    for(ind in 0 until t) {
        var (a, b) = readLine()!!.split(' ').map({it.toInt()})
        println("${a + b}")
    }*/
}