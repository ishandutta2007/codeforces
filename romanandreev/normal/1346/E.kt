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
    val inf = 1e9.toInt();
    var (n, m, k) = readInts()
    k--
    val X = IntArray(m)
    val Y = IntArray(m)
    val ans = IntArray(n) {inf}
    ans[k] = 0
    for (i in 0 until m) {
        var (x, y) = readInts()
        x--
        y--
        val a1 = ans[x]
        val a2 = ans[y]
        ans[x] = min(a1 + 1, a2)
        ans[y] = min(a2 + 1, a1)
    }

    for (x in ans) {
        if (x >= inf) {
            print("-1 ")
        } else {
            print("$x ")
        }
    }
    println()
}

fun main() {
    runTest()
    sc.close()
    pw.close()
}