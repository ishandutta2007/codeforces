import java.util.*

fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val n = readLine()!!.toInt();
        val a = readLine()!!.split(" ").map { it.toInt() };
        val minAns=IntArray(n);
        val maxAns=IntArray(n);
        val pqMin=PriorityQueue<Int>(compareBy{it});
        val pqMax=PriorityQueue<Int>(compareBy{-it});
        var maxSeen=0;
        for (i in 0 until n) {
            val new = maxSeen != a[i];
            while (maxSeen+1<a[i]) {
                maxSeen++;
                pqMin.add(maxSeen);
                pqMax.add(maxSeen);
            }
            maxSeen=a[i];
            if (new) {
                minAns[i]=a[i];
                maxAns[i]=a[i];
            }
            else {
                minAns[i]=pqMin.remove();
                maxAns[i]=pqMax.remove();
            }
        }
        println(minAns.joinToString(" "));
        println(maxAns.joinToString(" "));
    }
}