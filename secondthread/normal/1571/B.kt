
fun readInt() = readLine()!!.toInt();
fun readInts() = readLine()!!.split(" ").map { it.toInt() }

fun main() {
   repeat(readInt()) {
      readInt();// n
      val (a, va) = readInts();
      val (c, vc) = readInts();
      val b=readInt();
      println(minOf(va+(b-a), vc));
   }
}