import java.util.*;



fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(ind in 0..t - 1) {
        var a = readLine()!!.split(' ').map({it.toInt()}).toMutableList()
        var x = a[0]
        var y = a[1]

        var ans = 0
        while(y > 0) {
            var x1 = x
            while(x1 * 10L <= y)
                x1 *= 10
            //println("$y $x1")
            if(x1 <= y) {
                y -= x1
                ans++
            } else {
                ans += y
                break
            }
        }

        println("$ans")
    }

}