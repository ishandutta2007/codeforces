private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args:Array<String>){
    val t = readInt()
    repeat(t){
        val (a1, b1) = readInts()
        val (a2, b2) = readInts()
        val m1 = maxOf(a1,b1)
        val m2 = maxOf(a2,b2)
        val mi1 = minOf(a1,b1)
        val mi2 = minOf(a2,b2)
        if(m1 == m2 && mi1+mi2 == m1){
            println("Yes")
        }
        else{
            println("No")
        }    
    }
   
}