
fun go(at: Int, line: String, k: Int): Int {
//    println("$at line: $line $k");
    if (!line.contains("1")) {
        return 0;
    }
    val nextPosition = (at+k-1)%line.length;
    val nextLine=line.substring(0, nextPosition)+line.substring(nextPosition+1);
    return 1+go(nextPosition, nextLine, k);
}

fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val parts = readLine()!!.split(" ").map { it.toInt() };
        val n = parts[0]
        val k = parts[1]
        val line = readLine()!!;
        val ans=go(-k+1, line, k);
        println(ans);
    }
}