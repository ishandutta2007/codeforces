fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    for (case in 1..t) {
        var n = readLine()!!.toInt()
        var a = readLine()!!.split(" ").map {x -> x.toInt()}
        var found = false
        for (i in 1..n-2) {
            if (a[i] != a[i - 1] && a[i] != a[i + 1]) {
                println(i + 1)
                found = true
                break
            }
        }
        if (!found) {
            println(if (a[0] != a[1] && a[1] == a[n - 1]) 1 else n )
        }
    }
}