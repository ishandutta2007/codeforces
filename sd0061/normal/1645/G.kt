fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    var a = readLine()!!.toString().reversed()
    var b = readLine()!!.toString().reversed()
    var delta = Array<Int>(n, {0})
    for (i in 0..n-1) {
        delta[i] += b[i] - a[i]
        if (delta[i] < 0) {
            delta[i + 1] --;
            delta[i] += 26
        }
    }
    for (i in n-1 downTo 0) {
        if (i > 0) {
            delta[i - 1] += delta[i] % 2 * 26
        }
        delta[i] /= 2
    }
    for (i in 0..n-1) {
        delta[i] += a[i] - 'a'
        if (delta[i] >= 26) {
            delta[i + 1] ++;
            delta[i] -= 26
        }
    }
    for (i in n-1 downTo 0) {
        print('a' + delta[i])
    }
    println("")
}