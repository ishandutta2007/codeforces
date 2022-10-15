fun main(args: Array<String>) {
    val (a,b,c)=readLine()!!.split(" ").map{it.toInt()}
    println(minOf(a,b-1,c-2)*3+3)
}