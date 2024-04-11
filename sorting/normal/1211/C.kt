import java.util.*
import kotlin.math.*
import java.math.BigInteger

val reader = Scanner(System.`in`)

fun main(){
    var n = reader.nextInt()
    var k = reader.nextLong()

    var p = MutableList<Pair<Long, Long>>(n){_ -> Pair<Long, Long>(0L, 0L)}
    var ans: Long = 0L

    for(i in 0 until n){
        var a = reader.nextLong()
        var b = reader.nextLong()
        var c = reader.nextLong()

        k -= a
        ans += c * a
        p[i] = Pair(c, b - a)

        if(k < 0){
            break
        }
    }

    val rng = Random(System.nanoTime())
    for(i in 0 until n){
        var j = rng.nextInt(i + 1)
        var t = p[i]
        p[i] = p[j]
        p[j] = t
    }
    p = p.sortedWith(compareBy({ it.first }, { it.second })).toMutableList()

    for(i in 0 until n){
        if(k <= 0){
            break
        }

        if(p[i].second >= k) {
            ans += p[i].first * k
            k = 0
        }
        else{
            ans += p[i].first * p[i].second
            k -= p[i].second
        }
    }

    if(k != 0L){
        println("-1")
    }
    else {
        println(ans)
    }
}