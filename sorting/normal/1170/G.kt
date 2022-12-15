import java.util.*
import kotlin.math.*

val reader = Scanner(System.`in`)

fun main(){
    val n = reader.nextInt()
    val m = reader.nextInt()

    var adj = Array(n) { mutableSetOf<Pair<Int, Int>>()}
    for(i in 0 until m){
        var u: Int = reader.nextInt()
        var v: Int = reader.nextInt()

        adj[u - 1].add(Pair(i, v - 1))
        adj[v - 1].add(Pair(i, u - 1))
    }

    var ans = mutableListOf<List<Int>>()
    for(i in 0 until n){
        if(adj[i].isNotEmpty()){
            val curr = mutableListOf<Int>(i)
            var idx  = mutableSetOf<Int>(i)

            while (true){
                var u = curr.last()
                if(adj[u].isEmpty()){
                    if(curr.size == 1)
                        break

                    println("NO")
                    return
                }

                var p = adj[u].first()
                val v = p.second
                if(v == u){
                    adj[u].remove(p)
                    ans.add(listOf(u, u));
                    continue
                }

                adj[u].remove(p)
                adj[v].remove(Pair(p.first, u))

                if(idx.contains(v)){
                    var mine = mutableListOf<Int>(v)

                    do {
                        mine.add(curr.last())
                        idx.remove(curr.last())
                        curr.removeAt(curr.size - 1)
                    }while(curr.last() != v)

                    mine.add(v)
                    ans.add(mine)
                }
                else{
                    curr.add(v)
                    idx.add(v)
                }
            }
        }
    }

    println("YES")
    println(ans.size)
    for(x in ans){
        print("${x.size} ")
        for(y in x){
            print("${y + 1} ")
        }
        println()
    }

    return
}