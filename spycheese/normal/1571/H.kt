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
fun nextInts(n: Int) = IntArray(n) { nextInt() }
fun nextLongs(n: Int) = LongArray(n) { nextLong() }
fun nextDoubles(n: Int) = DoubleArray(n) { nextDouble() }

const val MOD = 998244353L

fun pw(a: Long, b: Long): Long {
  var r = 1L
  var aa = a
  var bb = b
  while (bb != 0L) {
    if ((bb and 1L) != 0L) r = r * aa % MOD
    aa = aa * aa % MOD
    bb = bb shr 1
  }
  return r
}

fun calcProb(ps: List<Long>): Long {
  var p = 1L
  for (p1 in ps) {
    p = p * (1L - p1) % MOD
  }
  p = (1 - p) % MOD
  if (p < 0) p += MOD
  return p
}

fun main() {
  var (n, sx, sy) = nextInts(3)
  sx *= 2
  sy *= 2

  val hor = Array(sy + 1) { mutableListOf<Long>() }
  val ver = Array(sx + 1) { mutableListOf<Long>() }
  val dg1 = Array(sx + sy + 1) { mutableListOf<Long>() }
  val dg2 = Array(sx + sy + 1) { mutableListOf<Long>() }
  hor[0].add(1)
  hor[sy].add(1)
  ver[0].add(1)
  ver[sx].add(1)

  repeat(n) {
    var (x, y) = nextInts(2)
    x *= 2
    y *= 2
    val p = nextLong() * pw(1000000, MOD - 2) % MOD
    hor[y].add(1)
    ver[x].add(1)
    dg1[x - y + sy].add(p)
    dg2[x + y].add(p)
  }

  val horP = hor.map { calcProb(it) }.toLongArray()
  val verP = ver.map { calcProb(it) }.toLongArray()
  val dg1P = dg1.map { calcProb(it) }.toLongArray()
  val dg2P = dg2.map { calcProb(it) }.toLongArray()

  var cv = 0L
  var ce = 0L

  for (x in 0..sx)
    for (y in 0..sy) {
      val p1 = horP[y]
      val p2 = verP[x]
      val p3 = dg1P[x - y + sy]
      val p4 = dg2P[x + y]
      cv += calcProb(listOf(p1, p2, p3, p4))
      if (cv >= MOD) cv -= MOD

      ce += if (x == 0 || x == sx) p1 else p1 * 2
      ce += if (y == 0 || y == sy) p2 else p2 * 2
      ce += if (x == 0 || x == sx || y == 0 || y == sy) p3 else p3 * 2
      ce += if (x == 0 || x == sx || y == 0 || y == sy) p4 else p4 * 2
      ce %= MOD
    }

  ce = ce * pw(2, MOD - 2) % MOD
  var ans = (1 - cv + ce) % MOD
  if (ans < 0) ans += MOD
  println(ans)
}