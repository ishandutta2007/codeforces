import java.util.*

const val INF : Int = 1000000000

fun main(args : Array<String>) {
    
    //println(c)
    //return
    var t = 1//readLine()!!.toInt()
    for(q in 0..(t - 1)) {
        var b = readLine()!!.split(" ").map({it.toInt()}).toMutableList()
        var n = b[0]
        var k = b[1]
        var x = b[2]

        var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()

        var l = -1L
        var r = 10000000002L
        while(r - l > 1) {
            var m = (l + r) / 2
            
            //println("$l $m $r")

            var s = 0L
            var del = 0
            /*var c = TreeSet<Pair<Int, Int>>((Comparator<Pair<Int, Int>> { s1, s2 ->
                 s1.first .compareTo(s2.first)
              }))*/
            var c = TreeSet<Pair<Int, Int>>((Comparator<Pair<Int, Int>> { s1, s2 ->
                 (s1.first.toLong() * 100000L + s1.second) 
                 .compareTo(s2.first.toLong() * 100000L + s2.second)
              }))  
             
            for(i in 0..n - 1) {
               /* if(m == 11L) {
                    println(c)
                    print(Pair<Int, Int>(a[i], i))
                }*/
                    
                c.add(Pair<Int, Int>(a[i], i))
                s += a[i]
                //if(m == 11L)
                //    println(c)
                if(c.size > x) {
                    s -= c.last().first
                    del++
                    c.remove(c.last())
                }
                 
                if(c.size == x) {
                    if(s <= m) {
                        s = 0
                        while(!c.isEmpty())
                            c.remove(c.first())
                    } 
                    
                }
                
                /*if(m == 11L) {
                    println("$i $s $x ${c.size}")
                    //println(c)
                }*/
            }
            
            while(!c.isEmpty() && s > m) {
                s -= c.last().first
                del++
                c.remove(c.last())
            }
            
            if(k >= del)
                r = m
            else
                l = m
        }
        print("$r \n")
    }
}