
fun go(fromR: Int, fromC: Int, toR: Int, toC: Int): Int {
    if (fromR==toR) return 0;
    val dR=toR-fromR;
    if ((fromR+fromC)%2!=0) {
        //adding is free, going left twice costs 1
        val targetC=fromC+dR;
        return (targetC-toC+1)/2;
    }
    else {
        val targetC=fromC+dR;
        //if we need to go right the entire time, do that now
        if (targetC==toC) return dR;
        //otherwise go left for free here
        return go(fromR+1, fromC, toR, toC);
    }
}

fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val n =readLine()!!.toInt();
        val rows=readLine()!!.split(" ").map { it.toInt() }
        val cols=readLine()!!.split(" ").map { it.toInt() }
        val pairs= MutableList<IntArray>(0) {IntArray(0)}
        for (i in 0 until n)
            pairs.add(intArrayOf(rows[i], cols[i]));
        pairs.add(intArrayOf(1, 1));
        pairs.sortBy { it[0] }
        var count=0;
        for (i in 0 until pairs.size-1) {
            val cost=go(pairs[i][0], pairs[i][1], pairs[i+1][0], pairs[i+1][1]);
            //println("$i Cost: $cost");
            count+=cost;
        }
        println(count);
    }
}