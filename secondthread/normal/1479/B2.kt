
fun main() {
    val n = readLine()!!.toInt();
    val a=readLine()!!.split(" ").map { it.toInt() };
    val nextMatch=IntArray(n);
    val lastSeen=IntArray(n+1){n};
    for (i in n-1 downTo 0) {
        nextMatch[i]=lastSeen[a[i]];
        lastSeen[a[i]]=i;
    }
    var top=-1;
    var bottom=-1;
    var topIndex=-1;
    var bottomIndex=-1;
    var count=0;
    for (i in 0 until n) {
        if (a[i]==top) {
            topIndex=i;
            continue;
        }
        if (a[i]==bottom) {
            bottomIndex=i;
            continue;
        }
        if (top==-1) {
            top=a[i];
            topIndex=i;
            count++;
            continue;
        }
        if (bottom==-1) {
            bottom=a[i];
            bottomIndex=i;
            count++;
            continue;
        }

        //otherwise we need to replace one of them, replace whichever ends first
        if (nextMatch[topIndex]<nextMatch[bottomIndex]) {
            bottom=a[i];
            bottomIndex=i;
            count++;
        }
        else {
            top=a[i];
            topIndex=i;
            count++;
        }
    }
    println(count);
}