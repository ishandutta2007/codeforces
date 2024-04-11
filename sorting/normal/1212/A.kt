import java.util.*
import kotlin.math.*

val reader = Scanner(System.`in`)

fun main(){
    var n: Int = reader.nextInt()
    var k: Int = reader.nextInt()

    repeat(k){
        if(n % 10 > 0){
            --n
        }
        else{
            n /= 10
        }
    }

    println("$n")

    return
}