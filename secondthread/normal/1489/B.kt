import kotlin.math.min

fun main() {
    val q=readLine()!!.toInt();
    for (test in 0 until q) {
        val (n, a, b) = readLine()!!.split(" ").map{it.toLong()}
        val bb=min(a*2, b);
        println(n/2*bb+n%2*a);
    }
}