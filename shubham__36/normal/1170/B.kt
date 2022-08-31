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
        var max1 = -1
        var max2 = -1
        var c = 0
        for(i in a){
            if((max1 > i) and (max2 > i))  c++
            if(max1<i){
                max2 = max1
                max1 = i
            }
            else if(max2 < i){
                max2 = i
            }
        }
        println(c)
    }
}