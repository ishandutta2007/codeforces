//package codeforces.cf632

fun main() {
    val n = readLine()!!.toInt()
    if (n <= 2) {
        println(-1)
    } else if (n == 3) {
        println("1 7 9")
        println("3 2 5")
        println("4 8 6")
    } else {
        val answer = Array(n) { IntArray(n) }
        answer[0][0] = 1
        answer[0][1] = (n * n) - 4
        answer[0][2] = 2
        answer[0][3] = (n * n) - 3

        answer[1][0] = (n * n) - 5
        answer[1][1] = (n * n) - 1
        answer[1][2] = 3
        answer[1][3] = 4

        answer[2][0] = 10
        answer[2][1] = 8
        answer[2][2] = 9
        answer[2][3] = (n * n) - 2

        answer[3][0] = n * n
        answer[3][1] = 7
        answer[3][2] = 6
        answer[3][3] = 5

        if (n >= 5) {
            var k = 11
            answer[2][4] = k
            k++
            for (y in 0 until 5) {
                if (y != 2) {
                    answer[y][4] = k
                    k++
                }
            }
            for (x in 3 downTo 0) {
                answer[4][x] = k
                k++
            }
            for (z in 5 until n) {
                answer[z - 1][z] = k
                k++
                for (y in 0..z) {
                    if (y != z - 1) {
                        answer[y][z] = k
                        k++
                    }
                }
                for (x in z - 1 downTo 0) {
                    answer[z][x] = k
                    k++
                }
            }
        }
        println(answer.map { it.joinToString(" ") }.joinToString("\n"))
    }
}