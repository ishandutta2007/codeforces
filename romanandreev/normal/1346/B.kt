import java.io.PrintWriter
import java.lang.Integer.min
import java.util.*
val sc = Scanner(System.`in`)
val pw = PrintWriter(System.out)
fun readLine() = sc.nextLine()!!
fun readInt() = readLine().toInt() // single int
fun readStrings() = readLine().split(" ").toTypedArray()
fun readInts() = readStrings().map { it.toInt() }.toIntArray()
fun print(x : Any) = pw.print(x)
fun println(x : Any) = pw.println(x)
fun println() = pw.println()

fun runTest() {
    val (n, k1, k2) = readInts()
    val exc = readLine()
    var sum = 0;
    var lastDay = 0;
    for (x in exc) {
        var curDay = 0;
        if (x == '1') {
            curDay = min(k1, k2 - lastDay)
        }
        lastDay = curDay;
        sum += curDay
    }
    println(sum)
}

fun main() {
    val tests = readInt()
    for (test in 1..tests) {
        runTest()
    }
    sc.close()
    pw.close()
}