fun main(args: Array<String>) {
    val a = readLine()!!.split(" ").map { it.toInt() }
    val ans = minOf(a[0],a[1]-1,a[2]-2)
    println(3*ans+3)
}