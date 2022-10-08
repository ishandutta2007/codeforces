import java.io.*
import kotlin.collections.*
import kotlin.math.*

val inp = BufferedReader(InputStreamReader(System.`in`))
val pw = PrintWriter(System.out)

fun readLine()= inp.readLine()
fun readInt() = readLine().toInt() // single int
fun readStrings() = readLine().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun print(x: Any) = pw.print(x)
fun println(x: Any) = pw.println(x)
fun println() = pw.println()

fun gcd(x: Int, y: Int): Int = if (y == 0) x else gcd(y, x % y)

class Main(val k: Int, val n: Int, val p: List<Int>, val x: List<Int>) {

    fun printAns(x1: Int, p1: Int, x2: Int, p2: Int) {
        println("YES")
        print((x1 - 1) % p1 + 1)
        println(" $p1")
        print((x2 - 1) % p2 + 1)
        println(" $p2")
    }

    fun test2(x1: Int, p1: Int): Boolean {
        var g = 0
        var last = 0
        for (x2 in x) {
            if (abs(x2 - x1) % p1 != 0) {
                if (last != 0) {
                    g = gcd(g, x2 - last)
                }
                last = x2
                if (g == 1) {
                    break
                }
            }
        }
        if (last == 0) {
            printAns(x1, p1, x1, p1);
            return true;
        }
        for (p2 in p) {
            if (g % p2 == 0) {
                printAns(x1, p1, last, p2)
                return true
            }
            if (p2 > g) {
                break
            }
        }
        return false;
    }

    fun test(x1: Int, x2: Int): Boolean {
        val inf = p.last()
        val was = BooleanArray(inf + 1)
        for (p0 in p) if (!was[p0]) {
            if ((x2 - x1) % p0 == 0) {
                if (test2(x1, p0)) {
                    return true
                }
                for (i in 1..inf) {
                    if (i * p0 <= inf) {
                        was[i * p0] = true
                    } else {
                        break
                    }
                }
            }
            if (x2 - x1 < p0) {
                break
            }
        }
        return false
    }

    fun run() {
        if (n == 2) {
            println("YES")
            print(x[0])
            print(" ")
            println(p[0])
            print(x[1])
            print(" ")
            println(p[0])
            return
        }
        if (test(x[0], x[1])) {
            return
        }
        if (test(x[1], x[2])) {
            return
        }
        if (test(x[0], x[2])) {
            return
        }
        println("NO")
    }
}

fun runTest() {
    val (k, n) = readInts()
    val p = readInts()
    val x = readInts()
    Main(k, n, p, x).run()
}

fun main() {
    runTest()
    inp.close()
    pw.close()
}