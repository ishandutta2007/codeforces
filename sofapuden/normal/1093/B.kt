private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args:Array<String>){
    val t = readInt()
    repeat(t){
        val s: CharArray = readLine()!!.toCharArray()
        s.sort()
        if(s.first() == s.last()){
            println(-1)
        }
        else{
            println(String(s))
        }  
    }
}