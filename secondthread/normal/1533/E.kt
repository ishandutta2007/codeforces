import kotlin.math.max
/*
1
5
2 7
3
0 4 19
 */
fun main() {
    val n=readLine()!!.toInt();
    val a=readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    val b=readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    a.sort()
    b.sort()
    val prefixMaxDiff=IntArray(n+1) {Int.MIN_VALUE}
    val suffixMaxDiff=IntArray(n+1) {Int.MIN_VALUE}
    for (i in 1..n) prefixMaxDiff[i]= max(prefixMaxDiff[i-1], b[i-1]-a[i-1]);
    for (i in n-1 downTo 0) suffixMaxDiff[i]= max(suffixMaxDiff[i+1], b[i+1]-a[i]);

    readLine();
    val queries=readLine()!!.split(" ").map { it.toInt() }
    for (x in queries) {
        //get the index of the first thing >= x
        var l=0
        var r=n;
        while (l != r) {
            val mid=(l+r)/2;
            if (a[mid]<x) {
                l=mid+1;
            }
            else {
                r=mid;
            }
        }
        // new index will be l
        val max= max(prefixMaxDiff[l], max(suffixMaxDiff[l], b[l]-x));

        print("$max ")
    }
    println()

}