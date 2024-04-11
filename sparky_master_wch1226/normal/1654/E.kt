
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.math.absoluteValue
import kotlin.random.Random
import kotlin.random.nextInt
import kotlin.system.measureTimeMillis

inline fun TIME(f:()->Unit){
    val t = measureTimeMillis(){
        f()
    }
    println("$t ms")
}

object IO{
    private const val BS = 1 shl 16
    private const val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC

    var warningActive = true
    var fakein = StringBuilder()

    private var IN: BufferedInputStream = BufferedInputStream(System.`in`, BS)
    val OUT: PrintWriter = PrintWriter(System.out)

    private val char: Char
        get() {
            while (bId == size) {
                size = IN.read(buf) // no need for checked exceptions
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toChar()
        }

    fun nextInt(): Int {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
    fun nextLong(): Long {
        var neg = false
        if (c == NC) c = char
        while (c < '0' || c > '9') {
            if (c == '-') neg = true
            c = char
        }
        var res = 0L
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        return if (neg) -res else res
    }
    fun nextString():String{
        val ret = StringBuilder()
        while (true){
            c = char
            if(!isWhitespace(c)){ break}
        }
        ret.append(c)
        while (true){
            c = char
            if(isWhitespace(c)){ break}
            ret.append(c)
        }
        return ret.toString()
    }
    fun isWhitespace(c:Char):Boolean{
        return c == ' ' || c == '\n' || c == '\r' || c == '\t'
    }
    fun rerouteInput(){
        if(warningActive){
            put("You forgot to disable tests you digital dummy!")
            println("You forgot to disable tests you digital dummy!")
            warningActive = false
        }
        val S = fakein.toString()
        println("New Case ")
        println(S.take(80))
        println("...")
        fakein.clear()
        IN = BufferedInputStream(S.byteInputStream(),BS)
    }
    fun takeFile(name:String){
        IN = BufferedInputStream(File(name).inputStream(),BS)
    }
}
fun put(aa:Any){ IO.OUT.println(aa)}
fun done(){ IO.OUT.close() }
fun share(aa:Any){
    if(aa is IntArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is LongArray){IO.fakein.append(aa.joinToString(" "))}
    else if(aa is List<*>){IO.fakein.append(aa.toString())}
    else{IO.fakein.append(aa.toString())}
    IO.fakein.append("\n")
}

val getint:Int get() = IO.nextInt()
val getlong:Long get() = IO.nextLong()
val getstr:String get() = IO.nextString()
fun getline(n:Int):IntArray{
    return IntArray(n){getint}
}
fun getlineL(n:Int):LongArray{
    return LongArray(n){getlong}
}
fun getbinary(n:Int, asTrue:Char):BooleanArray{
    val str = getstr
    return BooleanArray(n){str[it] == asTrue}
}

val List<Char>.ret:String
get() = this.joinToString("")
var dmark = -1
infix fun Any.dei(a:Any){
    //does not stand for anything it is just easy to type, have to be infix because kotlin does not have custom prefix operators
    dmark++
    var str = "<${dmark}>   "
    debug()
    if(this is String){ str += this
    }else if(this is Int){ str += this.toString()
    }else if(this is Long){ str += this.toString()
    }else{ str += this.toString()}
    if(a is List<*>){ println("$str : ${a.joinToString(" ")}")
    }else if(a is IntArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is LongArray){ println("$str : ${a.joinToString(" ")}")
    }else if(a is BooleanArray){ println("$str :${a.map{if(it)'1' else '0'}.joinToString(" ")}")
    }else if(a is Array<*>){
        println("$str : ")
        for(c in a){if(c is IntArray){println(c.joinToString(" "))}
        else if(c is LongArray){println(c.joinToString(" "))}
        else if(c is BooleanArray){println(c.map { if(it) '1' else '0' }.joinToString(""))
        }

        }
        println()
    }else{ println("$str : $a")
    }
}
val just = " " // usage: just dei x , where x is the debug variable
fun crash(){
    throw Exception("Bad programme")} // because assertion does not work
fun assert(a:Boolean){
    if(!a){
        throw Exception("Failed Assertion")
    }}
enum class solveMode {
    real, rand, tc
}
object solve{
    var mode:solveMode = solveMode.real
    var tcNum:Int = 0
    var rand:()->Unit = {}
    var TC:MutableMap<Int,()->Unit> = mutableMapOf()
    var answersChecked = 0
    var tn:Long = 0
    fun cases(onecase:()->Unit){
        val t = if(mode == solveMode.real){if(singleCase) 1 else getint} else if(mode == solveMode.tc){1 } else randCount
        //safety checks
        if(pI != 998_244_353 && pI != 1_000_000_007){
            throw Exception("Modding a wrong prime!")
        }
        if(withBruteForce){
            println("Brute force is active")
        }

        if(t == 1 && mode != solveMode.real){
            tn = System.currentTimeMillis()
        }
        repeat(t){
            if(mode == solveMode.tc){
                TC[tcNum]?.let { it() }
                IO.rerouteInput()
            }else if(mode == solveMode.rand){
                rand()
                IO.rerouteInput()
            }
            onecase()
        }
        if(t == 1 && mode != solveMode.real){
            val dt = System.currentTimeMillis() - tn
            println("Time $dt ms ")
        }
    }
    inline fun singleCase(a:solve.()->Unit){
        val t = if(mode != solveMode.rand){1} else randCount
        repeat(t) { a() }
    }
    fun rand(a:()->Unit){
        this.rand = a
    }
    fun tc(id:Int = 0,a:()->Unit){
        TC[id] = a
    }
    fun usetc(a:Int = 0 ){
        this.tcNum = a
        this.mode = solveMode.tc
    }
    fun userand(){
        this.mode = solveMode.rand
    }
}
inline fun<T> T.alsoBrute(cal:() -> T){
    if(!withBruteForce) return
    val also = cal()
    if(this != also){
        println("Checking failed: Got ${this} Brute ${also}")
        crash()
    }
}
// 1. Modded
const val p = 1000000007L
const val pI = p.toInt()
fun Int.adjust():Int{ if(this >= pI){ return this  - pI }else if (this < 0){ return this + pI };return this }
fun Int.snap():Int{ if(this >= pI){return this - pI} else return this}
infix fun Int.modM(b:Int):Int{ return ((this * 1L * b) % pI).toInt() }
infix fun Int.modPlus(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
// 2. DP initial values
const val plarge = 1_000_000_727
const val nlarge = -plarge
const val phuge = 2_727_000_000_000_000_000L
const val nhuge = -phuge
// 3. conveniecen conversions
val Boolean.chi:Int get() = if(this) 1 else 0 //characteristic function
val Char.code :Int get() = this.toInt() -  'a'.toInt()
//3. hard to write stuff
fun IntArray.put(i:Int,v:Int){ this[i] = (this[i] + v).adjust() }
val mint:MutableList<Int> get() = mutableListOf<Int>()
val mong:MutableList<Long> get() = mutableListOf<Long>()
//4. more outputs
fun List<Char>.conca():String = this.joinToString("")
val CharArray.conca :String get() = this.joinToString("")
val IntArray.conca :String get() = this.joinToString(" ")
@JvmName("concaInt")
fun List<Int>.conca():String = this.joinToString(" ")
val LongArray.conca:String get() = this.joinToString(" ")
@JvmName("concaLong")
fun List<Long>.conca():String = this.joinToString(" ")
//5. Pair of ints
const val longmask = (1L shl 32) - 1
fun makepair(a:Int, b:Int):Long = (a.toLong() shl 32) xor (longmask and b.toLong()) // remember positev sonly
val Long.first get() = (this ushr 32).toInt()
val Long.second get() = this.toInt()
//6. strings
val String.size get() = this.length
const val randCount = 100

tailrec fun gcd(a: Int, b: Int): Int {
    if(b == 0) return a
    return if (a % b == 0) Math.abs(b) else gcd(b, a % b)
}
tailrec fun gcd(a: Long, b: Long): Long {
    if(b == 0L) return a
    return if (a % b == 0L) Math.abs(b) else gcd(b, a % b)
}

fun debug(){}
const val withBruteForce = false
const val singleCase = true
const val maxn = 100100
const val cut = 300

private const val radixLog = 11
private const val radixBase = 1 shl radixLog
private const val radixMask = radixBase - 1
fun countSort(arr: IntArray, n: Int, expB: Int) {
    val output = IntArray(n)
    val count = IntArray(radixBase)
    for(i in 0 until n) {
        count[(arr[i] shr expB) and radixMask]++
    }
    for(i in 1 until radixBase){
        count[i] += count[i - 1]
    }
    for(i in n-1 downTo 0 ){
        output[count[(arr[i] shr expB) and radixMask] - 1] = arr[i]
        count[(arr[i] shr expB) and radixMask]--
    }
    for(i in 0 until n){
        arr[i] = output[i]
    }
}
fun IntArray.radixsort() {
    //Positives only!
    val n = this.size
    var b = 0
    repeat(3){
        countSort(this, n, b)
        b += radixLog
    }
}
private typealias ei = Int
private typealias earr = IntArray
//NOT batle tested
class fastDeque(val l:Int, val r:Int) {
    val total = r - l + 1
    val st = earr(total)
    var startpointer = 0 - l
    var endpointer = startpointer - 1
    val size: Int get() = endpointer - startpointer + 1

    fun isEmpty(): Boolean {
        return endpointer < startpointer
    }
    fun isNotEmpty():Boolean{
        return endpointer >= startpointer
    }
    fun first():ei{
        assert(isNotEmpty())
        return st[startpointer]
    }
    fun last():ei{
        assert(isNotEmpty())
        return st[endpointer]
    }
    fun addFirst(v:ei ){
        startpointer --
        st[startpointer]= v
    }
    fun addLast(v:ei){
        endpointer ++
        st[endpointer] = v
    }
    fun removeFirst(): Int {
        assert(isNotEmpty())
        val ret = st[startpointer]
        startpointer ++
        return ret
    }
    fun removeLast(): Int {
        assert(isNotEmpty())
        val ret = st[endpointer]
        endpointer --
        return ret
    }
    fun toArray():earr{
        return st.sliceArray(startpointer..endpointer)
    }
    fun toList():List<ei>{
        return st.slice(startpointer..endpointer)
    }

    inline fun forEach(act:(v:ei)->Unit){
        for(i in startpointer..endpointer){
            act(st[i])
        }
    }
    inline fun withIndex(act:(i:Int,v:ei)->Unit){
        for(i in startpointer..endpointer){
            act(i-startpointer,st[i])
        }
    }
}
fun fastEmptyList(max:Int):fastDeque{
    return fastDeque(0,max-1)
}

fun maxOccurence(a:IntArray):Int{
    val new = a.copyOf()
    new.radixsort()
    var last = 1
    var ret = 1
    for(i in 1..a.lastIndex){
        if(new[i] != new[i-1]){
            last = 1
        }else{
            last ++
            ret = maxOf(ret,last)
        }
    }
    return ret
}
fun main(){
    solve.tc {
        share(100000)
        share(List(100000){Random.nextInt(1..100000)}.conca())
    }
//    solve.usetc()
    solve.cases{
        val n = getint
        val L = getline(n)
        if(n <= 2){
            put(0)
            return@cases
        }
        val lstart = L.copyOf()
        for(i in 0 until n){
            lstart[i] += i * (-(cut+1))
            lstart[i] += plarge
        }
        var max = 2


//        val map = HashMap<Int,Int>( maxn/3 * 4 + 5)
//        TIME {
            for(slope in -cut..cut) {
//                map.clear()


                for(i in 0 until n) {
                    lstart[i] += i
                }
                max = maxOf(max,maxOccurence(lstart))
//                for(a in lstart) {
//                    map[a] = map.getOrDefault(a, 0) + 1
//                }
//                for(v in map.values) {
//                    max = maxOf(max, v)
//                }
            }
//        }

        val cutremains = (maxn / cut)+1
        val F = IntArray(200001)
        val shift = 100000
        val undo = IntArray(cutremains + 1 )
//        val needatleast = IntArray(cutremains + 1){it * cut}
        for(l in 0 until n){
//            val right = minOf(n-1, left + 2 * cutremains)
//
//            for(l in left..right){
//                val all = mutableMapOf<Long,Int>()


            var pt = -1

            for(r in l+1..minOf(n-1,(l + cutremains))){
                val ci = r - l
                val dif = L[r] - L[l]
                if(dif % ci != 0) continue
                val nt = (dif / ci) + shift
                F[nt]++
                pt ++
                undo[pt] = nt
                max = maxOf(max,F[nt]+1 )
            }
            for(i in 0..pt){
                F[undo[i]] --
            }
            pt = 0




//                for(r in l+1..right){
//                    val a = L[l]
//                    val b = L[r]
//                    val ci = r - l
//                    val cd = (b-a).absoluteValue
////                    val dif = (b-a).absoluteValue
//                    if(cd < needatleast[ci]) continue
//
//                }

        }



////        val skip = BooleanArray(cutremains + 1 )
//        for(left in 0 until n){
////            skip.fill(false)
//            for(right in left+1 .. (left + cutremains)){
//                if(right >= n) continue
////                if(skip[right - left]) continue
//                val a = L[left]
//                val b = L[right]
//                val ci = right - left
//                val dif = (b-a).absoluteValue
//                if(dif < needatleast[ci]){
//                     continue
//                }
//
//                val cd = b - a
//                var demand = b
//                var herenow = 2
//                for(next in right+ci until n step ci){
//                    demand += cd
//                    if(demand > maxn || demand < - maxn){
//                        break
//                    }
//                    if(L[next] == demand){
//                        herenow ++
////                        skip[next-left] = true
//                    }
//                }
//                max = maxOf(max, herenow)
//            }
//        }


        put(n-max)



    }
    done()
}
/*
3
71 142 213
 */