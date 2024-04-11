fun main(args: Array<String>) {
    val a = readLine()!!.split(" ").map { x -> x.toInt() }
    var n = a[0]
    var k = a[1]
    if (n < k) {
        println("NO")
        return
    }
    var cnt = 0
    val num = Array<Int>(30, {0});
    for (i in 29 downTo 0) {
        if (n >= (1 shl i)) {
            n -= 1 shl i
            ++ cnt
            ++ num[i]
        }
    }
    if (cnt > k) {
        println("NO")
    } else {
        for (i in 29 downTo 1) {
            while (num[i] > 0 && cnt < k) {
                num[i] --;
                num[i - 1] += 2
                cnt ++
            }
        }
        println("YES")
        for (i in 0..29) {
            for (j in 1..num[i]) {
                print(1 shl i)
                print(" ")
            }
        }
        println("")
    }
}