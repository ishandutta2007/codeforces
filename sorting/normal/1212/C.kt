import java.util.*
import kotlin.math.*

val reader = Scanner(System.`in`)

fun main(){
    var n = reader.nextInt()
    var k = reader.nextInt()

    var a = IntArray(n)

    for(i in 0 until n){
        a[i] = reader.nextInt()
    }

    val rnd = Random(System.nanoTime())
    for(i in 0 until n){
        var j = rnd.nextInt(i + 1)
        var c = a[j]
        a[j] = a[i]
        a[i] = c
    }
    a.sort(0, n)

    if(k == 0){
        if(a[0] == 1){
            println("-1")
        }
        else{
            println("1")
        }

        return
    }
    if(k == n){
        println(a[n - 1])
        return
    }

    if(a[k] != a[k - 1]){
        println(a[k - 1])
    }
    else{
        println("-1")
    }

    return
}