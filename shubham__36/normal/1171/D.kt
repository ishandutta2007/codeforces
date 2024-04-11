fun main(args: Array<String>) {
//    val t = readLine()!!.toInt()
    val t = 1
    repeat(t){
        val (x,y,z) = readLine()!!.split(" ").map { it.toInt() }
        val (a,b,c) = readLine()!!.split(" ").map { it.toInt() }
        if((a>=x) and ((a+b)>=(x+y)) and ((a+b+c)>=(x+y+z))){
            println("YES")
        }
        else{
            println("NO")
        }
    }
}