/*

  X *X  *** X

1
5 2
*.*.*
 */
fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val (n, k)= readLine()!!.split(" ").map { it.toInt() };
        val line=readLine()!!;
        val count=line.count { it=='*' };
        if (count<=0) {
            println(count);
        }
        else {
            var firstIndex = line.indexOfFirst { it=='*' };
            var lastIndex = line.indexOfLast { it=='*' };
            var count=0;
            var lastX=firstIndex
            var lastStar=firstIndex;
            for (l in firstIndex..lastIndex) {
                if (line[l]!='*') continue;
                if (l-lastX>k || l==firstIndex) {
                    count++;
                    lastX=lastStar;
                }
                if (l==lastIndex && l!=firstIndex) {
                    count++;
                }
                lastStar=l;
            }
            println(count);
        }

    }
}