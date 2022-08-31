import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.HashMap
import kotlin.math.max

class MyReader(inputStream: InputStream) {
  private val reader = BufferedReader(InputStreamReader(inputStream))
  private var tokenizer: StringTokenizer? = null

  fun next(): String {
    while (true) {
      tokenizer.let {
        if (it == null || !it.hasMoreTokens()) {
          tokenizer = StringTokenizer(reader.readLine())
        } else {
          return it.nextToken()
        }
      }
    }
  }
}
val reader = MyReader(System.`in`)
fun next() = reader.next()
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun nextStrings(n: Int) = Array(n) { next() }
fun nextInts(n: Int) = Array(n) { nextInt() }
fun nextLongs(n: Int) = Array(n) { nextLong() }
fun nextDoubles(n: Int) = Array(n) { nextDouble() }

fun main() {
  val arrs = Array(500111) { mutableListOf<Int>() }
  val n = nextInt()
  repeat(n) {
    val (x, y) = nextInts(2)
    arrs[y].add(x)
  }
  arrs.forEach { it.sort() }
  var ans = n
  for (iter in 0..1) {
    var u1 = BooleanArray(arrs[0].size) { false }
    for (i in 0 until arrs.size - 1) {
      val a1 = arrs[i]
      val a2 = arrs[i + 1]
      val u2 = BooleanArray(arrs[i + 1].size) { false }
      if ((i + iter) % 2 == 0) {
        val q = mutableListOf<Int>()
        var k = a2.size - 1
        for (j in a1.size - 1 downTo 0) {
          if (u1[j]) continue
          while (k >= 0 && a2[k] > a1[j]) {
            q.add(k)
            --k
          }
          q.removeLastOrNull()?.let { ans--; u2[it] = true }
        }
      } else {
        val q = mutableListOf<Int>()
        var k = 0
        for (j in 0 until a1.size) {
          if (u1[j]) continue
          while (k < a2.size && a2[k] < a1[j]) {
            q.add(k)
            ++k
          }
          q.removeLastOrNull()?.let { ans--; u2[it] = true }
        }
      }
      u1 = u2
    }
  }
  println(ans)
}