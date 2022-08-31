import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.util.*
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
fun nextInts(n: Int) = IntArray(n) { nextInt() }
fun nextLongs(n: Int) = LongArray(n) { nextLong() }
fun nextDoubles(n: Int) = DoubleArray(n) { nextDouble() }

fun main() {
  val s = next().toCharArray()
  val n = s.size
  val p0 = (0 until n).filter { s[it] == '0' }.toIntArray()
  val p1 = (0 until n).filter { s[it] == '1' }.toIntArray()
  val cnt0 = IntArray(n + 1)
  cnt0[0] = 0
  for (i in 0 until n) cnt0[i + 1] = cnt0[i] + if (s[i] == '1') 0 else 1
  val cnt1 = IntArray(n + 1)
  cnt1[0] = 0
  for (i in 0 until n) cnt1[i + 1] = cnt1[i] + if (s[i] == '1') 1 else 0

  (1..n).map { k ->
    var i = 0
    var ans = 0
    while (i < n) {
      ans++
      val c0 = cnt0[i]
      val c1 = cnt1[i]
      i = max(
        if (c0 + k >= p0.size) n else p0[c0 + k],
        if (c1 + k >= p1.size) n else p1[c1 + k]
      )
    }
    ans
  }.joinToString(" ").let { println(it) }
}