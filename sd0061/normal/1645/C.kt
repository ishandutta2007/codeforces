fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map {x -> x.toInt()}
    a = a.sorted()
    var res = 0
    for (i in 0..n/2-1) {
        res += a[i * 2 + 1] - a[i * 2]
    }
    println(res)
}