import java.lang.Integer.max

fun main() {
    var T=readLine()!!.toInt();
    for (tt in 1..T) {
        val n=readLine()!!.toInt();
        val a=readLine()!!.split(" ").map(String::toInt);
        var zeros=a.count{it%3==0};
        var ones=a.count{it%3==1};
        var twos=a.count{it%3==2};
        var turns=0;
        while (max(zeros, max(ones, twos))*3>n) {
            val zo=max(0, zeros-n/3);
            val ot=max(0, ones-n/3);
            val to=max(0, twos-n/3);
            ones+=zo-ot;
            twos+=ot-to;
            zeros+=to-zo;
            turns+=zo+ot+to;
        }
        println(turns);
    }
}