import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.lang.Integer.min
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
  val (n1, n2, m) = nextInts(3)
  val a = nextInts(n1)
  val e = Array(n1 + n2) { mutableListOf<Int>() }
  repeat(m) {
    var (x, y) = nextInts(2)
    x--
    y += n1 - 1
    e[x].add(y)
    e[y].add(x)
  }
  val vis = Array(n1 + n2) { false }
  var ans = 0
  for (i in 0 until n1 + n2) {
    if (vis[i]) continue
    var minA = 1000000000
    var cn = 0
    var cm = 0
    fun dfs(v: Int) {
      if (vis[v]) return
      vis[v] = true
      cn++
      cm += e[v].size
      if (v < n1) minA = min(minA, a[v])
      e[v].forEach { dfs(it) }
    }
    dfs(i)
    if (cm == (cn - 1) * 2) ans += minA
  }
  println(ans)
}