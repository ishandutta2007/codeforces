private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toLong() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toLong() } // list of ints

fun main(){
    val t = readLn().toInt()
    repeat(t){
        val n = readInt()
        var v = readInts()
        v = v.sorted()
        var ans = v[0]
        for(i in 0..n-1){
            ans = maxOf(ans,v[i.toInt()]*(n-i))
        }
        println(ans)
    }
}