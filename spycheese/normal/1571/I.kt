import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.lang.Long.max
import java.lang.Long.min
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
  val n = nextInt()
  val ls = nextLongs(n)
  val rs = nextLongs(n)
  for (i in 0 until n) rs[i]++
  var x1 = -1000000000000L
  var x2 = 1000000000000L

  rs.sorted().forEachIndexed { i, v ->
    x2 = min(x2, v - (i + 1))
  }
  ls.sorted().forEachIndexed { i, v ->
    x1 = max(x1, v - i)
  }

  if (x1 > x2) {
    println("-1")
  } else {
    data class Seg(val l: Long, val r: Long, val i: Int): Comparable<Seg> {
      override fun compareTo(other: Seg): Int {
        return l.compareTo(other.l)
      }
    }
    println(x1)
    val segs = (0 until n).map { i -> Seg(ls[i], rs[i], i) }.toTypedArray()
    val ans = mutableListOf<Int>()
    val ss = sortedSetOf<Pair<Long, Int>>(compareBy<Pair<Long, Int>> { it.first }.thenBy { it.second })
    var j = 0
    segs.sort()
    for (i in 0 until n) {
      val x = x1 + i.toLong()
      while (j < segs.size && segs[j].l <= x) {
        ss.add(Pair(segs[j].r, segs[j].i))
        j++
      }
      ans.add(1 + ss.first().second)
      ss.remove(ss.first())
    }
    println(ans.joinToString(" "))
  }
}