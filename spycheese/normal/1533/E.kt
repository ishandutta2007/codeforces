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
fun nextInts(n: Int) = IntArray(n) { nextInt() }
fun nextLongs(n: Int) = LongArray(n) { nextLong() }
fun nextDoubles(n: Int) = DoubleArray(n) { nextDouble() }

fun main() {
  val n = nextInt()
  val a = nextInts(n)
  val b = nextInts(n + 1)
  Arrays.sort(a)
  Arrays.sort(b)

  val m1 = IntArray(n + 1)
  m1[0] = (-1.1e9).toInt()
  for (i in 0 until n) m1[i + 1] = max(m1[i], b[i] - a[i])
  val m2 = IntArray(n + 1)
  m2[n] = (-1.1e9).toInt()
  for (i in n - 1 downTo 0) m2[i] = max(m2[i + 1], b[i + 1] - a[i])

  nextInts(nextInt()).map { c ->
    val i = a.binarySearch(c).let { if (it >= 0) it else -(it + 1) }
    max(max(m1[i], m2[i]), b[i] - c)
  }.joinToString(" ").let { println(it) }
}