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
fun nextInts(n: Int) = IntArray(n) { nextInt() }
fun nextLongs(n: Int) = LongArray(n) { nextLong() }
fun nextDoubles(n: Int) = DoubleArray(n) { nextDouble() }

val DIRS = arrayOf(
  Pair(1, 0),
  Pair(0, 1),
  Pair(-1, 0),
  Pair(0, -1)
)

fun main() = repeat(nextInt()) {
  val (sx, sy) = nextInts(2)
  val a = Array(sx) { nextInts(sy) }
  val k = a.sumOf { b -> b.count { it != 0 } }
  val seq = mutableListOf<Int>()
  val vis = Array(sx) { Array(sy) { false } }
  var visCnt = 0
  fun dfs(x: Int, y: Int): Boolean {
    if (x < 0 || y < 0 || x >= sx || y >= sy || a[x][y] == 0 || vis[x][y]) return false
    ++visCnt
    vis[x][y] = true
    seq.add(a[x][y])
    for ((dx, dy) in DIRS) {
      if (dfs(x + dx, y + dy)) seq.add(a[x][y])
    }
    return true
  }
  loop@ for (x in 0 until sx) {
    for (y in 0 until sy) {
      if (a[x][y] != 0) {
        dfs(x, y)
        break@loop
      }
    }
  }
  if (visCnt != k) {
    println(-1)
  } else {
    val s = (seq.size + 1) / 2
    println("$s $s")
    (0 until s).joinToString("\n") { x ->
      (0 until s).map { y -> seq[x + y] }.joinToString(" ")
    }.let { println(it) }
  }
}