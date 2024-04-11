/*
8
1 1 2 1 1 2 1 1
 */
fun main() {
    val n = readLine()!!.toInt();
    val a=readLine()!!.split(" ").map{it.toInt()};
    var count=0;
    var top=-1;
    var bottom=-1;
    for (i in a) {
        if (i==top) {
            if (i==bottom) {
                continue;
            }
            bottom=i;
            count++;
        }
        else if (i==bottom) {
            top=i;
            count++;
        }
        else {
            if (top!=bottom) {
                bottom=-1;
                top=i;
            }
            else {
                top=i;
            }
            count++;
        }
    }
    println(count);
}