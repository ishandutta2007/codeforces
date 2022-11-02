 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
 
fun main(args: Array<String>) {
    var (n, m, q) = readInts()
    var H = Array<Long> (n, {0L})
    var W = Array<Long> (m, {0L})
    var a = Array<MutableList<Int>> (n, { i -> mutableListOf() }) 
    for (i in 0..n - 1) {
        var have = readInts()
        for (j in 0..m - 1) {
            H[i] += (have[j]).toLong()
            W[j] += (have[j]).toLong()
            a[i].add(have[j])
        }
    }
    
    var ans = Array<Long> (q + 1, {0L})
    
    var ansH = 1000000000000000000L
    var ansL = 0L
    var ansR = 0L
    var suff = 0L
    
    for (i in 0..n - 1) {
        ansR += suff
        suff += H[n - 1 - i]
    }
    
    var pref = 0L
    for (i in 0..n - 1) {
        ansL += pref
        pref += H[i]
        if (ansH > ansL + ansR) {
            ansH = ansL + ansR
        }
        suff -= H[i]
        ansR -= suff
    }
    
    var ansW = 1000000000000000000L
    ansL = 0L
    ansR = 0L
    suff = 0L
    
    for (i in 0..m - 1) {
        ansR += suff
        suff += W[m - 1 - i]
    }
    
    pref = 0L
    for (i in 0..m - 1) {
        ansL += pref
        pref += W[i]
        if (ansW > ansL + ansR) {
            ansW = ansL + ansR
        }
        suff -= W[i]
        ansR -= suff
    }
    ans[0] = ansH + ansW
    
    for (t in 1..q) {
        var (x, y, w) = readInts()
        x--
        y--
        H[x] -= (a[x][y]).toLong()
        W[y] -= (a[x][y]).toLong()
        a[x][y] = w
        H[x] += (a[x][y]).toLong()
        W[y] += (a[x][y]).toLong()
        
        var ansH = 1000000000000000000L
        var ansL = 0L
        var ansR = 0L
        var suff = 0L
        
        for (i in 0..n - 1) {
            ansR += suff
            suff += H[n - 1 - i]
        }
        
        var pref = 0L
        for (i in 0..n - 1) {
            ansL += pref
            pref += H[i]
            if (ansH > ansL + ansR) {
                ansH = ansL + ansR
            }
            suff -= H[i]
            ansR -= suff
        }
        
        var ansW = 1000000000000000000L
        ansL = 0L
        ansR = 0L
        suff = 0L
        
        for (i in 0..m - 1) {
            ansR += suff
            suff += W[m - 1 - i]
        }
        
        pref = 0L
        for (i in 0..m - 1) {
            ansL += pref
            pref += W[i]
            if (ansW > ansL + ansR) {
                ansW = ansL + ansR
            }
            suff -= W[i]
            ansR -= suff
        }
        ans[t] = ansH + ansW
    }
    
    println(ans.joinToString(" "))
}