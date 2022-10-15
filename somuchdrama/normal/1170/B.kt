fun main(args: Array<String>){
    val n=readLine()!!.toInt()
    val a=readLine()!!.split(" ").map{it.toLong()}
    val s = sortedSetOf(0L)
    var ans=0;
    var ptr=0;
    for (i in a) {
        var cnt=0;
        for (j in s) {
            if(j>=(-i*1000000000L-ptr))break;
            cnt+=1;
            if(cnt==2){
                ans+=1;
                break;
            }
        }
        s.add(-i*1000000000L-ptr)
        ptr+=1
    }
    println(ans);
}