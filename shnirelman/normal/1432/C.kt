fun main() {
    var t = readLine()!!.toInt()
    for(i in 0..t - 1) {
        var n = readLine()!!.toInt()
        
        var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        
        var s = 0
        for(x in a)
            s += x
            
        println("${(s + n - 1) / n}")
        
    }
}