fun main(args: Array<String>){
    val (n,m)=readLine()!!.split(" ").map{it.toInt()}
    val a=readLine()!!.split(" ").map{it.toInt()}
    var p=IntArray(n+1)
    val q=readLine()!!.toInt()
    p[0]=0
    for(i in 1..n)p[i]=p[i-1]+a[i-1]
    repeat(q){
        var w=readLine()!!.split(" ").map{it.toInt()}.toIntArray()
        val g=w[0]
        w[0]=0
        w+=m+1
        var ptr=1;
        for(pos in 0..g){
            if(ptr==n+1)break;
            val len=w[pos+1]-w[pos]-1;
            if(p[ptr]-p[ptr-1]>len)continue;
            var l=ptr;
            var r=n+1;
            while(r-l>1){
                var mid=(l+r)/2;
                if(p[mid]-p[ptr-1]>len)r=mid;
                else l=mid;
            }
            ptr=l+1;
        }
        if(ptr==n+1)println("YES")
        else println("NO")
    }
}