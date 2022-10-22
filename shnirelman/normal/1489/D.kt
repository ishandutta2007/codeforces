import java.util.*
import java.lang.*
import java.lang.Long.*

fun main(args : Array<String>) {
    var n = readLine()!!.toInt()

    var a = mutableListOf<String>()
    for(i in 0..n - 1) {
        a.add(readLine()!!)
    }
    a.sortWith(Comparator<String> { s1, s2 -> if(s1.length > s2.length)  1 else
        if(s1.length < s2.length) -1 else 0})


    var ans = true
    for(i in 0..n - 2) {
        var res = false
        for(j in 0..a[i + 1].length - a[i].length) {
            if(a[i + 1].substring(j, j + a[i].length) == a[i]) {
                res = true
            }
        }

        if(!res)
            ans = false
    }

    if(ans) {
        print("YES\n")
        for(s in a)
            println(s)
    } else {
        print("NO\n")
    }
    //a.sortWith(Comparator<String> { s1, s2 -> s1.length.compareTo(s2.length)})

    /*var n = readLine()!!.toInt()
    var s = readLine()!!

    var ans = 0
    var cur = 0
    for(i in 0..n - 1) {
        if(s[i] == 'x') {
            cur++
            if(cur >= 3)
                ans++
        } else {
            cur = 0
        }
    }

    print("$ans")*/

    /*var q = readLine()!!.toInt()

    for(ind in 0..q - 1) {
        var x = readLine()!!.split(" ").map( {it.toLong()} )
        var n = x[0]
        var a = x[1]
        var b = x[2]

        var ans : Long = 0

        if(a * 2 < b)
            ans = n * a
        else
            ans = n / 2 * b + n % 2 * a

        print("$ans \n")
    }*/

    /*var n = readLine()!!.toInt()

    var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()

    var st = TreeSet<Int>()

    var x : Int = 0

    var ans = mutableListOf<Int>()

    //var ans = MutableList<Int>(0, x)

    var i = n - 1

    while(i >= 0) {
        //print(i)
        if(!st.contains(a[i])) {
            ans.add(a[i])
            st.add(a[i])
        }
        i--
    }

    print("${ans.size} \n")
    i = ans.size - 1
    while(i >= 0) {
        print("${ans[i]} ")
        i--
    }*/
}