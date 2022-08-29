class seg(val l:Int,val r:Int,val key:Int)
fun gcd(x:Int,y:Int):Int{return if(y==0)x else gcd(y,x%y)}
fun raw()=readLine()!!
fun innum()=raw().toInt()
fun inlin()=(raw().split(" ").map{it.toInt()}).toIntArray()
fun main(){
    var (n,m)=raw().split(" ").map{it.toInt()}
    var a=inlin()
    for(i in 1 until n)a[i]+=a[i-1]
    var q=innum()
    repeat(q){
        var b=inlin()
        var cur=0
        for(i in 0 until b[0]+1){
            var rm=0
            if(i==0)rm=b[1]-1
            else if(i==b[0])rm=m-b[b[0]]
            else rm=b[i+1]-b[i]-1
            //println(rm)
            var l=cur
            var r=n+1
            while(l+1<r){
                var mid=(l+r)/2
                if(a[mid-1]-(if(cur==0)0 else a[cur-1])<=rm)l=mid
                else r=mid
            }
            cur=l
        }
        if(cur==n)println("YES")
        else println("NO")
    }
}