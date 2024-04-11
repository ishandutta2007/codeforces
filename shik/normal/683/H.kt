import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
    val cin = Scanner(System.`in`)
    var n = cin.nextInt()
    var k = cin.nextLong()
    var a = Array(n, { cin.nextInt() - 1 })
    var cid = Array(n, {-1})
    var cs: MutableList<MutableList<Int>> = mutableListOf()
    for (i in 0..n-1) {
        if (cid[i] != -1) continue
        cid[i] = cs.size
        var j = a[i]
        var c: MutableList<Int> = mutableListOf(i)
        while (j != i) {
            c.add(j)
            cid[j] = cs.size
            j = a[j]
        }
        cs.add(c)
    }
    var ans = Array(n, {-1})
    for (i in 0..cs.size-1) {
        val c = cs[i]
        val d = (k % c.size).toString().toInt()
        for (j in 0..c.size-1) {
            ans[c[(j + d) % c.size]] = c[j] + 1
        }
    }
    println(ans.joinToString(" "))
}