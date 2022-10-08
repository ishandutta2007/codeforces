fun main() {
    val n=readLine()!!.toInt();
    val a=readLine()!!;
    var (counter, ans) = listOf(0, 0);
    for (i in 0 until n) {
        if (a[i]=='x') {
            counter++
            if (counter>2) ans++
        }
        else counter=0
    }
    println(ans)
}