fun main() {
    var t = readLine()!!.toInt()
    for(q in 0..t - 1) {
        var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        var b = readLine()!!.split(" ").map({it.toInt()}).toMutableList()

        var ans = false

        ans = (ans || (a[0] == b[0] && a[1] + b[1] == a[0]))
        ans = (ans || (a[0] == b[1] && a[1] + b[0] == a[0]))
        ans = (ans || (a[1] == b[0] && a[0] + b[1] == a[1]))
        ans = (ans || (a[1] == b[1] && a[0] + b[0] == a[1]))

        println(if(ans) "Yes" else "No")
    }
}