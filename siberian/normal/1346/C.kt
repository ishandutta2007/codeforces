import java.lang.AssertionError
import kotlin.math.*
import java.util.*
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}
 
fun main(args: Array<String>) {
    var t = readInt()
    for (i in 0 until t) {
        var (n, k, x, y) = readLongs()
 		var a = MutableList<Long> (0, {0L})
        var have = readLongs()
       	for (i in have) {
       		a.add(i)
       	}
       	a.sort()
       	var sum = 0L
       	for (i in a) {
       		sum += i
       	}
        if (a[(n - 1).toInt()] <= k) {
        	println(0)
        	continue
        }
       	var ans = x * n
		var i = (n - 1).toInt()
       	while (i >= 0) {
       		if (sum <= n * k) {
				var have = (n - 1 - i) * x + y
				if (a[i] <= k) {
					have = (n - 1 - i) * x
				}
				if (ans > have) {
					ans = have
				}
			}
			sum -= a[i]
			i--       
       	} 
       	println(ans)
    }
}