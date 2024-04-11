import java.io.PrintWriter
import java.lang.Long.min
import java.util.*
val sc = Scanner(System.`in`)
val pw = PrintWriter(System.out)
fun readLine() = sc.nextLine()!!
fun readInt() = readLine().toLong() // single int
fun readStrings() = readLine().split(" ").toTypedArray()
fun readInts() = readStrings().map { it.toLong() }.toLongArray()
fun print(x : Any) = pw.print(x)
fun println(x : Any) = pw.println(x)
fun println() = pw.println()

fun runTest() {
    val (n, k, x, y) = readInts()
    val a = readInts()
    a.sort()
    var ans = x * n
    var sumAll = a.sum()
    var del = 0
    for (i in (0..n).reversed()) {
        if (sumAll <= k * n) {
            ans = min(ans, x * (n - i) + y)
        }
        if (i.toInt() == 0 || a[i.toInt() - 1] <= k) {
            ans = min(ans, x * (n - i))
        }
        if (i.toInt() > 0) {
            sumAll -= a[i.toInt() - 1]
        }
    }
    println(ans)
}

fun main() {
    val tests = readInt()
    for (test in 1..tests) {
        runTest()
    }
    sc.close()
    pw.close()
}