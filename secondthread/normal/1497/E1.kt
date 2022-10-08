
val factorOf=IntArray(1_000_000_2) {-1};

fun removeSquares(nn: Int): Int {
    var n=nn;
    var toReturn=1;
    while (n!=1) {
        val fact=factorOf[n];
        var count=0;
        while (n%fact==0) {
            count++;
            n/=fact;
        }
        for (i in 0 until (count%2)) {
            toReturn*=fact;
        }
    }
    return toReturn;
}

fun main() {
    val T=readLine()!!.toInt();
    for (i in 2 until factorOf.size) {
        for (j in i until factorOf.size step i) {
            if (factorOf[j]==-1)
                factorOf[j]=i;
        }
    }
    repeat(T) {
        val (n, k) = readLine()!!.split(" ").map{it.toInt()};
        val a=readLine()!!.split(" ").map{removeSquares(it.toInt())};
        var count=1;
        var lastRemoved=-1;
        val lastSeen=HashMap<Int, Int>();
        for (i in 0 until n) {
//            println("Looking at ${a[i]} $count");
            if (lastSeen.contains(a[i])) {
                if (lastSeen[a[i]]!!>lastRemoved) {
                    count++;
                    lastRemoved=i-1;
                }
            }
            lastSeen[a[i]]=i;
        }
        println(count);
    }
}