val scan = java.util.Scanner(System.`in`)

fun solve() {
    var a = scan.nextInt()
    var b = scan.nextInt()
    println(a + b)
}


fun main(args: Array<String>) {
    var t = scan.nextInt()
    for (i in 0 until t) {
        solve()
    }
}