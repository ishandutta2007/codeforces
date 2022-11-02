private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
fun main(args: Array<String>) {
    var t = readInt()
    while (t-- > 0) {
    	var (n, m) = readInts()
    	var u = IntArray (m)
    	var v = IntArray (m)
    	var w = IntArray (m)
    	var order = MutableList<Pair<Int, Int>> (m, {Pair(0, 0)})
    	for (i in 0..m - 1) {
    	    var (a, b, c) = readInts()
            a--
            b--
            u[i] = a
            v[i] = b
            w[i] = c
            order[i] = Pair(w[i], i)
    	}
    	order.sortWith(compareBy({it.first}, {it.second}))
    	var ok = 1
    	var ans = Array<Int> (n, {-1})
    	for (i in 0..m - 1) {
    	    var U = u[order[m - 1 - i].second]
    	    var V = v[order[m - 1 - i].second]
    	    var W = w[order[m - 1 - i].second]
    	    if (ans[U] == -1) {
    	        ans[U] = W
    	    }
    	    if (ans[V] == -1) {
    	        ans[V] = W
    	    }
    	    if (ans[U] != W && ans[V] != W) {
    	        ok = 0
    	    }
    	}
    	if (ok == 0) {
    	    println("NO")
    	} else {
    	    println("YES")
    	    println(ans.joinToString(" "))
    	}
    }
}