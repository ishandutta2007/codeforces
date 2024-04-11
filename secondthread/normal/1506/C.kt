
fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val sa=readLine()!!;
        val sb=readLine()!!;
        var maxMatch=0;
        for (i in 0 until sa.length) {
            for (j in 0 until sb.length) {
                for (k in 0 until Math.min(sa.length-i, sb.length-j)) {
                    if (sa[i+k]!=sb[j+k]) break;
                    maxMatch=Math.max(maxMatch, k+1);
                }
            }
        }
        println(sa.length+sb.length-2*maxMatch);
    }
}