import java.util.Scanner
val reader = Scanner(System.`in`)

const val MAXN: Int = 400005

var a: IntArray = IntArray(MAXN)
var prefix: IntArray = IntArray(MAXN)

fun sum(l: Int, r: Int): Int{
    if(l > r){
        return 0;
    }
    if(l == 0){
        return prefix[r]
    }
    return prefix[r] - prefix[l - 1]
}

fun binary_search(l: Int, r: Int, mx: Int): Int{
    var l2: Int = l - 1
    var r2: Int = r - 1

    while(l2 != r2){
        val mid: Int = (l2 + r2 + 1) / 2

        if(sum(l, mid) < mx){
            l2 = mid
        }
        else{
            r2 = mid - 1
        }
    }

    return l2 + 1
}

fun main(){
    var n: Int = reader.nextInt()
    var m: Int = reader.nextInt()

    for(i in 0 until n){
        a[i] = reader.nextInt()
    }
    prefix[0] = a[0]
    for(i in 1 until n){
        prefix[i] = a[i] + prefix[i - 1]
    }

    var q: Int = reader.nextInt()
    for(i in 0 until q){
        var pr: Int = 0; var idx: Int = 0
        var sz: Int = reader.nextInt()

        for(i in 0 until  sz){
            var c: Int = reader.nextInt()

            idx = binary_search(idx, n, c - pr)

            pr = c
        }

        idx = binary_search(idx, n, m + 1 - pr)

        if(idx == n){
            println("YES")
        }
        else{
            println("NO")
        }
    }
}