// $time$
import java.io.BufferedInputStream
import java.io.File
import java.io.PrintWriter
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

val getintfast:Int get() = IO.nextInt()
val getint:Int get(){ val ans = getlong ; if(ans > Int.MAX_VALUE) IntArray(1000000000); return ans.toInt() }
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
infix fun Int.modM(b:Int):Int{ return ((this.toLong() * b) % pI).toInt() }
infix fun Int.modPlus(b:Int):Int{ val ans = this + b;return if(ans >= pI) ans - pI else ans }
fun intPow(x:Int,e:Int,m:Int):Int{
    var X = x ; var E =e ; var Y = 1
    while(E > 0){
        if(E and 1 == 0){
            X = ((1L * X * X) % m).toInt()
            E = E shr 1
        }else{
            Y = ((1L * X * Y) % m).toInt()
            E -= 1
        }
    }
    return Y
}
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
//7. bits
fun Int.has(i:Int):Boolean = (this and (1 shl i) != 0)



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
    fun reset(){
        startpointer = -l
        endpointer = startpointer -1
    }
}
fun fastEmptyList(max:Int):fastDeque{
    return fastDeque(0,max-1)
}

const val graphWeighed = false
class Graph(val n:Int, val m:Int, val directed:Boolean) {
    val maxedge = if (directed) m else m * 2

    var cnt = -1

    val edgecount:Int get() = cnt + 1

    val next = IntArray(maxedge)
    val head = IntArray(n) { -1 }
    val to = IntArray(maxedge)
    val from = IntArray(maxedge)
    val weights = IntArray(if (graphWeighed) m else 0)
    private fun primitive_add(u: Int, v: Int): Int {
        next[++cnt] = head[u]
        head[u] = cnt
        to[cnt] = v
        from[cnt] = u
        return cnt
    }

    fun add(u: Int, v: Int): Int {
        val e = primitive_add(u, v)
        if (!directed) {
            primitive_add(v, u)
        }
        return if (directed) e else e shr 1
    }

    fun addWeighted(u: Int, v: Int, w: Int):Int{
        val e = add(u, v)
        weights[e] = w
        return e
    }

    //Basic Transversals
    inline fun NS(a:Int, act:(Int)->Unit){
        var i= head[a]
        while(i != -1){
            act(to[i])
            i = next[i]
        }
    }
    inline fun NS_E(a:Int, act:(e:Int,v:Int)->Unit){
        var i= head[a]
        while(i != -1){
            act(i,to[i])
            i = next[i]
        }
    }

    // twice for undirected
    inline fun everyEdge(act:(a:Int, b:Int)->Unit){
        for(e in 0 until edgecount){
            act(from[e], to[e])
        }
    }

    //2 Basic Transversals
    var root = 0
    var preorder:IntArray = IntArray(0)
    var parent:IntArray = IntArray(0)
    val hasDFSorder:Boolean get() = preorder.size == n
    var parentEdge:IntArray = IntArray(0)

    var entryTime:IntArray = IntArray(0)
    var exitTime:IntArray = IntArray(0)

    //stores the order
    fun treeOrderDFS(withEdges:Boolean = false){
        parent = IntArray(n){-1}
        var pt = -1
        preorder = IntArray(n){-1}
        if(withEdges) parentEdge = IntArray(n){-1}

        val Q = fastDeque(0,n)
        parent[root] = root
        Q.addLast(root)
        while(Q.isNotEmpty()){
            val a = Q.removeLast()
            val p = parent[a]
            preorder[++pt] = a
            NS_E(a){e,v ->
                if(v == p) return@NS_E
                if(withEdges) parentEdge[v] = if(directed) e else (e shr 1)
                parent[v] = a
                Q.addLast(v)
            }
        }
    }
    //One off, does not store order
    inline fun anyOrderExplore(root:Int?,newroot:(r:Int) ->Unit, act:(form:Int, to:Int, root:Int, e:Int, spanning:Boolean)->Unit) {
        // null -> Exhaust
        parent = IntArray(n){-1}
        val explored = BooleanArray(n)
        val Q = fastDeque(0,n)
        for(i in 0 until n){
            if(explored[i] || (root != null && root != i) ) continue
            newroot(i)
            Q.addLast(i)
            parent[i] = i
            while(Q.isNotEmpty()){
                val a = Q.removeLast()
                NS_E(a) { e,v ->
                    if (v == parent[v]) return@NS_E
                    val newedge = !explored[v]
                    if (newedge) {
                        parent[v] = a
                        Q.addLast(v)
                        explored[v] = true
                    }
                    act(a, v, i, e,newedge)
                }
            }
            if(root != null) break
        }
    }
    fun EulerDoubleOrder(): Pair<IntArray, IntArray> {
        var pointer = 0
        val euler = IntArray(2 * n - 1)
        val entry = IntArray(n)
        fun dfs(v:Int, p:Int) {
            euler[++pointer] = v
            entry[v] = pointer
            NS(v){ w->
                if(w == p) return@NS
                dfs(w,p)
                euler[++pointer] = v
            }
        }
        dfs(root,-1)
        return Pair(euler, entry)
    }
    inline fun BFS(distRoot:Int, reached:(Int, Int)->Unit = {_,_ ->}): IntArray {
        val toDo = fastDeque(0,n)
        val explored = IntArray(n+1){-1} // also store parents
        toDo.addLast(distRoot)
        explored[distRoot] = -2
        val dist = IntArray(n){-1}
        dist[distRoot] = 0

        while(toDo.size > 0){
            val x = toDo.removeFirst()
            reached(x,explored[x])
            NS(x){ a->
                if(explored[a] == -1){
                    explored[a] = x
                    dist[a] = dist[x] + 1
                    toDo.addLast(a)
                }
            }
        }
        return dist
    }
    inline fun trueOrderDFS(root:Int?,newroot:(r:Int) ->Unit, preexplore:(v:Int) ->Unit, postExplore:(v:Int)->Unit ){
        val Q = fastDeque(0,n)
        val explored = BooleanArray(n){false}
        val headHere = head.copyOf()
        for(i in 0 until n) {
            if (explored[i] || (root != null && root != i)) continue
            newroot(i)
            explored[i] = true
            Q.addLast(i)
            while(Q.isNotEmpty()){
                val v = Q.last()
                val e = headHere[v]
                if(e == head[v]){
                    preexplore(v)
                }
                if(e == -1){
                    postExplore(v)
                    Q.removeLast()
                    continue
                }
                headHere[v] = next[e]
                val t = to[e]
                if(!explored[t]){
                    explored[t] = true
                    Q.addLast(t)
                }
            }
        }

    }


    //standard graph transversal orders
    inline fun leafFirst(act:(Int)->Unit){
        if(!hasDFSorder) treeOrderDFS()
       for(i in preorder.lastIndex downTo 0){
           act(preorder[i])
       }
    }
    inline fun rootFirst(act:(Int)->Unit){
        if(!hasDFSorder) treeOrderDFS()
        for(a in preorder){
            act(a)
        }
    }
    inline fun anyOrder(act:(Int)->Unit){
        for(i in 0 until n){
            act(i)
        }
    }
    inline fun rootFirstEdge(act:(from:Int, to:Int, e:Int)->Unit){
        if(!hasDFSorder) treeOrderDFS()
        for(i in 1 until preorder.size){
            val v = preorder[i]
            act(parent[v],v,parentEdge[v])
        }
    }

    // Basic invariants maintaining
    fun calculateParents():IntArray{
        if(!hasDFSorder) treeOrderDFS()
        return parent
    }
    fun calculateSizes():IntArray{
        val ret = IntArray(n){1}
        leafFirst { v -> if(v != root) ret[parent[v]] += ret[v] }
        return ret
    }
    fun calculateSubtreeSum(weights:IntArray){
        leafFirst { v -> if(v != root) weights[parent[v]] += weights[v] }
    }
    fun calculateDepth(): IntArray {
        val ret = IntArray(n)
        rootFirst { v -> if(v != root) ret[v] = ret[parent[v]] + 1  }
        return ret
    }
    inline fun subs(v:Int, act:(Int)->Unit){
        NS(v){w ->
            if(w != parent[v]) act(w)
        }
    }
    fun calculateDepthWeighted(): LongArray {
        val ret = LongArray(n)
        rootFirstEdge{from,to,e -> ret[to] = ret[from] + weights[e]}
        return ret
    }
    fun outdegree():IntArray{
        val ret = IntArray(n)
        everyEdge { a, b -> ret[a] ++  }
        return ret
    }
    fun indegree():IntArray{
        val ret = IntArray(n)
        everyEdge {a, b -> ret[b] ++}
        return ret
    }
    fun degree():IntArray = outdegree()
    fun reversed():Graph{
        assert(directed)
        val new = Graph(n,m,true)
        everyEdge { a, b -> new.add(b,a) }
        return new
    }
    fun intime():IntArray{
        val tin = IntArray(n)
        if(!hasDFSorder) treeOrderDFS()
        for(i in 0 until n) tin[preorder[i]] = i
        return tin
    }
    fun outtime():IntArray{
        val tout = intime()
        leafFirst { v ->
            val p = parent[v]
            if(p == v) return@leafFirst
            tout[p] = maxOf(tout[p], tout[v])
        }
        return tout
    }

}

fun debug(){}
const val withBruteForce = false
const val singleCase = false
fun main(){
    solve.cases{
        val n = getint
        val G = Graph(n,n-1,false)
        repeat(n-1){
            G.add(getint - 1 , getint - 1 )
        }

        val able = IntArray(n){nlarge}
        val truedegree = G.degree()
        val subdegree = G.degree()
        for(i in 1 until n){
            subdegree[i] --
        }

        //1 can do even only
        // 2 can do odd only
        //3 can do both
        // 0 none
        G.leafFirst {
            v ->
            if(v == 0) return@leafFirst
            val d = subdegree[v]
            if(d == 0){
                able[v] = 1
                return@leafFirst
            }
            // 0, 1, 2 can do both
            val types = IntArray(4)
            G.subs(v){
                w ->
                types[able[w]] ++
            }
            if(types[0] != 0){
                able[v] = 0
                return@leafFirst
            }
            var ret = 0
            for(p in 0 until 2){
                val base = intArrayOf((d+2)/2 , (d+1) /2 )
                base[p] --
                if(types[1] <= base[0] && types[2] <= base[1]){
                    ret += 1 shl p
                }
            }
            able[v] = ret
        }
        val finald = subdegree[0]
        val need = intArrayOf((finald +1)/2 , finald/2)
        val have = IntArray(4)
        G.subs(0){
            w -> have[able[w]] ++
        }
        if(have[0] != 0){
            put("NO")
            return@cases
        }
        if(!(have[1] <= need[0] && have[2] <= need[1])){
            put("NO")
            return@cases
        }
        val allret = mutableListOf<Pair<Int,Int>>()
        fun solve(v:Int, type:Int){

            val odd = mint
            val even = mint
            val both = mint

            if(type == 0){
                even.add(-1)
            }else if(type == 1){
                odd.add(-1)
            }

            G.subs(v){
                w ->
                if(able[w] == 1){
                    even.add(w)
                }else if(able[w] == 2){
                    odd.add(w)
                }else{
                    both.add(w)
                }
            }
            val dhere = truedegree[v]
            val order = mint
            for(i in dhere-1 downTo 0){
                if(i % 2 == 0) {
                    if(even.isNotEmpty()){
                        order.add(even.removeLast())
                    }else{
                        order.add(both.removeLast())
                    }
                }else{
                    if(odd.isNotEmpty()){
                        order.add(odd.removeLast())
                    }else{
                        order.add(both.removeLast())
                    }
                }
            }
            for(i in order.indices){
                val next = order[i]
                val nxettype = (dhere - 1 - i ) %2
                if(next == -1){
                    allret.add(Pair(v,G.parent[v]))
                }else{
                    solve(next,nxettype)
                }
            }

        }
        solve(0,-1)
        put("YES")
        for((a,b) in allret){
            put("${a+1} ${b+1}")
        }





    }
    done()
}

/*
1
3
1 2
2 3

1
4
1 2
2 3
3 4
 */