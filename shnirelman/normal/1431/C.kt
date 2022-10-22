const val INF : Int = 1000000000

fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(q in 0..(t - 1)) {
        var b = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        var n = b[0]
        var k = b[1]
        var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        
        var s = mutableListOf(0)
        for(i in 1..n)
            s.add(s[i - 1] + a[i - 1])
        var ans = 0
        var i = n - 1
        while(i >= 0) {
            var cnt = (n - i) / k
            ans = Math.max(ans, s[i + cnt] - s[i])
            i--
        }
        
        print("$ans \n")
    }
}