import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.lang.Integer.max
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

fun main() {
  val (n, m) = nextInts(2)
  val a1 = IntArray(m)
  val a2 = IntArray(m)
  val cnt = Array(n) { IntArray(n) { 0 } }
  val cnt1 = IntArray(n) { 0 }
  val cnt2 = IntArray(n) { 0 }
  for (i in 0 until m) {
    a1[i] = nextInt() - 1
    a2[i] = nextInt() - 1
    cnt[a1[i]][a2[i]]++
    cnt1[a1[i]]++
    cnt2[a2[i]]++
  }

  var ans = -1
  for (x1 in 0 until n)
    for (x2 in 0 until n) {
      if (x1 == x2) continue
      val me = (if (x1 == a1[0]) 1 else 0) + (if (x2 == a2[0]) 1 else 0)
      val c = IntArray(3)
      c[2] = cnt[x1][x2]
      c[1] = cnt1[x1] + cnt2[x2] - c[2] * 2
      c[0] = m - c[2] - c[1]
      var p = 0
      for (i in me + 1 until 3) p += c[i]
      ans = max(ans, p + 1)
    }
  println(ans)
}