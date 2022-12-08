import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    for (c in 1..jin.nextInt()) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        val c = jin.nextInt()
        val d = jin.nextInt()
        val x = jin.nextInt()
        val y = jin.nextInt()
        val x1 = jin.nextInt()
        val y1 = jin.nextInt()
        val x2 = jin.nextInt()
        val y2 = jin.nextInt()
        if (x1 <= x - a + b && x - a + b <= x2 && (x1 != x2 || (a == 0 && b == 0)) && y1 <= y - c + d && y - c + d <= y2 && (y1 != y2 || (c == 0 && d == 0))) {
            println("YES")
        } else {
            println("no")
        }
    }
}