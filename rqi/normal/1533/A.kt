/**
 * Description: Kotlin tips for dummies
 * Source:
 * https://codeforces.com/blog/entry/71089
 * Kotlin Reference
 * https://kotlinlang.org/docs/tutorials/competitive-programming.html
 */
 
/// episode 1: https://codeforces.com/contest/1170
/// episode 2: https://codeforces.com/contest/1211
/// episode 3: https://codeforces.com/contest/1297
// https://github.com/bqi343/USACO/blob/master/Implementations/content/various/kotlinOld.kt
 
import java.io.*
import java.lang.Math.abs
import java.util.*
import kotlin.system.exitProcess
 
// @JvmField val INPUT = File("input.txt").inputStream()
// @JvmField val OUTPUT = File("output.txt").outputStream()
 
/// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.jvm/-jvm-field/
 
class Kattio: PrintWriter {
    @JvmField val r: BufferedReader
    @JvmField var st = StringTokenizer("")
    constructor(): this(System.`in`,System.out) {}
    constructor(i: InputStream, o: OutputStream): super(o,false) { r = i.bufferedReader() }
    fun rLine(): String? = r.readLine()
 
    fun read(): String { // if no input left returns empty string
        while (st.hasMoreTokens().not()) st =
            StringTokenizer(rLine() ?: return "", " ")
        return st.nextToken()
    }
    fun strs(n: Int) = List(n){read()}
    fun ln() = rLine()!!
    fun lns(n: Int) = List(n){ln()}
    fun int() = read().toInt()
    fun ints(n: Int) = List(n){int()}
    fun db() = read().toDouble()
    fun rDbs(n: Int) = List(n){db()}
    fun long() = read().toLong()
    fun longs(n: Int) = List(n){long()}
}
 
val io = Kattio()
//const val MOD = 1000000007
const val MOD = 998244353
const val INF = (1e18).toLong()
const val SZ = 1 shl 17
 
fun YN(b: Boolean) : String { return if (b) "YES" else "NO"  }
fun add(a: Int, b: Int): Int {
    val res = a+b
    return if (res >= MOD) res-MOD else res
}
fun sub(a: Int, b: Int): Int {
    val res = a-b
    return if (res < 0) res+MOD else res
}
fun mul(a: Int, b: Int) = ((a.toLong()*b)%MOD).toInt()
fun mod_pow(a: Int, b: Int): Int {
    if (b == 0) return 1
    if (b%2 == 1) return mul(mod_pow(a,b-1),a)
    return mod_pow(mul(a,a),b/2)
}
fun mod_inv(a: Int): Int = mod_pow(a,MOD-2)
fun gcd(a: Int, b: Int) : Int = if (b == 0) a else gcd(b,a%b)
 
fun example() {
    println(String.format("%.8f", 5.25)) // print to 8 decimals
    val arr2D = Array<IntArray>(5,{IntArray(5,{5})})
    var (x,y) = arrayOf(3,2) // or rInts(2)
    when (x) { //  switch, can be used as expression
        0,1 -> println("x <= 1")
        2 -> println("x == 2") // Note the block
        else -> { println("x is neither 1 nor 2") }
    }
    x = y.also { y = x } // swap x and y
    println("${maxOf(x+2,y)}") // (x,y)=(4,3) -> 4
    val h = HashMap<String,Int>()
    val s = "ababa"
    for (i in 0..s.length-2) {
        val w = s.substring(i,i+2)
        val c = h.getOrElse(w,{0})
        h[w] = c+1
    }
    for ((a,b) in h) println("${a} ${b}") // key,value
    val pq = PriorityQueue<Pair<Long,Int>>(){x,y ->
        x.first.compareTo(y.first)} // or compareBy{it.first}
    val A = arrayListOf(Pair(1,3),Pair(3,2),Pair(2,3))
    val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y ->
        x.first.compareTo(y.first)}) // or sortBy{it.first}
    val list = arrayListOf('a','b','c','d','e')
    println(list.binarySearch('d')) // 3
    list.remove('d')
    val actualInsertPoint = -(list.binarySearch('d')+1) // 3
    list.add(actualInsertPoint, 'd') // [a,b,c,d,e]
    list.removeAt(1) // remove at index -> [a,c,d,e]
}
 
//fun makeArrayList(n: Int): ArrayList<Int> {
//    val res = ArrayList<Int>()
//    for (i in 0 until n) res.add(0)
//    return res
//}
 
//fun allOnes(): ArrayList<Int> {
//    val res = ArrayList<Int>()
//    for (i in 0 until 8192) res.add(1)
//    return res
//}
 
fun empty(): IntArray {  return IntArray(8192){0} }
fun ones(): IntArray {  return IntArray(8192){1} }
val seg = Array<IntArray>(2048){ones()}
 
fun fft(_A: IntArray, inv: Boolean = false): IntArray {
    var A = _A.copyOf()
    val n = A.size
    var b = n/2
    var B = empty()
    while (b > 0) {
        val w = mod_pow(5,(MOD-1)/n*b)
        var m = 1 // n/b'th root of unity
        var i = 0
        while (i < n) {
            for (j in 0 until b) {
                val u = A[i+j]
                val v = mul(A[i+j+b],m);
                B[i / 2 + j] = add(u,v);
                B[i / 2 + j + n / 2] = sub(u,v);
            }
            i += b*2
            m = mul(m,w)
        }
        b /= 2
        A = B.also{ B = A}
    }
    if (inv) {
        var i = 1
        while (i < A.size-i) {
            A[i] = A[A.size-i].also{A[A.size-i] = A[i]}
            ++i
        }
        val z = mod_inv(n);
        for (i in 0 until n) A[i] = mul(A[i],z)
    }
    return A
}
 
fun makeOnes(w: Int, n: Int): IntArray {
    val res = empty()
    for (i in 0..n) res[i*w] = 1
    return res
}
 
fun comb(a: IntArray, b: IntArray): IntArray {
    val c = empty()
    for (i in 0 until 8192) c[i] = mul(a[i],b[i])
    return c
}
 
fun qrange(_l: Int, _r: Int):  IntArray {
    var l = _l+1024
    var r = _r+1025
    var res = ones()
    while (l < r) {
        if (l%2 == 1) res = comb(res,seg[l++])
        if (r%2 == 1) res = comb(res,seg[--r])
        l /= 2
        r /= 2
    }
    return res
}
 
fun solve() {
//    val (a,b,k) = io.longs(3)
//    io.println((k+1)/2*a-k/2*b)
//    val n = io.int()
//    val a = io.ints(n).sorted()
////    println(a)
//    var ans = 0
//    for (i in 0 until n/2) ans += a[2*i+1]-a[2*i]
//    println(ans)
    
    val n = io.int()
    val k = io.int()
    
    var ans = 0
    for (i in 1..n) {
        val l = io.int()
        val r = io.int()
        
        if(l <= k && k <= r){
            ans = maxOf(ans, r-k+1)
        }
    }
    
    println(ans)
}
 
fun main() {
    val t = io.int()
    repeat(t) { solve() }
    io.close()
}