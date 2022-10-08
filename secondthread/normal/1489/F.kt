



fun possible(a: List<Int>, size:Int, nBoxes: Int, start: Int): Boolean {
    var boxesLeft=nBoxes;
    var sizeLeft=size;
    a.subList(start, a.size).forEach{
        if (size<it) return false;
        if (sizeLeft<it) {
            boxesLeft--;
            sizeLeft=size;
        }
        sizeLeft-=it;
    }
    return boxesLeft>0;
}

fun main() {
    val (n, nBoxes, size) = readLine()!!.split(" ").map{it.toInt()}
    val a =readLine()!!.split(" ").map { it.toInt() }
    var min=0;
    var max=n;
    while (min!=max) {
        val mid=(min+max)/2;
        if (possible(a, size, nBoxes, mid))
            max=mid;
        else
            min=mid+1;
    }
    println(n-min);
}