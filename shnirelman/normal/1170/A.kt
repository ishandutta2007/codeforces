import java.util.*
import java.io.*

fun solve() {
    var (x, y) = readLine()!!.split(" ").map{it.toInt()}
    
    var a : Int = Math.min(x, y) - 1
    print("$a ${x - a} ${y - a}\n")
    
}

fun main(args : Array<String>) {
    var t : Int = readLine()!!.toInt()
    
    while(t-- > 0)
        solve()
}