import java.util.Scanner

const val MAXN: Int = 200007
val reader = Scanner(System.`in`)

fun main(){
    var n: Int = reader.nextInt()
    var max1 : Int = 0
    var max2: Int = 0

    var ans: Int = 0

    for(i in  1..n){
        val x: Int = reader.nextInt()
        if(x < max2) {
            ++ans
        }

        if(x > max1){
            max2 = max1
            max1 = x
        }
        else {
            if(x > max2){
                max2 = x
            }
        }
    }

    println("$ans")
}