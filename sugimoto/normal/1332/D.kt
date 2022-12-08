fun main() {
    val k = readLine()!!.toInt()
    println("3 3")
    println("${(1 shl 18) - 1} ${1 shl 17} 0")
    println("$k ${(1 shl 18) - 1} ${(1 shl 18) - 1}")
    println("0 0 $k")
}