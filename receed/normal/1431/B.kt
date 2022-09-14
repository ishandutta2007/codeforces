fun main() {
    val t = readLine()!!.toInt()
    for (i in 1..t) {
        val s = readLine()!!
        println(s.count {it == 'w'} + s.split('w').sumBy { it.length / 2 })
    }
}