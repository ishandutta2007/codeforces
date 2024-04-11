class seg(val l:Int,val r:Int,val key:Int)
fun gcd(x:Int,y:Int):Int{return if(y==0)x else gcd(y,x%y)}
fun raw()=readLine()!!
fun innum()=raw().toInt()
fun inlin()=(raw().split(" ").map{it.toInt()}).toIntArray()
fun main(){
    var t=innum()
    repeat(t){
        var a=inlin()
        var x=minOf(a[0],a[1])-1
        println("${x} ${a[0]-x} ${a[1]-x}")

    }
}