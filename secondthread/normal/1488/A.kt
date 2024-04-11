fun count(x:Int):Int = if (x==0) 0 else x%10+count(x/10);

fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val (x, y) = readLine()!!.split(" ").map{it.toInt()};
        val times=y/x;
        var total=y%x;
        total += count(times);
        println(total);
    }
}