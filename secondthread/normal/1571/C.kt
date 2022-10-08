
fun readInt() = readLine()!!.toInt();
fun readInts() = readLine()!!.split(" ").map { it.toInt() }
/*
1
4
abc abcdef 0
xyz zzz 1
aaa bba 0
c d 0
 */
fun main() {
   repeat(readInt()) {
      val n = readInt();
      var lb=-1
      var ub=1e9.toInt();

      repeat(n) {
         val parts=readLine()!!.split(" ");
         var match=0;
         val (n1, n2) = intArrayOf(parts[0].length, parts[1].length);
         while (match<n1 && match<n2 && parts[0][n1-1-match] == parts[1][n2-1-match])
            match++;
         if (parts[2] == "1")
            ub=minOf(match, ub);
         else
            lb=maxOf(match, lb);
      }
      println(maxOf(0, ub-lb));
      for (i in lb+1 .. ub) {
         print("$i ");
      }
      println();
   }
}