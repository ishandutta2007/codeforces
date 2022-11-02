val scan = java.util.Scanner(System.`in`)

fun solve() {
    var n = scan.nextInt()
    var a = IntArray(n, {0})
    for (i in 0 until n) {
        a[i] = scan.nextInt()
    }
    var sum : Int = 0
    for (i in a) {
        sum += i
    }
    println((sum + n - 1) / n)
}

fun main(args: Array<String>) {
    var t = scan.nextInt()
    for (i in 0 until t) {
        solve()
    }
}