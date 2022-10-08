
fun main() {
    val T = readLine()!!.toInt();
    repeat(T) {
        val parts=readLine()!!.split(" ");
        val a=parts[0].toInt();
        val b=parts[1].toInt();
        println(a+b);
    }
}