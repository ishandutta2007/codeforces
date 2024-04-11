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
  val a = Array(sx) { nextInts(sy) }
  val b = Array(sx) { Array(sy) { 0 } }
  val ans = ArrayList<Pair<Int, Int>>()
  for (i in 0 until sx - 1) {
    for (j in 0 until sy - 1) {
      if (a[i][j] == 1 && a[i+1][j] == 1 && a[i][j+1] == 1 && a[i+1][j+1] == 1) {
        ans.add(Pair(i, j))
        b[i][j] = 1
        b[i+1][j] = 1
        b[i+1][j+1] = 1
        b[i][j+1] = 1
      }
    }
  }
  if (a.flatten() == b.flatten()) {
    println(ans.size)
    ans.forEach { println("${it.first + 1} ${it.second + 1}") }
  } else {
    println(-1)
  }
}