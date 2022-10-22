fun main() {
    var t = readLine()!!.toInt()
    for(i in 0..t - 1) {
        var x  = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        var n = x[0]
        var a = x[1]
        var b = x[2]
        
        var s = ""
        for(i in 0..a - b - 1)
            s += "a"
            
        //var y = 'a' + 2
       // println("$y")

        for(i in 0..b - 1)
            s += ('a' + i)
        
        //println("s: " + s)
            
        for(i in 0..n - 1)
            print(s[i % a])
        println()
    }
}