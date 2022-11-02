import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
    val cin = Scanner(System.`in`)
    var na = cin.nextInt();
    var a = Array(na, { cin.nextInt() })
    var nb = cin.nextInt()
    var b = Array(nb, { cin.nextInt() })
    var c = Array(4000, {0});
    for (x in a) c[x + 2000]++
    for (x in b) c[x + 2000]++
    var nc = 0
    for (x in c) if (x == 1) nc++
    print(nc)
    for (x in 0..3999) if (c[x] == 1) print(" ${x - 2000}")
    println("")
}