
fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val parts=readLine()!!.split(" ").map { it.toLong() };
        if (parts[2]%2==0L) {
            println(parts[2]/2 * (parts[0]-parts[1]));
        }
        else {
            println(parts[2]/2 * (parts[0]-parts[1]) + parts[0]);
        }
    }
}