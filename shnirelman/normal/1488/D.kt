import java.util.*
import java.lang.*
import java.lang.Integer.*


fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(ind in 0..t - 1) {
        var a = readLine()!!.split(' ').map({it.toLong()}).toMutableList()
        var n = a[0]
        var s = a[1]

        var l = 1L
        var r = s + 1
        while(r - l > 1) {
            var m = (l + r) / 2

            var s1 = 0L
            var i = 0
            var cur = m
            while(i < n && cur > 1) {
                s1 += cur
                cur = (cur + 1) / 2
                i++
            }

            if(s1 + n - i > s)
                r = m
            else
                l = m
        }

        println("$l")
    }
    /*var t = readLine()!!.toInt()
    for(ind in 0..t - 1) {
        var a = readLine()!!.split(' ').map({it.toInt()}).toMutableList()
        var n = a[0]
        var x = a[1]
        var y = a[2]
        if(x > y) {
            var z = x
            x = y
            y = z
        }

        var ans = n * 2
        for(z in x + 1..y) {
            ans = min(ans, max(min(z - x - 1 + z - 2, x - 1 + z - 2), min(y - z + n - z, n - y + n - z)))
        }

        println("$ans")
    }*/
    /*var t = readLine()!!.toInt()
    for(ind in 0..t - 1) {
        var a = readLine()!!.split(' ').map({it.toInt()}).toMutableList()
        var n = a[0]
        var k = a[1]

        var s = readLine()!!

        var cur = 0
        var ans = 0
        var len = 0
        for(i in 0..n - 1) {
            cur += if(s[i] == ')')  1 else -1
            len++
            if(cur == 0) {
                var d = min(k, (len - 2) / 2)
                k -= d
                ans += d
                ans++
                len = 0
            }
        }

        println("$ans")
    }*/
    /*var t = readLine()!!.toInt()
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
    }*/

}