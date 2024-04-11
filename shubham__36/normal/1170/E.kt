private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
//    val t = readInt()
    val t = 1
    repeat(t) {
        val (n,m) = readInts()
        val a = readInts()
        val q = readInt()
        val pref_sum = Array<Int>(n+1,{i->0})
        for(i in 1..n){
            pref_sum[i] = pref_sum[i-1]+a[i-1]
        }
        for(i in 1..q){
            var k = readInts()
            var sum = 0
            for(i in 1..k[0]){
                if(i==1){
                    val t1 = k[i]-1
                    var l = 0
                    var r = n
                    while(l!=r){
                        var mid = (l+r+1)/2
                        if(pref_sum[mid]<=t1) l = mid
                        else r=mid-1
                    }
                    sum = pref_sum[l]
                }
                else{
                    val t1 = sum+k[i]-k[i-1]-1
                    var l = 0
                    var r = n
                    while(l!=r){
                        var mid = (l+r+1)/2
                        if(pref_sum[mid]<=t1) l = mid
                        else r=mid-1
                    }
                    sum = pref_sum[l]
                }
            }
            val t1 = sum+m-k.last()
            var l = 0
            var r = n
            while(l!=r){
                var mid = (l+r+1)/2
                if(pref_sum[mid]<=t1) l = mid
                else r=mid-1
            }
            sum = pref_sum[l]
            if(sum == pref_sum[n]){
                println("YES")
            }
            else{
                println("NO")
            }
        }
    }
}