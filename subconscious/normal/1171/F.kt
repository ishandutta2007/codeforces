class seg(val l:Int,val r:Int,val key:Int)
fun main(){
    val t=readLine()!!.toInt()
    repeat(t){
        val n=readLine()!!.toInt()
        var a=Array<seg>(n){i->seg(0,0,0)}
        var ans=Array<Int>(n){0}
        var low=Array<Int>(n){0}
        for(i in 0 until n){
            var(x,y)=readLine()!!.split(" ").map{it.toInt()}
            a[i]=seg(x,y,i)
        }
        a.sortWith(Comparator{x,y->when{
            x.r!=y.r->x.r-y.r
            else->x.l-y.l
        }})
        //for(i in a)println(i.l)
        low[n-1]=a[n-1].l;
        for(i in n-2 downTo 0)low[i]=minOf(low[i+1],a[i].l)
        var gf=-1
        for(i in 0 until n-1)if(a[i].r<low[i+1]){gf=i;break;}
        if(gf==-1)println("-1")
        else{
            for(i in 0 until n)ans[a[i].key]=if (i<=gf) 1 else 2
            println(ans.joinToString(" "))
        }
    }

}