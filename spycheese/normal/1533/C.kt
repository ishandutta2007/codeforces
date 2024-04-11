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

fun main() = repeat(nextInt()) {
  val (n, k) = nextInts(2)
  val s = next().map { it != '0' }.toBooleanArray()
  val done = BooleanArray(n) { false }
  var i = 0
  var ans = 0
  var rem = s.count { it }
  var remAll = n
  while (rem > 0) {
    if (remAll != n) {
      i = (i - 1 + n) % n
      repeat((k - 1) % remAll + 1) {
        do {
          i = (i + 1) % n
        } while (done[i])
      }
    }
    done[i] = true
    if (s[i]) rem--
    ans++
    remAll--
  }
  println(ans)
}