
fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        var (h, w, n) = readLine()!!.split(" ").map { it.toLong() };
        n--;
        val x=n/h;
        val y=n%h;
        val ans=x+y*w+1;
        println(ans);
    }
}