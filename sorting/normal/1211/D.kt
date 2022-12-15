import java.util.*
import kotlin.math.*

val reader = Scanner(System.`in`)
const val R = 1000007

var arr = LongArray(R){_ -> 0L}

fun main(){
    var n = reader.nextInt()
    var a = reader.nextLong()
    var b = reader.nextLong()
    var k = reader.nextInt()

    for(i in 0 until n){
        var x = reader.nextInt()
        ++arr[x]
    }

    var ans: Long = 0L

    if(a < b) {
        for (i in R - 1 downTo 0) {
            if (i % k == 0) {
                var mn = min(arr[i / k] / a, arr[i] / b)
                arr[i / k] -= mn * a
                arr[i] -= mn * b
                ans += mn
            }
        }
    }
    else{
        for (i in 0 until R) {
            if (i % k == 0) {
                var mn = min(arr[i / k] / a, arr[i] / b)
                arr[i / k] -= mn * a
                arr[i] -= mn * b
                ans += mn
            }
        }
    }

    println(ans)

    return
}