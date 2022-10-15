/** template author -- Spheniscine */

@file:Suppress("NOTHING_TO_INLINE", "EXPERIMENTAL_FEATURE_WARNING", "OVERRIDE_BY_INLINE")
@file:OptIn(ExperimentalStdlibApi::class)

import java.io.PrintWriter
import kotlin.math.*
import kotlin.random.Random
import kotlin.collections.sort as _sort
import kotlin.collections.sortDescending as _sortDescending
import kotlin.io.println as iprintln

fun main() { _writer.solve(); _writer.flush() }
fun PrintWriter.solve() {
//    val startTime = System.nanoTime()

    val numCases = readInt()
    case@ for(case in 1..numCases) {
    	val n=readInt()
    	val a=readLongArray(n)
    	a._sortDescending()
    	var ans:Long=0
    	for (i in 0..n-1){
    		val cur=(i+1)*a[i]
    		if(ans<cur)
    			ans=cur
    	}
    	iprintln(ans)
    }

//    iprintln("Time: ${(System.nanoTime() - startTime) / 1000000} ms")
}


/** IO */
//@JvmField val ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null
//const val PATH = "src/main/resources/"
//@JvmField val INPUT = File(PATH + "input.txt").inputStream()
//@JvmField val OUTPUT = File(PATH + "output.txt").outputStream()
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

const val _BUFFER_SIZE = 1 shl 16
@JvmField val _buffer = ByteArray(_BUFFER_SIZE)
@JvmField var _bufferPt = 0
@JvmField var _bytesRead = 0

tailrec fun readChar(): Char {
    if(_bufferPt == _bytesRead) {
        _bufferPt = 0
        _bytesRead = INPUT.read(_buffer, 0, _BUFFER_SIZE)
    }
    return if(_bytesRead < 0) Char.MIN_VALUE
    else {
        val c = _buffer[_bufferPt++].toChar()
        if (c == '\r') readChar() else c
    }
}

/** @param skipNext Whether to skip the next character (usually whitespace), defaults to true */
fun readCharArray(n: Int, skipNext: Boolean = true): CharArray {
    val res = CharArray(n) { readChar() }
    if(skipNext) readChar()
    return res
}

fun readLine(): String? {
    var c = readChar()
    return if(c == Char.MIN_VALUE) null
    else buildString {
        while(c != '\n' && c != Char.MIN_VALUE) {
            append(c)
            c = readChar()
        }
    }
}
fun readLn() = readLine()!!

fun read() = buildString {
    var c = readChar()
    while(c <= ' ') {
        if(c == Char.MIN_VALUE) return@buildString
        c = readChar()
    }
    do {
        append(c)
        c = readChar()
    } while(c > ' ')
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

@JvmField val _writer = PrintWriter(OUTPUT, false)

/**  sort overrides to avoid quicksort attacks */

@JvmField var _random: Random? = null
val random get() = _random ?: Random(0x594E215C123 * System.nanoTime()).also { _random = it }

inline fun <A, T> _mergeSort(a0: A, n: Int, tmp0: A, get: A.(Int) -> T, set: A.(Int, T) -> Unit, cmp: (T, T) -> Int) {
    var a = a0
    var tmp = tmp0
    var len = 1
    while(len < n) {
        var l = 0
        while(true) {
            val m = l + len
            if(m >= n) break
            val r = min(n, m + len)
            var i = l
            var j = m
            for(k in l until r) {
                if(i != m && (j == r || cmp(a.get(i), a.get(j)) <= 0)) {
                    tmp.set(k, a.get(i++))
                } else tmp.set(k, a.get(j++))
            }
            l = r
        }
        for(i in l until n) tmp.set(i, a.get(i))
        val t = a; a = tmp; tmp = t
        len += len
    }
    if(a !== a0) for(i in 0 until n) a0.set(i, tmp0.get(i))
}

inline fun IntArray.sortWith(cmp: (Int, Int) -> Int) { _mergeSort(this, size, IntArray(size), IntArray::get, IntArray::set, cmp) }
inline fun <T: Comparable<T>> IntArray.sortBy(func: (Int) -> T) { sortWith { a, b -> func(a).compareTo(func(b)) } }
inline fun <T: Comparable<T>> IntArray.sortByDescending(func: (Int) -> T) { sortWith { a, b -> func(b).compareTo(func(a)) } }
fun IntArray.sort() { sortBy { it } }
fun IntArray.sortDescending() { sortByDescending { it } }

inline fun LongArray.sortWith(cmp: (Long, Long) -> Int) { _mergeSort(this, size, LongArray(size), LongArray::get, LongArray::set, cmp) }
inline fun <T: Comparable<T>> LongArray.sortBy(func: (Long) -> T) { sortWith { a, b -> func(a).compareTo(func(b)) } }
inline fun <T: Comparable<T>> LongArray.sortByDescending(func: (Long) -> T) { sortWith { a, b -> func(b).compareTo(func(a)) } }
fun LongArray.sort() { sortBy { it } }
fun LongArray.sortDescending() { sortByDescending { it } }

inline fun DoubleArray.sortWith(cmp: (Double, Double) -> Int) { _mergeSort(this, size, DoubleArray(size), DoubleArray::get, DoubleArray::set, cmp) }
inline fun <T: Comparable<T>> DoubleArray.sortBy(func: (Double) -> T) { sortWith { a, b -> func(a).compareTo(func(b)) } }
inline fun <T: Comparable<T>> DoubleArray.sortByDescending(func: (Double) -> T) { sortWith { a, b -> func(b).compareTo(func(a)) } }
fun DoubleArray.sort() { sortBy { it } }
fun DoubleArray.sortDescending() { sortByDescending { it } }

inline fun CharArray.sort() { _sort() }
inline fun CharArray.sortDescending() { _sortDescending() }

inline fun <T : Comparable<T>> Array<out T>.sort() = _sort()
inline fun <T : Comparable<T>> Array<out T>.sortDescending() = _sortDescending()
inline fun <T : Comparable<T>> MutableList<out T>.sort() = _sort()
inline fun <T : Comparable<T>> MutableList<out T>.sortDescending() = _sortDescending()

// import preserving junk function
@Suppress("NonAsciiCharacters") fun () { iprintln(max(1, 2)) }

fun IntArray.sumLong() = sumOf { it.toLong() }

fun IntArray.sortedIndices() = IntArray(size) { it }.also { it.sortBy(::get) }
fun IntArray.sortedIndicesDescending() = IntArray(size) { it }.also { it.sortByDescending(::get) }
fun LongArray.sortedIndices() = IntArray(size) { it }.also { it.sortBy(::get) }
fun LongArray.sortedIndicesDescending() = IntArray(size) { it }.also { it.sortByDescending(::get) }
fun DoubleArray.sortedIndices() = IntArray(size) { it }.also { it.sortBy(::get) }
fun DoubleArray.sortedIndicesDescending() = IntArray(size) { it }.also { it.sortByDescending(::get) }
fun <T: Comparable<T>> Array<T>.sortedIndices() = IntArray(size) { it }.also { it.sortBy(::get) }
fun <T: Comparable<T>> Array<T>.sortedIndicesDescending() = IntArray(size) { it }.also { it.sortByDescending(::get) }
fun <T: Comparable<T>> List<T>.sortedIndices() = IntArray(size) { it }.also { it.sortBy(::get) }
fun <T: Comparable<T>> List<T>.sortedIndicesDescending() = IntArray(size) { it }.also { it.sortByDescending(::get) }

// max/min Kotlin 1.6 -> 1.4 shim
fun IntArray.max() = maxOf { it }
fun IntArray.min() = minOf { it }
fun LongArray.max() = maxOf { it }
fun LongArray.min() = minOf { it }
fun CharArray.max() = maxOf { it }
fun CharArray.min() = minOf { it }
fun <T : Comparable<T>> Iterable<T>.max() = maxOf { it }
fun <T : Comparable<T>> Iterable<T>.min() = minOf { it }
fun <T : Comparable<T>> Sequence<T>.max() = maxOf { it }
fun <T : Comparable<T>> Sequence<T>.min() = minOf { it }