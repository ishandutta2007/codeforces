fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    var a = readLine()!!.split(" ").map {x -> x.toInt()}
    a = a.sorted()
    for (i in 2..n-1) {
        if (a[i] == a[i - 1] && a[i] == a[i - 2]) {
            println("NO")
            return
        }
    }
    println("YES")
    println((n + 1) / 2)
    for (i in 0..n-1 step 2) {
        print(a[i])
        print(" ")
    }
    println("")
    println(n / 2)
    for (i in (if(n % 2 == 0) n-1 else n-2) downTo 1 step 2) {
        print(a[i])
        print(" ")
    }
    println("")
}