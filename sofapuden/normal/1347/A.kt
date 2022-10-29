private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args:Array<String>){
    val t = readInt()
    repeat(t){
        val (a, b) = readInts()
        println(a+b)
    }
   
}