val scan = java.util.Scanner(System.`in`)

fun solve() {
    var n = scan.nextInt()
    println(n - (n + 2) / 2)
}

fun main(args: Array<String>) {
    var t = scan.nextInt()
    for (i in 0 until t) {
        solve()
    }
}