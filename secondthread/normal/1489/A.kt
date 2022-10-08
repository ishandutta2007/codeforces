fun main() {
    val n = readLine()!!.toInt();
    val a = readLine()!!.split(" ").map { x -> x.toInt() };

    val ans = mutableListOf<Int>();
    outer@ for (i in 0 until n) {
        for (j in i+1 until n) {
            if (a[i]==a[j])
                continue@outer
        }
        ans.add(a[i])
    }
    println(ans.size)
    ans.map { print("$it "); }
    println();
}