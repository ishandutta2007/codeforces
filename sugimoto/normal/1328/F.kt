import java.util.*
import kotlin.math.min

fun main() {
    val line = readLine()!!
    val six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    val k = line.substring(six + 1).toInt()
    if (k == 1) {
        println(0)
        return
    }
    val tokenizer = StringTokenizer(readLine()!!)
    val array = Array(n) { tokenizer.nextToken().toInt() }
    array.sort()
    var amtSame = 1
    for (j in 1 until n) {
        if (array[j] == array[j - 1]) {
            amtSame++
            if (amtSame == k) {
                println(0)
                return
            }
        } else {
            amtSame = 1
        }
    }
    var answer1 = 0L
    for (j in k until n) {
        if (array[j] == array[k - 1]) {
            answer1--
        }
    }
    for (j in 0 until k) {
        answer1 += (array[k - 1] - array[j]).toLong()
    }
    var answer2 = 0L
    for (j in n - k - 1 downTo 0) {
        if (array[j] == array[n - k]) {
            answer2--
        }
    }
    for (j in n - 1 downTo n - k) {
        answer2 += (array[j] - array[n - k]).toLong()
    }
    var curr = 0L
    for (j in 0 until n) {
        curr += (array[j] - array[0]).toLong()
    }
    var answer3 = curr
    for (j in 1 until n) {
        curr += (array[j] - array[j - 1]).toLong() * (j - (n - j)).toLong()
        answer3 = min(answer3, curr)
    }
    answer3 -= (n - k).toLong()
    println(min(answer3, min(answer1, answer2)))
}