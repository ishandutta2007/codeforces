fun main(args: Array<String>) {
    val (n, m) = readLine()!!.split(' ').map { x -> x.toInt() }
    val count = Array(n) { IntArray(n) { 0 } }
    val first = IntArray(n)
    val last = IntArray(n)

    var (xx, yy) = readLine()!!.split(' ').map { x -> x.toInt() }
    -- xx
    -- yy
    for (i in 2..m) {
        var (x, y) = readLine()!!.split(' ').map { x -> x.toInt() }
        -- x
        -- y
        ++ count[x][y]
        ++ first[x]
        ++ last[y]
    }
    var res = 0
    for (i in 0 until n) {
        for (j in 0 until n) {
            if (i == j) {
                continue
            }
            if (i == xx || j == yy) {
                continue
            } else {
                res = res.coerceAtLeast(first[i] + last[j] - count[i][j])
            }
        }
    }
    println(res + 1)
}