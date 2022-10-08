import java.lang.Integer.max
import java.lang.Integer.min

fun count(size: Int, x: Int): Int {
    if (x<=0) return size-1-x;
    if (x>=size-1) return x;
    return size-1+min(x, size-1-x);
}


fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val (n, xx, yy) = readLine()!!.split(" ").map{it.toInt()};
        val x=min(xx, yy);
        val y=max(xx, yy);
        var ans=3*n;
        for (split in 1 until n) {
            val x1=x-1;

            val size2=n-split;
            val x2=y-split-1;
            ans=min(ans, max(count(split, x1), count(size2, x2)));
        }
        println(ans);
    }
}