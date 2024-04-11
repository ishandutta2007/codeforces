import java.io.PrintWriter
import java.lang.Integer.max
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
    val (n, m) = readInts()
    val a = IntArray(n)
    val X = IntArray(m)
    val Y = IntArray(m)
    val W = IntArray(m)
    for (i in 0 until m) {
        var (x, y, w) = readInts()
        x--
        y--
        X[i] = x
        Y[i] = y
        W[i] = w
    }
    for (i in 0 until m) {
        a[X[i]] = max(a[X[i]], W[i])
        a[Y[i]] = max(a[Y[i]], W[i])
    }
    for (i in 0 until m) {
        if (min(a[X[i]], a[Y[i]]) != W[i]) {
            println("NO")
            return
        }
    }
    println("YES")
    for (x in a) {
        print("$x ")
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