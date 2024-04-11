import kotlin.math.*

fun readLn() = readLine()!! // string line
fun readInt() = readLn().toInt() // single int
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints

fun f(n : Int, k : Int) : Int{
    if(k == 0)
        return n + 1
    return n - 1 + min(k-1, n-k)
}

fun main() {
    var q = readInt()
    repeat(q) {
        var (n, x, y) = readInts()
        if (x > y) {
            var (x2, y2) = Pair(y, x)
            x = x2
            y = y2
        }
        var ans = 2 * n
        for (i in x..y) {
            ans = min(ans, max(f(i, x), f(n-i, y-i)))
        }
        println(ans)
    }
}