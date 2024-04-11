import java.io.PrintWriter
import java.util.*
val sc = Scanner(System.`in`)
val pw = PrintWriter(System.out)
fun readLine() = sc.next()!!
fun readInt() = readLine().toInt() // single int
fun readStrings() = readLine().split(" ").toTypedArray()
fun readInts() = readStrings().map { it.toInt() }.toIntArray()
fun print(x : Any) = pw.print(x)
fun println() = pw.println()

fun runTest() {
    val n = readInt()
    if (n <= 3) {
        pw.println(-1)
        return
    }
    var cur = 1
    if (n % 2 == 0) {
        cur = 2
    }
    while (cur <= n) {
        pw.print("$cur ")
        cur += 2
    }
    cur -= 2
    cur -= 3
    print("$cur ")
    cur += 2
    print("$cur ")
    cur -= 4
    while (cur >= 1) {
        print("$cur ")
        cur -= 2
    }
    println()
}

fun main() {
    val tests = readInt()
    for (test in 1..tests) {
        runTest()
    }
    sc.close()
    pw.close()
}