
fun go(n: Int, k: Int) {
    if (k>3) {
        print("1 ");
        go(n-1, k-1);
        return;
    }
    if (n<8) {
        val a=if (n%2==0) 2 else 1;
        val b=(n-1)/2;
        println("$a $b $b");
    }
    else {
        if (n%4!=0) {
            val aList = listOf(4, 1, 2, 1);
            val a = aList[n % 4];
            val b = (n - a) / 2;
            println("$a $b $b");
        }
        else {
           println("${n/4} ${n/4} ${n/2}");
        }
    }
}

fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val (n, k) = readLine()!!.split(" ").map{it.toInt()};
        go(n, k);
    }
}