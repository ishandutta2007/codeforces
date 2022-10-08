
fun query(i: Int):Int {
    println("? $i");
    return readLine()!!.toInt();
}

fun main() {
    val n = readLine()!!.toInt();
    var l=1;
    var r=n;
    while (r>l+2) {
        val m1=(l+r)/2;
        val m2=m1+1;
        if (query(m1)<query(m2)) {
            r=m2;
        }
        else {
            l=m1;
        }
    }
    var min=l;
    for (i in l..r) {
        if (query(i)<query(min)) min=i;
    }
    println("! $min");
}