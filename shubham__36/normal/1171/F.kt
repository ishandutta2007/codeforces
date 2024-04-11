fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
//    val t = 1
    repeat(t){
        val n = readLine()!!.toInt()
        val a = (1..n).map { readLine()!!.split(" ").map { it.toInt() } };
        val b = (0..n - 1).sortedWith(compareBy( { a[it][0] } ));
        var temp = a[b[0]][1];
        var bo=0
        for(i in 1..n-1){
            if(a[b[i]][0]>temp) {
                bo = i
                break
            }
            else{
                temp = maxOf(a[b[i]][1],temp);
            }
        }
        if(bo==0){
            println(-1)
        }
        else{
            var a = Array<Int>(n,{i->0})
            for(i in 0..n-1) {
                if (i < bo) a[b[i]]=1
                else a[b[i]]=2
            }
            for(i in 0..n-1) {
                print(a[i])
                print(" ")
            }
            println()
        }
    }
}