import java.io.BufferedReader
import java.io.InputStream
import java.io.InputStreamReader
import java.lang.Integer.max
import java.util.*
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

class SegTree(val gl: Int, val gr: Int, initF: ((Node, Int) -> Unit)? = null) {
  class Node {
    var tmax: Long = 0

    fun setX(x: Long) {
      tmax = x
    }

    fun update(cl: Int, cr: Int, l: Node, r: Node) {
      tmax = max(l.tmax, r.tmax)
    }
  }

  private val t = Array((gr - gl) * 4) { Node() }

  private fun update(c: Int, cl: Int, cr: Int) = t[c].update(cl, cr, t[c * 2 + 1], t[c * 2 + 2])
  private fun push(c: Int, cl: Int, cr: Int) = Unit

  private fun build(c: Int, cl: Int, cr: Int, initF: ((Node, Int) -> Unit)?) {
    if (cl + 1 == cr) {
      initF?.invoke(t[c], cl)
    } else {
      val mid = (cl + cr) / 2
      build(c * 2 + 1, cl, mid, initF)
      build(c * 2 + 2, mid, cr, initF)
      update(c, cl, cr)
    }
  }

  init {
    build(0, gl, gr, initF)
  }

  constructor(n: Int) : this(0, n)
  constructor(n: Int, initF: ((Node, Int) -> Unit)?) : this(0, n, initF)

  fun getLeaf(i: Int): Node {
    var c = 0
    var cl = gl
    var cr = gr
    while (cl + 1 != cr) {
      push(c, cl, cr)
      val mid = (cl + cr) / 2
      if (i < mid) {
        c = c * 2 + 1
        cr = mid
      } else {
        c = c * 2 + 2
        cl = mid
      }
    }
    return t[c]
  }

  private fun <R> withLeaf(i: Int, foo: (Node) -> R, c: Int, cl: Int, cr: Int): R {
    if (cl + 1 == cr) return foo(t[c])
    push(c, cl, cr)
    val mid = (cl + cr) / 2
    return if (i < mid) {
      withLeaf(i, foo, c * 2 + 1, cl, mid)
    } else {
      withLeaf(i, foo, c * 2 + 2, mid, cr)
    }.also {
      update(c, cl, cr)
    }
  }

  fun <R> withLeaf(i: Int, foo: (Node) -> R): R {
    return withLeaf(i, foo, 0, gl, gr)
  }

  private fun withSeg(l: Int, r: Int, foo: (Node, Int, Int) -> Unit, c: Int, cl: Int, cr: Int) {
    if (cr <= l || r <= cl) return
    if (l <= cl && cr <= r) {
      foo(t[c], cl, cr)
      return
    }
    push(c, cl, cr)
    val mid = (cl + cr) / 2
    withSeg(l, r, foo, c * 2 + 1, cl, mid)
    withSeg(l, r, foo, c * 2 + 2, mid, cr)
    update(c, cl, cr)
  }

  fun withSeg(l: Int, r: Int, foo: (Node, Int, Int) -> Unit) = withSeg(l, r, foo, 0, gl, gr)
  fun withSegS(l: Int, r: Int, foo: (Node) -> Unit) = withSeg(l, r, { it, _, _ -> foo(it) }, 0, gl, gr)

  fun getMax(l: Int, r: Int): Long {
    var s = 0L
    withSegS(l, r) { s = max(s, it.tmax) }
    return s
  }
}

data class Point(val x: Int, val y: Int, val a: Long): Comparable<Point> {
  override fun compareTo(other: Point): Int {
    if (y == other.y) return x.compareTo(other.x)
    return other.y.compareTo(y)
  }
}

fun main() {
  val (n, m0) = nextInts(2)
  val ps = mutableListOf<Point>()
  for (i in 0 until n) {
    val k = nextInt()
    val aa = nextInts(k)
    val bb = nextInts(k)
    for (j in 0 until k) {
      val a = aa[j]
      val y = bb[j]
      val x = i + y
      ps.add(Point(x, y, a.toLong()))
    }
  }
  ps.sort()

  val st = SegTree(700000)
  var ans = 0L
  val x0 = m0
  val y0 = m0
  for (p in ps) {
    if (p.x < x0 || p.y > y0) continue
    val m = st.getMax(0, p.x)
    val d = p.a + m
    st.withLeaf(p.x) { it.setX(max(it.tmax, d)) }
    ans = max(ans, d)
  }

  println(ans)
}