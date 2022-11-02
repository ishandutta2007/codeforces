import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
    val cin = Scanner(System.`in`)
    var n = cin.nextInt();
    var a = Array(n, { cin.nextInt() })
    for (t in 1..n) {
        var x = -1
        for (i in 0..n-1) {
            if (a[i] == 0) {
                x = i
                break
            }
        }
        print(x + 1)
        if (t == n) println("")
        else print(" ")
        for (i in 0..x) a[i]--
    }
}