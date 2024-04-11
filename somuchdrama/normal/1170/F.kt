import java.io.*
import java.util.*
fun main(args: Array<String>) = bufferOut { readSolveWrite() }
private fun PrintWriter.readSolveWrite() {
    val (n,m,k)=readLine()!!.split(" ").map{it.toInt()}
    var a=readLine()!!.split(" ").map{it.toLong()}.toLongArray()
    val random = Random(228L)
    for(i in 0..n-1){
        val j=random.nextInt(i+1)
        val t=a[i]
        a[i]=a[j]
        a[j]=t
    }
    a=a.sortedArray()
    var p=LongArray(n+1)
    var ans=1000000000000000000L
    p[0]=0
    for(i in 1..n)p.set(i,p[i-1]+a[i-1])
    for(i in 0..n-m){
        val med=i+(m+1)/2-1
        val kek=a[med]*(med-i+1)-(p[med+1]-p[i])
        var opt=med
        var optval=a[med]
        if(kek>k){
            var l=i;
            var r=med;
            while(r-l>1){
                var mid=(l+r)/2
                val cur=a[mid]*(mid-i+1)-(p[mid+1]-p[i])
                if(cur>k)r=mid
                else l=mid
            }
            opt=l;
            var tl=a[opt]
            var tr=1000000000L
            if(opt+1<n)tr=a[opt+1]
            while(tr-tl>1){
                var mid=(tl+tr)/2
                val cur=mid*(opt-i+1)-(p[opt+1]-p[i])
                if(cur>k)tr=mid
                else tl=mid
            }
            optval=tl
        }
        var pl=optval*(opt-i+1)-(p[opt+1]-p[i])
        var pr=p[i+m]-p[opt+1]-optval*(i+m-opt-1)
        if(ans>pl+pr)ans=pl+pr
    }
    println(ans)
}
private fun bufferOut(block: PrintWriter.() -> Unit) = PrintWriter(System.out).use { block(it) }