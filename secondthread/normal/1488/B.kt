import java.lang.Integer.min

fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val (n, k)=readLine()!!.split(" ").map{it.toInt()};
        var preSum=0
        var zeroCount=0;
        for (c in readLine()!!) {
            if (c=='(') preSum++
            else preSum--
            if (preSum==0) zeroCount++;
        }
        val ans=min(zeroCount+k, n/2);
        println(ans);
    }
}