class seg(val l:Int,val r:Int,val key:Int)
fun gcd(x:Int,y:Int):Int{return if(y==0)x else gcd(y,x%y)}
fun rd() = readLine()!!
fun rdnum() = rd().toInt()
fun rdlin() = rd().split(' ').map{it.toLong()}.toMutableList()
fun main(){
    var (n,m,k)=rdlin()
    var a=rdlin()
    a.add(0)
    a.sort()
    var s=Array(n.toInt()+1){0L}
    for(i in 1 until n.toInt()+1)s[i]=s[i-1]+a[i]
    var ls=1
    var ans=1000000000000000001L
    for(i in 1 until (n-m).toInt()+2){
        var L=maxOf(i,ls)
        var R=i+m.toInt()/2
        while(L<R){
            var mid=(L+R+1)/2
            if((mid-i+1)*a[mid]-(s[mid]-s[i-1])<=k)L=mid else R=mid-1
        }
        var tmp=L
        ls=L
        var ll=a[tmp]
        if(tmp!=i+m.toInt()/2){
            var rr=a[tmp+1]
            while(ll<rr){
                var mid=(ll+rr+1)/2
                if((tmp-i+1)*mid-(s[tmp]-s[i-1])<=k)ll=mid else rr=mid-1
            }
        }
        var now0=(tmp-i+1)*ll-(s[tmp]-s[i-1])
        var now1=(s[i+m.toInt()-1]-s[tmp])-(i+m-1-tmp)*ll
        ans = minOf(ans,now0+now1)
    }
    println(ans)
}