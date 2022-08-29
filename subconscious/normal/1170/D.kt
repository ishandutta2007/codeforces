class seg(val l:Int,val r:Int,val key:Int)
fun gcd(x:Int,y:Int):Int{return if(y==0)x else gcd(y,x%y)}
fun raw()=readLine()!!
fun innum()=raw().toInt()
fun inlin()=(raw().split(" ").map{it.toInt()}).toIntArray()
var f=Array(300005){i->i}
fun fa(x:Int):Int{
    if(x==f[x])return x
    else{
        f[x]=fa(f[x])
        return f[x]
    }
}
fun main(){
    var n=innum()
    var a=inlin()
    var tot=0
    var num=Array(n){0}
    var ans=Array(n){mutableListOf<Int>()}
    for(i in a)if(i==-1)++tot
    for(i in 0 until tot)f[i]=i
    var cur=0;
    for(i in a){
        ans[cur].add(i)
        ++num[cur]
        if(i==-1){
            var x=fa((cur+1)%tot)
            f[cur]=x
        }
        cur=fa((cur+1)%tot)
    }
    println(tot)
    for(i in 0 until tot){
        print("${num[i]-1}")
        for(j in 0 until num[i]-1)
            print(" ${ans[i][j]}")
        println("")
    }
}