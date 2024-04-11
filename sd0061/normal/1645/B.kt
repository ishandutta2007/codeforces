fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val s = readLine()
    var i = 0
    var step = 1
    var res = ""
    while (i < n) {
        res += s!![i]
        i += step
        step ++
    }
    println(res)
}