import java.util.*
import kotlin.math.*

val reader = Scanner(System.`in`)
var mp = mutableMapOf<String, Int>()

fun main(){
    var n: Int = reader.nextInt()
    reader.nextLine()
    var s: String = reader.nextLine()
    var mx: Int = 0

    for(i in 1 until n){
        var curr: String = ""
        curr += s[i - 1]
        curr += s[i]

        mp[curr] = mp.getOrDefault(curr, 0) + 1
        mx = max(mp.getOrDefault(curr, 0), mx)
    }

    for(x in mp){
        if(x.value == mx){
            println("${x.key}")
            return
        }
    }
}