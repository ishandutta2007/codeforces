
fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val n=readLine()!!.toInt();
        val a=readLine()!!.split(" ").map { it.toInt() };
        val map=HashMap<Int, Int>();
        var maxCount=0;
        a.forEach{
            map[it]=map.getOrDefault(it, 0)+1;
            maxCount=Math.max(maxCount, map[it]!!);
        }
        println(Math.max(n%2, n-2*(n-maxCount)));
    }
}