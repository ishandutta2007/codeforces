import java.lang.Integer.min

fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    for (ca in 1..t) {
        val n =  readLine()!!.toInt()
        val (a, va) = readLine()!!.split(' ').map {x -> x.toInt()}
        val (c, vc) = readLine()!!.split(' ').map {x -> x.toInt()}
        val b = readLine()!!.toInt()
        val vb = min(vc, b - a + va)
        println(vb)
    }
}