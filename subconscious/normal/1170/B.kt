class seg(val l:Int,val r:Int,val key:Int)
fun gcd(x:Int,y:Int):Int{return if(y==0)x else gcd(y,x%y)}
fun raw()=readLine()!!
fun innum()=raw().toInt()
fun inlin()=(raw().split(" ").map{it.toInt()}).toIntArray()
fun main(){
    var n=innum()
    var a=inlin()
    var x=-1
    var y=-1
    var ans=0
    for(i in a){
        if(y>i)++ans
        if(x<i){
            y=x
            x=i
        }
        else if(y<i)y=i
    }
    println(ans)
}