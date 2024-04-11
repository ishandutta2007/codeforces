

fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(ind in 0 until t) {
        var (a, b, k) = readLine()!!.split(' ').map({it.toInt()})
        println("${(k + 1) / 2 * 1L * a - k / 2 * 1L * b}")
    }
    /*var t = readLine()!!.toInt()
    for(ind in 0 until t) {
        var (a, b) = readLine()!!.split(' ').map({it.toInt()})
        println("${a + b}")
    }*/
}