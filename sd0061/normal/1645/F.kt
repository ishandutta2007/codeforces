fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map { x -> x.toInt() }.sorted()
    var cur = 0
    var res = 0
    for (x in a) {
        if (cur < x - 1) {
            cur = x - 1
            ++ res;
        } else if (cur < x) {
            cur = x
            ++ res
        } else if (cur < x + 1) {
            cur = x + 1
            ++ res
        }
    }
    println(res)
}