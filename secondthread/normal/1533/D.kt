
fun main() {
    val parts = readLine()!!.split(" ").map { it.toInt() }
    val n=parts[0];
    val m=parts[1];
    val hm = HashMap<String, Int>()
    repeat(n) {
        val line=readLine()!!
        if (hm.containsKey(line)) hm[line] = hm[line]!! + 1
        else hm[line]=1;
    }
    val nq= readLine()!!.toInt();
    repeat(nq) {
        val line=readLine()!!;
        var ans=0;
        val hs=HashSet<String>();
        for (i in 0..m) {
            val query=line.substring(0, i)+line.substring(i+1);
            if (!hs.contains(query)) {
                ans += hm.getOrDefault(query, 0);
                hs.add(query)
            }
        }
        println(ans);
    }

}