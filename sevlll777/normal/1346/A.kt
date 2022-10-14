import kotlin.math.*

fun readInt(): Int{return readLine()!!.toInt()}
fun readList(): MutableList<Int> {return readLine()!!.split(' ').map{it.toInt()}.toMutableList()}
fun less(x: Pair<Int, Int>, y: Pair<Int, Int>): Boolean{return x.first < y.first || x.first == y.first && x.second <= y.second}
fun comp(x: Pair<Int, Int>, y: Pair<Int, Int>): Int{return when{less(x, y) -> -1; less(y, x) -> 1 else -> 0}}
fun toInt(x: Boolean): Int{return when{x -> 1 else -> 0}}

fun main() {
    val t1 = readInt()
    for (q11 in 1..t1){
        val (n, k) = readList()
        var d4 = (n/(1+k+k*k+k*k*k))
        println(d4)
        println(d4*k)
        println(d4*k*k)
        println(d4*k*k*k)
    }
}