fun main() {
    var n = readLine()!!.toInt() // read integer from the input
    while (n > 0) {
        n--
        var (ab, ac) = readLine()!!.split(" ").map { it.toInt() }
        var a = ab
        if (ac < ab) a = ac;
        a--
        println(a.toString() + " " + (ab - a).toString() + " " + (ac - a).toString())
    }
}