private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
//    val t = readInt()
    val t = 1
    repeat(t) {
        val n = readInt()
        val a = readInts()
        val b = readInts()
        val gr = Array(n) {mutableListOf<Int>()}
        for(i in 1..n-1){
            gr[b[i-1]-1].add(i)
        }
        var child = 0
        for(i in 0..n-1){
            if(gr[i].isEmpty()) child=child+1
        }
        fun dfs(v: Int) : Int {
            if(gr[v].isEmpty()) return 1
            var c = 0
            if(a[v]==1) c=1000000
            for(i in gr[v]){
                val temp = dfs(i)
                if(a[v]==1) c= minOf(c,temp)
                else c=c+temp
            }
            return c
        }
        println(child-dfs(0)+1)
    }
}