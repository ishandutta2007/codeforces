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
        var c = 0
        for(i in a){
            if(i==-1) c++
        }
        val ans = Array(c) {mutableListOf<Int>()}
        val nxt = Array<Int>(c,{i->i+1})
        val prv = Array<Int>(c,{i->i-1})
        nxt[c-1]=0
        prv[0]=c-1
        var len = 0
        for(i in a){
            if(i==-1){
                val t1 = prv[len]
                val t2 = nxt[len]
                nxt[t1]=t2
                prv[t2]=t1
                len = t2
            }
            else{
                ans[len].add(i)
                len = nxt[len]
            }
        }
        val sans = Array<String>(c,{i->""})
        for(i in 0..ans.lastIndex){
            sans[i] = (ans[i].lastIndex+1).toString() + " "+ (ans[i].joinToString(separator = " ")).toString()
//            for(k in ans[i]){
//                sans[i] = sans[i]+k.toString()+" "
//            }
        }
        println(ans.lastIndex+1)
        println(sans.joinToString(separator = "\n"))
//                .joinToString("\n")))
//        for(i in 0..ans.lastIndex){
//            print(ans[i].lastIndex+1)
//            print(" ")
//
//            ans.
//        }
    }
}