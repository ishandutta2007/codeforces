import kotlin.math.*

fun readLn() = readLine()!! // string line
fun readInt() = readLn().toInt() // single int
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints
fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun check(n : Long, x : Long) : Long{
    var sum = 0L
    var rem = n
    var last = x
    while(rem >= 1 && last > 1){
        sum+= last
        last = (last + 1) / 2
        rem--
    }
    sum+= rem
    return sum
}

fun main() {
    var q = readInt()
    repeat(q) {
        var (n, s) = readLongs()
        var l = 0L
        var r = s + 1
        while(r-l > 1){
            var mid : Long = (l + r) / 2
            if(check(n, mid) <= s)
                l = mid
            else
                r = mid
        }
        println(l)
    }
}