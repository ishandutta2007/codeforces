import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.lang.Integer.max
import java.lang.Integer.min
import java.util.*

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

fun main() = repeat(nextInt()) {
  var k1 = 0
  var k2 = 1000000
  repeat(nextInt()) {
    val s1 = next().reversed()
    val s2 = next().reversed()
    val r = nextInt()
    var q = 0
    while (q < s1.length && q < s2.length && s1[q] == s2[q]) ++q
    if (r == 1) {
      k2 = min(k2, q)
    } else {
      k1 = max(k1, q + 1)
    }
  }
  if (k1 > k2)
    println(0)
  else {
    println(k2 - k1 + 1)
    println((k1..k2).joinToString(" "))
  }
}