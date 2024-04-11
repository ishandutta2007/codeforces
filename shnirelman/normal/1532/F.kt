import java.util.*


fun main(args : Array<String>) {
    var n = readLine()!!.toInt()
    var s = MutableList<String>(n * 2 - 2) {i -> ""}

    var mx = mutableListOf<String>()
    for(i in 0..n * 2 - 3) {
        s[i] = readLine()!!
        if(s[i].length == n - 1) {
            mx.add(s[i])
        }
    }

    var str = listOf<String>(mx[0] + mx[1][n - 2], mx[1] + mx[0][n - 2])

    for(t in str) {
        //println(t)
        var fl = false
        var res = IntArray(n * 2 - 2)
        var pr = IntArray(n - 1) {i -> 0}
        var suf = IntArray(n - 1) {i -> 0}

        for(i in 0..n * 2 - 3) {
            var p = true
            for(j in 0 until s[i].length) {
                if(t[j] != s[i][j]) {
                    p = false
                    break
                }
            }

            if(p && pr[s[i].length - 1] == 0) {
                res[i] = 0
                pr[s[i].length - 1] = 1
                continue
            }

            var sf = true
            for(j in 0 until s[i].length) {
                if(t[n - s[i].length + j] != s[i][j]) {
                    sf = false
                    break
                }
            }

            if(sf && suf[s[i].length - 1] == 0) {
                res[i] = 1
                suf[s[i].length - 1] = 1
                continue
            }

            fl = true
            break
        }

        if(!fl) {
            for(i in 0..n * 2 - 3)  {
                print("${if(res[i] == 0) 'P' else 'S'}")
            }
            return
        }
    }

    /*var n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map({it.toInt()}).toIntArray()

    var mx1 = 0
    var mx2 = 0
    var s = 0L

    for(i in 0 until n) {
        if(mx1 < a[i]) {
            mx2 = mx1
            mx1 = a[i]
        } else if(mx2 < a[i]) {
            mx2 = a[i]
        }

        s += a[i]
    }

    var ans = mutableListOf<Int>()
    for(i in 0 until n) {
        var x = if (a[i] == mx1) mx2 else mx1
        if(x * 1L == s - x - a[i]) {
            ans.add(i)
        }
    }

    println("${ans.size}")
    for(i in ans)
        print("${i + 1} ")
    */

    /*var n = readLine()!!.toInt()
    var a = readLine()!!.split(' ').map({it.toInt()}).toIntArray()

    a.sort()

    /*for(i in 0 until n) {
        print("${a[i]}")
    }
    println()*/

    var ans = 0
    var i = 0
    while(i < n) {
        ans += a[i + 1] - a[i]
        i += 2
    }

    println("$ans")*/

    /*var t = readLine()!!.toInt()
    for(ind in 0 until t) {
        var (n, k) = readLine()!!.split(' ').map({it.toInt()})
        for(i in 0 until n) {
            print("${'a' + i % k}")
        }
        println()
    }*/

    /*var t = readLine()!!.toInt()
    for(ind in 0 until t) {
        var (a, b, k) = readLine()!!.split(' ').map({it.toInt()})
        println("${(k + 1) / 2 * 1L * a - k / 2 * 1L * b}")
    }*/

    /*var t = readLine()!!.toInt()
    for(ind in 0 until t) {
        var (a, b) = readLine()!!.split(' ').map({it.toInt()})
        println("${a + b}")
    }*/
}