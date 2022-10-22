import java.util.*

const val INF : Int = 1000000000

fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(q in 0..(t - 1)) {
        var n = readLine()!!.toInt()
        var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        var b = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        
        var res = -1
        var ans : MutableList<Int> = mutableListOf<Int>()
        for(i in 0..n) {
            var r = INF
            for(j in 0..i - 1)
                r = Math.min(r, Math.abs(a[j] - b[n - i + j]))
            for(j in i..n - 1)
                r = Math.min(r, Math.abs(a[j] - b[j - i]))
                
            //println("$i $r")
            
            if(r > res) {
                res = r
                while(!ans.isEmpty())
                    ans.removeLast()
                for(j in 0..i - 1)
                    ans.add(n - i + j)
                for(j in i..n - 1)
                    ans.add(j - i)
            }
        }
        
        for(x in ans)
            print("${x + 1} ")
        println()
    }
}