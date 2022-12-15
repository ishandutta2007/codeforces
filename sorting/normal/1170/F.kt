import java.util.Scanner
import kotlin.math.*
import kotlin.random.Random

var reader = Scanner(System.`in`)

const val MAXN: Int = 200007

var a: LongArray = LongArray(MAXN)
var prefix: LongArray = LongArray(MAXN)

fun get_sum(l: Int, r: Int): Long{
    if(l == 0){
        return prefix[r]
    }
    return prefix[r] - prefix[l - 1]
}

fun get_median(l: Int, r: Int): Pair<Long, Int>{
    var first: Long
    if((l + r) % 2 == 1){
        first = (a[(l + r) / 2] + a[(l + r + 1) / 2]) / 2
    }
    else{
        first = a[(l + r) / 2]
    }

    return Pair(first, (l + r) / 2)
}

fun get_poss(l: Int, r: Int, k: Long): Pair<Long, Int>{
    var l2: Int = l
    var r2: Int = r

    while(l2 != r2){
        var mid: Int = (l2 + r2 + 1) / 2
        var up: Long = (mid - l + 1) * a[mid] - get_sum(l, mid)

        if(up <= k){
            l2 = mid
        }
        else{
            r2 = mid - 1
        }
    }

    var up: Long = (l2 - l + 1) * a[l2] - get_sum(l, l2)
    var ret: Long = a[l2] + (k - up) / (l2 - l + 1)
    ret = min(ret, a[min(l2 + 1, r)])

    return Pair(ret, l2)
}

fun calc_score(l: Int, r: Int, x: Long, idx: Int): Long{
    var lvalue: Long = (idx - l + 1) * x - get_sum(l, idx)
    var rvalue: Long = get_sum(idx + 1, r) - (r - idx) * x

    return lvalue + rvalue
}

fun main(){
    var n: Int = reader.nextInt()
    var m: Int = reader.nextInt()
    var k: Long = reader.nextLong()

    for(i: Int in 0 until n){
        a[i] = reader.nextLong()
    }
    val rng = Random(System.nanoTime())
    for (i in 0 until n) {
        val j = rng.nextInt(i + 1)
        val t = a[j]
        a[j] = a[i]
        a[i] = t
    }
    a.sort(0, n)

    prefix[0] = a[0]
    for(i: Int in 1 until n){
        prefix[i] = a[i] + prefix[i - 1]
    }

    var ans: Long = 1
    for(i in 0 until 18){
        ans *= 10
    }

    for(i: Int in m - 1 until n){
        var med: Pair<Long, Int> = get_median(i - m + 1, i)
        var poss: Pair<Long, Int> = get_poss(i - m + 1, i, k)

        if(poss.first < med.first){
            med = poss
        }

        ans = min(ans, calc_score(i - m + 1, i, med.first, med.second))
    }

    println(ans)

    return
}