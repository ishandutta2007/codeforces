import java.lang.Integer.*
import java.util.*
import kotlin.math.max

class pii {
    var f = 0
    var s = 0

    constructor(a : Int, b : Int) {
        f = a
        s = b
    }
}

class Man {
    var sum = 0
    var i = 0
    var b = 0
    var a = 0

    constructor(i1 : Int, a1 : Int, b1 : Int) {
        i = i1
        a = a1
        b = b1
        sum = i + b
    }
}

fun comp(a : Man, b : Man): Int {
    if(a.sum != b.sum)
        return if(a.sum < b.sum) -1 else 1;
    else
        return if(a.i < b.i) 1 else -1;
}

var INF = 1000000013 * 1L * 1000000013

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

var t = mutableListOf<Long>()
var a = mutableListOf<MutableList<Int>>()
var b = mutableListOf<MutableList<Int>>()

fun build(v : Int, l : Int, r : Int) {
    t[v] = -INF
    if(r - l == 1)
        return

    var m = (l + r) / 2

    build(v * 2 + 1, l, m)
    build(v * 2 + 2, m, r)
}

fun get(v : Int, l : Int, r : Int, ql : Int, qr : Int) : Long {
    if(l >= qr || r <= ql)
        return -INF

    if(ql <= l && r <= qr)
        return t[v]

    var m = (l + r) / 2
    return max(get(v * 2 + 1, l, m, ql, qr), get(v * 2 + 2, m, r, ql, qr))
}

fun update(v : Int, l : Int, r : Int, qi : Int, x : Long) {
    if(r - l == 1) {
        t[v] = max(t[v], x)
        return
    }

    var m = (l + r) / 2

    if(qi < m)
        update(v * 2 + 1, l, m, qi, x)
    else
        update(v * 2 + 2, m, r, qi, x)

    t[v] = max(t[v * 2 + 1], t[v * 2 + 2])
}

fun main(args : Array<String>) {
    var (n, m) = readLine()!!.split(" ").map({it.toInt()})

    var order = mutableListOf<Man>()

    for(i in 0 until n) {
        var k = readLine()!!.toInt()
        a.add(readLine()!!.split(" ").map({it.toInt()}).toMutableList())
        b.add(readLine()!!.split(" ").map({it.toInt()}).toMutableList())
        for(j in 0 until k) {
            order.add(Man(i, a[i][j], b[i][j]))
        }
    }

    order.sortWith(Comparator<Man>{s1, s2 ->  comp(s1, s2)})

    for(i in 0..(m * 4))
        t.add(0L)

    build(0, 0, m + 1)

    update(0, 0, m + 1, m, 0)

    var ans = 0L
    for(i in order.indices) if(order[i].sum >= m){
        var res = get(0, 0, m + 1, order[i].b, m + 1) + order[i].a
        update(0, 0, m + 1, order[i].b, res)
        ans = max(ans, res)
        //println("${order[i].i} ${order[i].a} ${order[i].b} $res")
    }

    println(ans)
}

/*fun main(args : Array<String>) {
    var (n, m) = readLine()!!.split(" ").map({it.toInt()})

    var cur = 0
    var a = mutableListOf<Int>()
    var ind = mutableListOf<Int>()

    var res = mutableListOf<Int>()

    var sum = 0

    for(i in 0 until n) {
        var (k, t) = readLine()!!.split(" ").map({it.toInt()})
        res.add(-1)

        if(t == 1) {
            res[i] = cur + 1
            cur += k
        } else {
            a.add(k)
            ind.add(i)
            sum += k
        }
    }

    m -= cur

    if(m < 0) {
        println(-1)
        return
    }

    var p = mutableListOf<MutableList<Int>>()
    for(i in 0..a.size) {
        p.add(mutableListOf<Int>())
        for(j in 0..m)
            p[i].add(-1)
    }

    p[0][0] = 0

    for(i in a.indices) {
        //println(i)
        for(j in p[i].indices) if(p[i][j] != -1) {
            //println("$i $j")
            p[i + 1][j] = 0
            if(j + a[i] <= m)
                p[i + 1][j + a[i]] = 1
        }
    }

    var x = -1
    for(i in 0..m) if(p[a.size][i] != -1 && i * 2 - 1 <= m && (sum - i) * 2 <= m) {
        x = i
    }

    //println("x $x")

    if(x == -1) {
        println(-1)
        return
    }

    var i = a.size
    var cur0 = cur + 2
    var cur1 = cur + 1
    while(i > 0) {
        if(p[i][x] == 0) {
            res[ind[i - 1]] = cur0
            cur0 += a[i - 1] * 2

        } else {
            res[ind[i - 1]] = cur1
            cur1 += a[i - 1] * 2
            x -= a[i - 1]
        }
        i--
    }

    for(r in res)
        print("$r ")

}*/

/*fun main(args : Array<String>) {
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
}*/

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