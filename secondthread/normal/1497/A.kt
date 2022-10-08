
fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val n=readLine()!!.toInt();
        val a=readLine()!!.split(" ").map { it.toInt() };
        val counts=IntArray(101);
        a.forEach{counts[it]++};
        val b=IntArray(n);
        var index=0;
        for (i in 0 until n) {
            if (counts[i]==0) break;
            b[index++]=i;
            counts[i]--;
        }
        for (i in 0 until 101) {
            while (counts[i]>0) {
                b[index++]=i;
                counts[i]--;
            }
        }
        println(b.joinToString(" "));
    }
}