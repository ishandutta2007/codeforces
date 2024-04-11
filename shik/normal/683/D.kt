import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
    val cin = Scanner(System.`in`)
    var q = cin.nextInt();
    for (i in 1..q) {
        var n = cin.nextInt()
        var m = cin.nextInt()
        var p = cin.nextInt()
        var good = false
        for (x in 1..n) for (y in 1..m) if (x * y == p) good = true
        if (good) println("Yes")
        else println("No")
    }
}