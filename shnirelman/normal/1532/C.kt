

fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(ind in 0 until t) {
        var (n, k) = readLine()!!.split(' ').map({it.toInt()})
        for(i in 0 until n) {
            print("${'a' + i % k}")
        }
        println()
    }

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