import kotlin.math.*
 
private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun Boolean.toInt() = if (this) 1 else 0

fun main(args : Array<String>) {
    var t = readInt()
    
    while(t > 0){
    
    var (n, k) = readInts()
    var x = n / (k*k*k+k*k+k+1)
    print(x)
    print(" ")
    x = x * k
    print(x)
    print(" ")
    x = x * k
    print(x)
    print(" ")
    x = x * k
    println(x)
    
    t -= 1
    }
}