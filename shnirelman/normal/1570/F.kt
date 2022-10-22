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

fun main(args : Array<String>) {
    var (n, m) = readLine()!!.split(" ").map({it.toInt()})

    var a = mutableListOf<MutableList<Int>>()
    var b = mutableListOf<MutableList<Int>>()
    for(i in 0 until n) {
        a.add(readLine()!!.split(" ").map({it.toInt()}).toMutableList())
    }

    for(i in 0 until n) {
        b.add(mutableListOf())
        for(j in 0 until m) {
            b[i].add(0)
        }
    }

    var res = mutableListOf<pii>()
    for(i in 0..n - 2) {
        for(j in 0..m - 2) {
            if(a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1) {
                res.add(pii(i, j))
                b[i][j] = 1
                b[i + 1][j] = 1
                b[i][j + 1] = 1
                b[i + 1][j + 1] = 1
            }
        }
    }

    if(a != b) {
        println("-1")
    } else {
        println(res.size)
        for(p in res) {
            println("${p.f + 1} ${p.s + 1}")
        }
    }
}

/*fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(_case in 1..t) {
        var s = readLine()!!

        var fir = -1
        var lst = -1
        var cnt = 0
        for(i in s.indices) {
            if(s[i] == '1') {
                if(fir == -1)
                    fir = i
                lst = i
                cnt++
            }
        }

        println("${ if(fir == -1) 0 else (lst - fir + 1 - cnt) }")
    }
}*/

/*fun get(n : Int) : Int {
    var x = n + 1
    while(x % 10 == 0)
        x /= 10
    return x
}

fun main(args : Array<String>) {
    var n = readLine()!!.toInt()

    var st = TreeSet<Int>()

    while(!st.contains(n)) {
        st.add(n)
        n = get(n)
    }

    println("${st.size}")
}*/

/*fun comp(a : pii, b : pii): Int {
    if(a.f != b.f)
        return if(a.f < b.f) 1 else -1;
    else
        return if(a.s < b.s) -1 else 1;
}

fun main(args : Array<String>) {
    var n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map( { it.toInt() } )

    var b = mutableListOf<pii>()
    for(i in 0 until n) {
        b.add(pii(a[i], i))
    }
    //b.sortBy{ -it.f }

    b.sortWith(Comparator<pii>{s1, s2 ->  comp(s1, s2)})

    var ans = n
    for(i in 0 until n) {
        ans += i * b[i].f
    }

    println("$ans")
    for(i in 0 until n) {
        print("${b[i].s + 1} ")
    }
    //b.sortWith()
    //var b = Array<pii>(n, pii(0, 0))

}*/

/*fun main(args : Array<String>) {
    var a1 = readLine()!!.toInt()
    var a2 = readLine()!!.toInt()
    var k1 = readLine()!!.toInt()
    var k2 = readLine()!!.toInt()
    var n = readLine()!!.toInt()

    if(k1 < k2) {
        a1 += a2
        a2 = a1 - a2
        a1 -= a2

        k1 += k2
        k2 = k1 - k2
        k1 -= k2
    }

    var mx = 0

    if(n >= a2 * k2)
        mx = a2 + (n - a2 * k2) / k1
    else
        mx = n / k2


    var mn = max(0, n - a2 * (k2 - 1) - a1 * (k1 - 1))

    println("$mn $mx")
}*/

/*fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(_case in 1..t) {
        var (a, b) = readLine()!!.split(" ").map({it.toInt()})
        println("${a + b}")
    }
}*/