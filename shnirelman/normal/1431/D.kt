const val INF : Int = 1000000000

fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(q in 0..(t - 1)) {
        var n = readLine()!!.toInt()
        var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()

        var b : MutableList<Pair<Int, Int>> = mutableListOf<Pair<Int, Int>>()
        //b.add(Pair<Int, Int>(2, 2))
        for(i in 0..n - 1)
            b.add(Pair<Int, Int>(a[i], i))

        b.sortBy { -it.first }
        
        
        //println(b)

        var l = 0
        var r = n - 1
        var cur = 0

        var ans : MutableList<Int> = mutableListOf<Int>()

        while(l <= r) {
            if(b[r].first <= cur) {
                ans.add(b[r].second)
                cur = 1
                r--
            } else {
                ans.add(b[l].second)
                cur++
                l++
            }
            
        }

        for(i in ans)
            print("${i + 1} ")
        println()
    }
}