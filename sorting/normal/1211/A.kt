import java.util.*
import kotlin.math.*

val reader = Scanner(System.`in`)

fun main(){
    var n = reader.nextInt()
    var arr = IntArray(n + 1)
    arr[0] = 0

    var a = 0; var b = 0; var c = 0
    for(i in 1 until n + 1){
        var x = reader.nextInt()
        arr[i] = x

        if(x == arr[a] || x == arr[b] || x == arr[c]){
            continue
        }

        if(x > arr[c]){
            a = b;
            b = c;
            c = i;
        }
        else{
            if(x > arr[b]){
                a = b;
                b = i;
            }
            else{
                if(x > arr[a]){
                    a = i;
                }
            }
        }
    }

    if(arr[a] == 0){
        println("-1 -1 -1")
    }
    else{
        println("$a $b $c")
    }

    return
}