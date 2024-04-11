fun main() {
    var n = readLine()!!.toInt() // read integer from the input
    var a = readLine()!!.split(" ").map { it.toInt() }
    var i = 0
    var mx1 = -1
    var mx2 = -1
    var ans = 0
    while (i < n) {
        if (a[i] < mx1) ans++
        if (a[i] > mx2) {
            mx1 = mx2
            mx2 = a[i]
        } else if (a[i] > mx1) mx1 = a[i]
        i++
    }
    println(ans)
}