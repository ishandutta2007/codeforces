import java.lang.Integer.min
/*
2 2 0 2 1 0

0 1 1 1 5 2 4 4 6 7

 */
fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() };
        val counts=IntArray(m);
        val a=readLine()!!.split(" ").map{it.toInt()};
        a.forEach{counts[it%m]++};
        var total=n;
        for (i in 0 until m) {
            if (i+i==m || i==0) {
                //special case
                if (counts[i]!=0) {
                    total -= counts[i] - 1;
                    //println("For $i subtracting ${counts[i]-1}");
                }
            }
            else {
                if (counts[i]==counts[m-i]) {
                    if (counts[i]!=0)
                        total -= 2 * min(counts[i], counts[m - i]) - 1;
                }else
                    total-=2*min(counts[i], counts[m-i]);
                //println("After $i total now $total");
                counts[i]=0;
                counts[m-i]=0;
            }
        }
        println(total);
    }
}