import java.lang.AssertionError
 
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
        var (n, k1, k2) = readLongs()
        var s = readLn()
    	var ans = (0).toLong()
    	var last = (0).toLong()
    	for (i in s) {
    		if (i == '0') {
    			last = 0
    			continue
    		}
    		var now = k1
    		if (now + last > k2) {
    			now = k2 - last
    		}
    		ans = ans + now
    		last = now
    	}
    	println(ans)
    }
}