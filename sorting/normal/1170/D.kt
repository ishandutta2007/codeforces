import java.util.Scanner
val reader = Scanner(System.`in`)

const val MAXM: Int = 300007

var a = IntArray(MAXM)
var nxt = IntArray(MAXM)
var pr = IntArray(MAXM)
var ans = Array<MutableList<Int>>(MAXM, { i -> mutableListOf() })

fun main(){
    var m: Int = reader.nextInt()
    var n: Int = 0

    for(i in 0 until m) {
        a[i] = reader.nextInt()
        if (a[i] == -1) {
            ++n
        }
    }

    for(i in 0 until n){
        nxt[i] = (i + 1) % n
        pr[i] = (i - 1 + n) % n
    }

    var j: Int = 0
    for(i in 0 until m){
        if(a[i] == -1) {
            if (nxt[j] == j) {
                break;
            }
            nxt[pr[j]] = nxt[j]
            pr[nxt[j]] = pr[j]
            j = nxt[j]
            continue
        }

        ans[j].add(a[i])
        j = nxt[j]
    }

    println("$n")
    for(i in 0 until n){
        print("${ans[i].size}")
        for(x in ans[i]){
            print(" $x")
        }
        println()
    }
}