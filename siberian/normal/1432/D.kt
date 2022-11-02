val scan = java.util.Scanner(System.`in`)

fun solve() {
    var n = scan.nextInt()
    var a = scan.nextInt()
    var b = scan.nextInt()
    var ans = CharArray(n, {' '})
    for (i in 0 until b) {
        ans[i] = ('a'.toInt() + i).toChar()
    }
    for (i in b until a) {
        ans[i] = ans[b - 1]
    }
    for (i in a until n) {
        ans[i] = ans[i - a]
    }
    for (i in ans) {
        print(i)
    }
    println()
}

fun main(args: Array<String>) {
    var t = scan.nextInt()
    for (i in 0 until t) {
        solve()
    }
}