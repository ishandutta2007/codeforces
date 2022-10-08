import java.io.PrintWriter
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
    val (n, k) = readInts()
    val x = 1 + k + k * k + k * k * k;
    print(n / x)
    print(" ")
    print(n / x * k)
    print(" ")
    print(n / x * k * k)
    print(" ")
    println(n / x * k * k * k)
}

fun main() {
    val tests = readInt()
    for (test in 1..tests) {
        runTest()
    }
    sc.close()
    pw.close()
}