import java.lang.Integer.max

fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val parts = readLine()!!.split(" ").map { it.toInt()};
        val n =parts[0];
        val k=parts[1];
        var ans=0;
        repeat(n) {
            val parts2=readLine()!!.split(" ").map { it.toInt() };
            if (parts2[0]>k) {

            }
            else {
                ans=max(ans, parts2[1]-k+1);
            }
        }
        println(ans);
    }
}