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

class Node {
  val e = IntArray(26) { -1 }
  var word = false
}

const val MOD = 998244353

fun mul(a: Array<IntArray>, b: Array<IntArray>, c: Array<IntArray>) {
  val n = a.size
  val k = b.size
  val m = b[0].size
  for (i in 0 until n) {
    for (j in 0 until m) {
      var x = 0L
      for (q in 0 until k) {
        x = (x + a[i][q].toLong() * b[q][j].toLong()) % MOD
      }
      c[i][j] = x.toInt()
    }
  }
}

fun identity(n: Int) = Array(n) { i -> IntArray(n) { j -> if (i == j) 1 else 0 } }

fun pow(a: Array<IntArray>, b: Int): Array<IntArray> {
  var r = identity(a.size)
  var r2 = identity(a.size)
  var aa = a
  var aa2 = identity(a.size)
  var bb = b
  while (true) {
    if (bb and 1 == 1) {
      mul(r, aa, r2)
      r = r2.also { r2 = r }
    }
    bb = bb shr 1
    if (bb == 0) break
    mul(aa, aa, aa2)
    aa = aa2.also { aa2 = aa }
  }
  return r
}

fun main() {
  val (words, len) = nextInts(2)
  val vs = mutableListOf<Node>(Node())
  repeat(words) {
    val s = next()
    var v = 0
    for (cc in s) {
      val c = cc - 'a'
      if (vs[v].e[c] == -1) {
        vs[v].e[c] = vs.size
        vs.add(Node())
      }
      v = vs[v].e[c]
    }
    vs[v].word = true
  }

  val n = vs.size
  val a = Array(n * n) { i ->
    val row = IntArray(n * n) { 0 }
    val v1 = i % n
    val v2 = i / n
    for (c in 0 until 26) {
      var u1 = vs[v1].e[c].takeIf { it != -1 } ?: continue
      var u2 = vs[v2].e[c].takeIf { it != -1 } ?: continue
      if (u1 > u2) u1 = u2.also { u2 = u1 }
      row[u1 + u2 * n]++
      if (vs[u1].word) row[u2 * n]++
      if (vs[u2].word) row[u1 * n]++
      if (vs[u1].word && vs[u2].word) row[0]++
    }
    row
  }
  val vis1 = BooleanArray(n * n) { false }
  val vis2 = BooleanArray(n * n) { false }
  val ll = mutableListOf<Int>()
  fun dfs1(v: Int) {
    if (vis1[v]) return
    vis1[v] = true
    (0 until n * n).filter { a[v][it] != 0 }.forEach(::dfs1)
  }
  fun dfs2(v: Int) {
    if (vis2[v]) return
    vis2[v] = true
    if (vis1[v]) ll.add(v)
    (0 until n * n).filter { a[it][v] != 0 }.forEach(::dfs2)
  }
  dfs1(0)
  dfs2(0)
  val b = Array(ll.size) { i ->
    IntArray(ll.size) { j ->
      a[ll[i]][ll[j]]
    }
  }
  println(pow(b, len)[0][0])
}