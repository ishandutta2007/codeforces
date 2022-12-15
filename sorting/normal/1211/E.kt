import java.util.*
import kotlin.math.*

val reader = Scanner(System.`in`)
const val MAXN = 200007

var cnt = IntArray(MAXN){_ -> 0}
var p = IntArray(MAXN){_ -> 0}
var used = BooleanArray(MAXN){_ -> false}

fun myCheck(n: Int, a: IntArray, mid: Int):Boolean{
    for(i in 0 until MAXN){
        used[i] = false
    }

    var state1 = 0
    var state2 = 0

    for(i in 0 until n){
        if(a[i] <= mid){
            if(!used[a[i]]){
                p[state1] = a[i]
                state1++
                used[a[i]] = true
                continue
            }

            if(p[state2] != a[i]){
                return false
            }
            state2++
        }
    }

    if(state1 != state2){
        return false
    }

    return true
}

fun main(){
    var n = reader.nextInt()
    var a = IntArray(n)

    for(i in 0 until n){
        a[i] = reader.nextInt()
        ++cnt[a[i]]
    }

    var mx = 0

    for(i in 1 until MAXN){
        if(cnt[i] != 2){
            break
        }
        ++mx
    }

    var l = 0
    var r = mx

    while(l != r){
        var mid = (l + r + 1) / 2

        if(myCheck(n, a, mid)){
            l = mid
        }
        else{
            r = mid - 1
        }
    }
    mx = l

    for(i in 0 until MAXN){
        used[i] = false
    }

    var state1 = 0
    var state2 = 0

    for(i in 0 until n){
        if(a[i] <= mx){
            if(!used[a[i]]){
                p[state1] = a[i]
                state1++
                used[a[i]] = true
                print("R")
                continue
            }

            state2++
            print("G")
        }
        else{
            print("B")
        }
    }

    return
}