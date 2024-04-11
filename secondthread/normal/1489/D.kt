fun main() {
    val n=readLine()!!.toInt();
    val strings = mutableListOf<String>()
    repeat(n) {strings.add(readLine()!!)}

    strings.sortBy { it.length }
    var works=true;
    for (i in 0 until n-1)
        if (!strings[i+1].contains(strings[i]))
            works=false;
    if (!works) {
        println("NO")
    }
    else {
        println("YES");
        println(strings.joinToString ("\n" ))
    }
}