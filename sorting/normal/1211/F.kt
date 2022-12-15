import java.util.*
import kotlin.math.*

val reader = Scanner(System.`in`)

const val word = "kotlin"

fun main(){
    var n = reader.nextInt()
    val where = IntArray(256)
    for(i in 0 until 6){
        where[word[i].toInt()] = i
    }

    var e = Array<Array<MutableList<Int>>>(6){_ -> Array(6){_ -> mutableListOf<Int>()} }
    var cnt = Array<IntArray>(6){_ -> IntArray(6){_ -> 0}}

    for(i in 0 until n){
        var s = reader.next()
        val from = where[s[0].toInt()]
        val to = (where[s.last().toInt()] + 1) % 6

        e[from][to].add(i)
        cnt[from][to]++
    }


    var st = mutableListOf<Int>()
    var pr = -1
    st.add(0)

    var ans = mutableListOf<Int>()

    while(st.isNotEmpty()){
        var u = st.last()
        var ok = false

       // println("$u -u")
        //println(st.size)

        for(to in 0 until 6){
            if(cnt[u][to] > 0){
                st.add(to)
                //print("${e[u][to].last() + 1} ")
                //e[u][to].dropLast(1)
                cnt[u][to]--
                //print(cnt[u][to])
                ok = true
                break
            }
        }

       // println(st.size)

        if(!ok){
            if(pr != -1){
                ans.add(e[u][pr].last() + 1)
                e[u][pr].removeAt(e[u][pr].size - 1)
            }
            pr = u
            st.removeAt(st.size - 1)
            //println("$pr - pr")
        }
    }

    for(x in ans.reversed()){
        print("$x ")
    }
    println()

    return
}