
fun print(a: Int, b: Int, cost: Int) = println("${a+1} ${b+1} $cost");
fun add(i: Int, j: Int, costt: Int) {
    from.add(i);
    to.add(j);
    cost.add(costt);
}

val from = mutableListOf<Int>()
val to = mutableListOf<Int>()
val cost= mutableListOf<Int>()

fun main() {
    val (l, r) = readLine()!!.split(" ").map{it.toInt()};
    println("YES");

    for (i in 0..19)
        for (j in (i+1)..19)
            add(i+1, j+1, 1 shl i)
    val START=0;
    val END=21;
    for (i in 0..19)
        add(START, 1+i, l);
    add(START, END, l);

    val diff=r-l;
    var toAdd=1;
    for (i in 0..19)
        if ((diff and (1 shl i))!=0) {
            add(i+1, END, toAdd);
            toAdd+=1 shl i;
        }

    println("22 ${from.size}");
    for (i in 0 until from.size)
        print(from[i], to[i], cost[i]);

}