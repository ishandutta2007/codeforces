private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val t = readInt()
//    val t = 1
    repeat(t) {
        val (x,y) = readInts()
        val com = minOf(x-1,y-1)
        val a = Array<Int>(3,{i->0})
        a[0]=x-com
        a[1]=com
        a[2]=y-com
        for(i in a){
            print("$i ")
        }
        println()
    }
}