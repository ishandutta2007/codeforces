import java.io.PrintWriter
import java.lang.Long.min
import java.lang.Math.abs
import java.lang.RuntimeException
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

var a = emptyArray<LongArray>()
var sx = LongArray(0)
var sy = LongArray(0)
var n = 0
var m = 0
fun solve() : Long {
    var ansx : Long = 1e18.toLong()
    var ansy : Long = 1e18.toLong()
    val ssx = LongArray(n + 1)
    for (i in 1..n) {
        ssx[i] = ssx[i - 1] + sx[i - 1]
    }
    val ssy = LongArray(m + 1)
    for (i in 1..m) {
        ssy[i] = ssy[i - 1] + sy[i - 1]
    }
    val sssx = LongArray(n + 1)
    for (i in 1..n) {
        sssx[i] = sssx[i - 1] + sx[i - 1] * i
    }
    val sssy = LongArray(m + 1)
    for (i in 1..m) {
        sssy[i] = sssy[i - 1] + sy[i - 1] * i
    }
    for (i in 0 until n) {
        var s = (sssx[n] - sssx[i]) - (ssx[n] - ssx[i]) * (i + 1)
        s += ssx[i] * (i + 1) - sssx[i]
        ansx = min(ansx, s)
    }
    for (i in 0 until m) {
        var s = (sssy[m] - sssy[i]) - (ssy[m] - ssy[i]) * (i + 1)
        s += ssy[i] * (i + 1) - sssy[i]
        ansy = min(ansy, s)
    }
    return ansx + ansy
}
fun runTest() {
    val (N, M, q) = readInts()
    n = N
    m = M
    a = Array(n) { LongArray(m) }
    for (i in 0 until n) {
        a[i] = readInts().map { it.toLong() }.toLongArray()
    }
    sx = LongArray(n)
    sy = LongArray(m)
    for (i in 0 until n) {
        for (j in 0 until m) {
            sx[i] += a[i][j]
            sy[j] += a[i][j]
        }
    }
    print(solve())
    for (i in 0 until q) {
        var (x, y, z) = readInts()
        x--
        y--
        sx[x] -= a[x][y]
        sy[y] -= a[x][y]
        a[x][y] = z.toLong()
        sx[x] += a[x][y]
        sy[y] += a[x][y]
        print(" ")
        print(solve())
    }
    println()
}

fun main() {
    runTest()
    sc.close()
    pw.close()
}