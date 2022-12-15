import java.util.*
import kotlin.math.*
import kotlin.collections.*

val reader = Scanner(System.`in`)

fun findGcd(a: Long, b: Long):Long{
    if(b == 0L){
        return a
    }

    return findGcd(b, a % b)
}

fun main(){
    var n = reader.nextInt()
    var a = LongArray(n)

    for(i in 0 until n){
        a[i] = reader.nextLong()
    }

    var gcd = a[0]
    for(i in 1 until n){
        gcd = findGcd(gcd, a[i])
    }

    for(i in 0 until n){
        a[i] /= gcd
    }

    var p = mutableListOf<Pair<Int, Int>>()
    var ans = LongArray(n)

    var mx = 0
    for(i in 0 until n){
        var pow2 = 0
        var pow3 = 0
        var x = a[i]

        while(x % 3L == 0L){
            pow3++
            x /= 3L
        }
        while(x % 2L == 0L){
            pow2++
            x /= 2L
        }

        p.add(Pair(pow2, pow3))
        mx = max(mx, pow3)
    }

    for(i in 0 until n){
        ans[p[i].first + mx - p[i].second] = a[i]
    }

    for(i in 0 until n){
        print("${ans[i] * gcd} ")
    }
    println()

    return
}