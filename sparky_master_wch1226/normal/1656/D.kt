
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
import kotlin.math.ln
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


/*
 condition 1 :
    at least (k-1)(k) / 2


    2s

    (2s-1)s ( mod 2s)
    = s (mod 2s)

    2^20 * 3

    1 2

    is that mod k

    if k is odd

    2,3
    3,4 4,5

    not smallest odd primes

    so what is

    15, 20




 */


 object sieve{

     const val sieveMx = 50000
     val primeOf = IntArray(sieveMx + 1)
     var primeCounter = 0
     val primeUpperBound = maxOf(25,(sieveMx.toDouble()/(ln(sieveMx.toDouble()) -4)).toInt() +3)
     val primes = IntArray(primeUpperBound)
     var sieveCalculated = false
     val nextPrime = IntArray(sieveMx+1)
     val nextPrimePower = IntArray(sieveMx+1)
     val afterPrimePowerDivison = IntArray(sieveMx+1)
     var mobius = IntArray(0)

     var factors:List<MutableList<Int>> = mutableListOf()

     fun calculateSieveFast(){
         if(sieveCalculated){
             return
         }
         sieveCalculated = true
         for(i in 2..sieveMx){
             if(primeOf[i] == 0 ){
                 primeOf[i] = i
                 primes[primeCounter] = i
                 primeCounter += 1
             }
             for(j in 0 until primeCounter){
                 val p = primes[j]
                 val pd = p * i
                 if(p <= i && pd <= sieveMx){
                     primeOf[pd] = p
                 }else{
                     break
                 }
             }
         }
     }
     fun preparePrimePower(){
         nextPrime[1] = -1
         nextPrimePower[1] = -1
         afterPrimePowerDivison[1] = 1
         for(i in 2..sieveMx){
             val p = primeOf[i]
             val new = i / p
             nextPrime[i] = p
             if(nextPrime[new] == p){
                 nextPrimePower[i] = nextPrimePower[new]
                 afterPrimePowerDivison[i] = afterPrimePowerDivison[new]
             }else{
                 afterPrimePowerDivison[i] = new
             }
             nextPrimePower[i] += 1
         }
     }
     fun prepareFactors(){
         // 700ms in 1M
         // shoudl not be used for 1M
         // 200ms codeforces for 200k
         factors = List(sieveMx + 1){ mutableListOf()}
         factors[1].add(1)

         for(i in 2..sieveMx){
             val p = nextPrime[i]
             val a = nextPrimePower[i]
             val old = afterPrimePowerDivison[i]

             var here = 1
             repeat(a+1){
                 for(c in factors[old]){
                     factors[i].add(c * here )
                 }
                 here *= p
             }
 //            factors[1].ad
 //            factors[i].addAll(i.factors())
         }
     }
     fun calculateMobius(){
         assert(sieveCalculated)
         mobius = IntArray(sieveMx + 1)
         mobius[1] = 1
         for(i in 2..sieveMx){
             val p = primeOf[i]
             if(p == primeOf[i/p]){
                 mobius[i] = 0
             }else{
                 mobius[i] = -1 * mobius[i/p]
             }
         }
     }
 }
 inline fun Int.eachPrimePower(act:(Int,Int)->Unit){
     var here = this
     while(here > 1){
         act(sieve.nextPrime[here], sieve.nextPrimePower[here])
         here = sieve.afterPrimePowerDivison[here]
     }
 }
 fun GS(start:Int,ratio:Int,count:Int) = sequence {
     var ret = 1
     for(i in 1
             ..count){
         ret *= ratio
         yield(ret)
     }
 }
 fun Int.factors():List<Int>{
     val ret = mutableListOf(1)
     this.eachPrimePower { p, e ->
         val s = ret.toList()
         for(pn in GS(p,p,e)){
             ret.addAll(s.map{it * pn})
         }
     }
     return ret
 }
 fun totient(a:Int):Int{
     var ret = a
     a.eachPrimePower{
             p, _ ->
         ret /= p
         ret *= (p-1)
     }
     return ret
 }
 fun Int.numOfDivisors():Int{
     var ret = 1
     this.eachPrimePower { _, e -> ret *= (e+1) }
     return ret
 }
 fun Int.factorLook():List<Int>{
     return sieve.factors[this]
 }

 fun factorSingleNumber(a:Long): Long {
//     val ret = mutableListOf<Pair<Long,Int>>()
     var now = a
     for(pi in 0 until sieve.primeCounter){
         val p = sieve.primes[pi]
         var level = 0
         while(now % p == 0L){
             return p.toLong()
         }
//         if(level > 0){
//             return
//             ret.add(Pair(p.toLong(),level ))
//         }
     }
     return now
 }
fun debug(){}
const val withBruteForce = false
const val singleCase = false
fun main(){
    sieve.calculateSieveFast()
    fun accepts(k:Long, v:Long){
        assert(v <= 3e9)
        val new = (v * (v+1)) / 2
        assert(k >= new)
        if(v %2 == 0L){
            assert(k % v == (v/2))
        }else{
            assert(k % v == 0L)
        }
    }
    solve.cases{
        val n = getlong

        var now = n
        var need = 1L
        while(now % 2L == 0L ){
            now = now /2L
            need = need * 2L
        }
        if(now == 1L){
            put(-1)
            return@cases
        }else{
//            now dei need
            val need2 = need * 2
            val doublec = (need2).toDouble() * (need2.toDouble() + 1.0)
            if(doublec <= 3e18){
                val size = (need2 * (need2+1)) /2
                if(n >= size){
                    put(need * 2)
//                    accepts(n,need*2)
                    return@cases
                }
            }
//            assert(now <= 4e9)

            val p = factorSingleNumber(now)
            val sizes = (p.toDouble()) * (p.toDouble() + 1.0)
            if(sizes >= 3e18) {
                put(-1)
                return@cases
            }
            val newsize = (p) * (p + 1) / 2
            if(newsize <= n){
//                accepts(n,smallest)
                put(p)
            }else{
                put(-1)
            }

        }




    }
    done()
}