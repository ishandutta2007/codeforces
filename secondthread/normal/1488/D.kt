import java.lang.Long.max
/*
1
2 6
1
2 1000000000000000000
1
4 10
1
4 14
1
4 13

1
1 15
 */

//return 1 if sum is too big, 0 otherwise
fun possible(n: Long, s: Long, last: Long): Boolean {
    //worried about sum of first n choices being too big
//    println("$n, $s, $last")
    if (n>s) {
        return false;
    }
    if (n==0L || last==1L) {
        return true;
    }
    val prev=max(1, (last+1)/2);
    return possible(n-1, s-last, prev);
}

fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val (n, s) = readLine()!!.split(" ").map{it.toLong()};
        var min=1L;
        var max=s;
        while (min!=max) {
            val mid=(min+max+1)/2;
            if (possible(n, s, mid)) {
                min=mid;
            }
            else {
                //we are too big for it to be possible
                max=mid-1;
            }
        }
        println(min);
    }
}