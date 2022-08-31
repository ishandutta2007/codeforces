fun main(){
    val (a,b,c)=readLine()!!.split(" ").map{it.toInt()}
    val ans=minOf(a,b-1,c-2)
    println(ans*3+3)
}