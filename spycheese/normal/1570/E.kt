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
  repeat(reader.nextInt()) {
    val s = reader.next()
    if (s.all { it == '0' }) {
      println(0)
    } else {
      val i = s.indexOfFirst { it == '1' }
      val j = s.indexOfLast { it == '1' }
      println(s.subSequence(i, j).count { it == '0' })
    }
  }
}