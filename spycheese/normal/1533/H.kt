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
  val (sx, sy) = nextInts(2)
  val a = Array(sx) { next().map { it - 'A' }.toIntArray() }
  val d = LongArray(32)
  val d2 = LongArray(6) { 0 }
  for (mask in 1 until 32) {
    var res: Long = 0

    val c = IntArray(sy) { 0 }
    for (x in 0 until sx) {
      for (y in 0 until sy) {
        if ((mask and (1 shl a[x][y])) == 0) {
          c[y] = 0
        } else{
          c[y]++
        }
      }
      val p1 = IntArray(sy)
      val s = mutableListOf<Int>()
      for (y in 0 until sy) {
        while (s.isNotEmpty() && c[s.last()] > c[y]) s.removeLast()
        p1[y] = s.lastOrNull() ?: -1
        s.add(y)
      }
      val p2 = IntArray(sy)
      s.clear()
      for (y in sy - 1 downTo 0) {
        while (s.isNotEmpty() && c[s.last()] >= c[y]) s.removeLast()
        p2[y] = s.lastOrNull() ?: sy
        s.add(y)
      }
      for (y in 0 until sy) {
        res += c[y].toLong() * (p2[y] - y).toLong() * (y - p1[y]).toLong()
      }
    }

    d[mask] = res
    val cnt = (0 until 5).count { (mask and (1 shl it)) != 0 }
    for (mask2 in 1 until 32)
      if ((mask2 and mask) == mask2 && mask != mask2)
        d[mask] -= d[mask2]
    d2[cnt] += d[mask]
  }
  println(d2.drop(1).joinToString(" "))
}