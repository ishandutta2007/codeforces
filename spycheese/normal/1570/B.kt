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

  fun nextInt() = next().toInt()
  fun nextLong() = next().toLong()
  fun nextDouble() = next().toDouble()
  fun nextStrings(n: Int) = Array(n) { next() }
  fun nextInts(n: Int) = Array(n) { nextInt() }
  fun nextLongs(n: Int) = Array(n) { nextLong() }
  fun nextDoubles(n: Int) = Array(n) { nextDouble() }
}
val reader = MyReader(System.`in`)

fun main() {
  var a1 = reader.nextInt()
  var a2 = reader.nextInt()
  var k1 = reader.nextInt()
  var k2 = reader.nextInt()
  val n = reader.nextInt()

  if (k1 > k2) {
    a1 = a2.also { a2 = a1 }
    k1 = k2.also { k2 = k1 }
  }

  val m1 = max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1))
  val m2 = if (n <= a1 * k1) n / k1 else a1 + (n - a1 * k1) / k2
  println("$m1 $m2")
}