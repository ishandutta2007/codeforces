
fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val n=readLine()!!.toInt();
        val a=readLine()!!.split(" ").map { it.toInt() }
        var works=true;
        for (i in 0 until n-1) {
            if ((a[i+1]-a[i])%2==0) works=false
        }
        println(if (!works) "YES" else "NO")

    }
}