

fun main() {
    val n = readLine()!!.toInt();
    val a = readLine()!!.split(" ").map { it.toLong() };
    val hs = HashSet<Long>();
    val hs2 = HashSet<Long>();
    a.forEach {
        if (hs.contains(it)) hs2.add(it);
        hs.add(it)
    }
    val list = mutableListOf<Int>();
    var sum=0L;
    a.forEach { sum+=it }
    for (i in 0 until n) {
        val otherSum=sum-a[i];
        if (otherSum%2==0L && hs2.contains(otherSum/2)) {
            list.add(i);
        }
        else if (otherSum%2==0L && hs.contains(otherSum/2) && otherSum/2 != a[i]) {
            list.add(i);
        }
    }
    println(list.size);
    list.forEach{print("${it+1} ")}
    println();
}