import java.util.Scanner
import java.util.Arrays

class P(n: String, h: Int) {
    public var name: String = n
    public var height: Int = h
}

fun main(args: Array<String>) {
    val cin = Scanner(System.`in`)
    var n = cin.nextInt();
    val a = Array(n, { P(cin.next(), cin.nextInt()) })
    Arrays.sort(a){ x, y -> x.height - y.height }
    for (x in a) println(x.name)
}