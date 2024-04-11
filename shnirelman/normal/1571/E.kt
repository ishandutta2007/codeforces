import java.lang.Integer.*
import java.util.*

class pii {
    var f = 0
    var s = 0

    constructor(a : Int, b : Int) {
        f = a
        s = b
    }
}

var INF = 1000000013

/*
1
4
))((
0

1
4
))((
1

1
4
()()
0
 */

fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(case in 0 until t) {
        var n = readLine()!!.toInt()
        var s = readLine()!!
        var a = readLine()!!

        var dp = mutableListOf<MutableList<Int>>()
        for(i in 0..(n - 2)) {
            dp.add(mutableListOf<Int>())
            for(j in 0..8) {
                dp[i].add(INF)
            }
        }

        for(mask in 0..7) {
            dp[0][mask] = 0
            var bt = mutableListOf<Int>(mask / 4, mask / 2 % 2, mask % 2)
            for(i in 0..2) {
                if(bt[i] != (s[i] - '(')) {
                    //println("$mask ${bt[i]} ${s[i] - '0'}")
                    dp[0][mask]++
                }
            }
        }

        var good = mutableListOf<Boolean>()
        for(i in 0..15) {
            good.add(true)
            var bt = mutableListOf<Int>(i / 8, i / 4 % 2, i / 2 % 2, i % 2)

            var cur = 0
            for(j in 0..3) {
                cur += if(bt[j] == 0) 1 else -1
                if(cur < 0)
                    good[i] = false
            }

            if(cur != 0)
                good[i] = false

            //println("$i ${good[i]}")
        }

        for(i in 0..(n - 4)) {
            for(mask in 0..7) {
                var bt = mutableListOf<Int>(mask / 4, mask / 2 % 2, mask % 2)
                for(x in 0..1) {
                    var nmask = mask % 4 * 2 + x

                    if(a[i] == '1' && !good[mask * 2 + x])
                        continue

                    dp[i + 1][nmask] = min(dp[i + 1][nmask], dp[i][mask] + (if(s[i + 3] - '(' != x) 1 else 0))

                    //println("${i + 1} $nmask ${dp[i + 1][nmask]} $mask ${dp[i][mask]}")
                }
            }
        }

        var ans = INF
        for(i in 0..7)
            ans = min(ans, dp[n - 3][i])

        println("${if(ans < INF) ans else -1}")
    }
}

/*fun main(args : Array<String>) {
    var (n, m) = readLine()!!.split(" ").map({it.toInt()})

    var fir = mutableListOf<Int>()
    var lst = mutableListOf<Int>()
    var both = mutableListOf<MutableList<Int>>()
    for(i in 0 until n) {
        fir.add(0)
        lst.add(0)
        both.add(mutableListOf())
        for(j in 0 until n) {
            both[i].add(0)
        }
    }

    var x = 0
    var y = 0

    for(ii in 0 until m) {
        var (f, l) = readLine()!!.split(" ").map({it.toInt()})

        f--
        l--

        if(ii == 0) {
            x = f
            y = l
        }

        both[f][l]++
        fir[f]++
        lst[l]++
    }

    var ans = 1

    for(i in 0 until n) {
        for(j in 0 until n) if(i != j) {
            if(i == x && j == y)
                ans = max(ans, 1)
            else if(i == x || j == y)
                ans = max(ans, both[i][j] + 1)
            else
                ans = max(ans, fir[i] + lst[j] - both[i][j] + 1)
            //println("$i $j $ans")
        }
    }

    println(ans)
}*/

/*fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(case in 0 until t) {
        var n = readLine()!!.toInt()

        var lf = 0
        var rg = 1000000

        for(ii in 0 until n) {
            var (s, t, r) = readLine()!!.split(" ")

            if(r == "1") {
                var i = s.length - 1
                var j = t.length - 1
                while(i >= 0 && j >= 0 && s[i] == t[j]) {
                    i--
                    j--
                }

                var k = s.length - i - 1
                rg = min(rg, k)
            } else {
                var i = s.length - 1
                var j = t.length - 1
                while(i >= 0 && j >= 0 && s[i] == t[j]) {
                    i--
                    j--
                }

                var k = s.length - i - 1
                lf = max(lf, k + 1)
            }
        }

        println(max(0, rg - lf + 1))
        for(i in lf..rg) {
            print("$i ")
        }
        println()
    }
}*/

/*fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(case in 0 until t) {
        var n = readLine()!!.toInt()
        var (a, x) = readLine()!!.split(" ").map({it.toInt()})
        var (b, y) = readLine()!!.split(" ").map({it.toInt()})

        var c = readLine()!!.toInt()

        var res = min(x + c - a, y)

        println(res)
    }
}*/

/*fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(case in 0 until t) {
        var s = readLine()!!
        var a = true
        var b = true
        for(c in s) {
            if(c == '<')
                a = false
            else if(c == '>')
                b = false
        }

        var res = "?"

        if(a && b)
            res = "="
        else if(a)
            res = ">"
        else if(b)
            res = "<"
        else
            res = "?"

        println("$res")
    }
}*/