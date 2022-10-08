
fun readInt() = readLine()!!.toInt();

fun main() {
   repeat(readInt()) {
      val line=readLine()!!;
      val lt=line.contains("<")
      val gt=line.contains(">")
      val eq=line.contentEquals("=")
      if (lt && gt) {
         println("?");
      }
      else if (lt) {
         println("<")
      }
      else if (gt) {
         println(">")
      }
      else println("=")
   }
}