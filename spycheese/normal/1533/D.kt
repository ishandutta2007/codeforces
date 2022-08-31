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
  val (n, m) = nextInts(2)
  val s = nextStrings(n).toSet()
  repeat(nextInt()) {
    val t = next()
    val s2 = HashSet<String>()
    var ans = 0
    for (i in 0..m) {
      val t1 = t.substring(0, i) + t.substring(i + 1, m + 1)
      if (s2.add(t1) && t1 in s) ans++
    }
    println(ans)
  }
}