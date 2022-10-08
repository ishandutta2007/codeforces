

fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val parts=readLine()!!.split(" ").map { it.toInt() };
        val n=parts[0]
        val k=parts[1]
        for (i in 0 until n) {
            val res=(i%k) + 'a'.toInt();
            print(res.toChar())
        }
        println();
    }
}