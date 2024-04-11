fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map {x -> x.toInt()}
    var f = Array<Int>(n, {0})
    var inc = -1
    var dec = 10000000
    for (i in 0..n-1) {
        if (inc < a[i] && (a[i] >= dec || (i + 1 < n && a[i] < a[i + 1]))) {
            inc = a[i]
            f[i] = 0
        } else if (a[i] < dec) {
            dec = a[i]
            f[i] = 1
        } else {
            println("NO")
            return
        }
    }
    println("YES")
    for (i in 0 ..n-1) {
        print(f[i])
        print(" ")
    }
    println("")
}