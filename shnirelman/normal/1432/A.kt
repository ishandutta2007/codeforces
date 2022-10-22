fun main() {
    var t = readLine()!!.toInt()
    for(i in 0..t - 1) {
        var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        println("${a[0] + a[1]}")
    }
}