fun main() {
    for (tt in 1..readLine()!!.toInt()) {
        readLine();
        val a = readLine()!!.split(" ").map { it.toInt() }
        val counts:HashMap<Int, Int> = HashMap<Int, Int>()
        for (i: Int in a) counts[i] = (counts[i]?:0)+1
        println(counts.values.max())
    }
}