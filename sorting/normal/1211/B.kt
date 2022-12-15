import java.util.*
import kotlin.math.*

val reader = Scanner(System.`in`)

fun main(){
    var n = reader.nextLong()

    var ans: Long = 0L
    for(i in 0 until n){
        var x = reader.nextLong()

        ans = max(ans,  (x - 1) * n + i + 1)
    }

    println(ans)

    return
}