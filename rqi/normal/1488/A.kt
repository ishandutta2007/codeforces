fun nextInt() = readLine()!!.toInt()
fun nextInts() = readLine()!!.split(" ").map { it.toInt() }
 
fun main(args: Array<String>) {
    val t = nextInt()
    for(T in 1..t) {
        var(x, y) = nextInts()
        var ans = y%x
        y = y/x
        for(i in 0..9){
            ans = ans+y%10
            y = y/10
        }
        println(ans)
    }
}