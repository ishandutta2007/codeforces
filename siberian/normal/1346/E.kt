 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
 
fun main(args: Array<String>) {
  	var (n, m, k) = readInts()
 	k--
 	var dp = Array<Int> (n, {-1})
 	dp[k] = 0
    for (i in 0..m - 1) {
        var(a, b) = readInts()
        a--
        b--
        if (dp[a] == -1 && dp[b] == -1) {
            continue
        }
        else if (dp[a] == -1) {
            dp[a] = dp[b]
            dp[b]++
        }
        else if (dp[b] == -1) {
            dp[b] = dp[a]
            dp[a]++
        } else {
            var na = dp[a] + 1
            if (na > dp[b]) {
                na = dp[b]
            }
            var nb = dp[b] + 1
            if (nb > dp[a]) {
                nb = dp[a]
            }
            dp[a] = na
            dp[b] = nb
        }
    }
    println(dp.joinToString(" "))
}