import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
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
fun nextInts(n: Int) = Array(n) { nextInt() }
fun nextLongs(n: Int) = Array(n) { nextLong() }
fun nextDoubles(n: Int) = Array(n) { nextDouble() }

fun main() = repeat(nextInt()) {
  val n = nextInt()
  val k = nextInt()
  val ans = (0 until n).maxOf {
    val l = nextInt()
    val r = nextInt()
    if (l > k || r < k) 0 else r - k + 1
  }
  println(ans)
}