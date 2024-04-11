fun main(args: Array<String>){
    val t=readLine()!!.toInt()
    repeat(t){
        val (x,y)=readLine()!!.split(" ").map{it.toInt()}
        val b=minOf(x,y)-1;
        val a=x-b;
        val c=y-b;
        println("$a $b $c")
    }
}