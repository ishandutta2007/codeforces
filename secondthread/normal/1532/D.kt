import java.util.*

fun main() {
    val n = readLine()!!.toInt();
    val a = readLine()!!.split(" ").map { it.toInt() }.toIntArray();
    a.sort();
    var total=0L;
    for (i in 0 until n step 2) {
        total+=a[i+1]-a[i]
    }
    println(total);
}