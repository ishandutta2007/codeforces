import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.lang.Integer.min
import java.util.*
import javax.security.auth.callback.ConfirmationCallback.OK

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

val CORR = intArrayOf(
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 1, 0, 0, 0
)

fun main() = repeat(nextInt()) {
  val n = nextInt()
  val s = next().map { if (it == '(') 0 else 1 }.toIntArray()
  val a = next().map { if (it == '0') 0 else 1 }.toIntArray()

  var d = IntArray(8)
  for (mask in 0..7)
    for (i in 0..2)
      if (((mask shr i) and 1) != s[i])
        d[mask]++

  for (ii in 0 until a.size) {
    val x = s[ii + 3]
    val nd = IntArray(8) { 1000000000 }
    for (mask in 0..7) {
      if (d[mask] > n) continue
      for (x1 in 0..1) {
        val cd = d[mask] + if (x == x1) 0 else 1
        val mask2 = mask + x1 * 8
        if (a[ii] == 0 || CORR[mask2] == 1) {
          nd[mask2 / 2] = min(nd[mask2 / 2], cd)
        }
      }
    }
    d = nd
  }

  println(d.minOrNull()?.takeIf { it <= n } ?: -1)
}