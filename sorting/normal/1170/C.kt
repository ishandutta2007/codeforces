import java.util.Scanner

val reader = Scanner(System.`in`)

fun solve(){
    var s: String = reader.next()
    var t: String = reader.next()

    var i: Int = 0
    var j: Int = 0
    var ans: Boolean = true

    while(i < s.length && j < t.length){
        if(s[i] == t[j]){
            ++i
            ++j
            continue
        }
        if(s[i] == '+') {
            ans = false
            break
        }
        if(i == s.length - 1 || s[i + 1] != '-'){
            ans = false;
            break
        }
        i += 2
        ++j
    }
    if(i != s.length || j != t.length){
        ans = false
    }

    if(ans){
        println("YES")
    }
    else{
        println("NO")
    }
}

fun main(){
    var k: Int= reader.nextInt()

    for(i in 0 until  k){
        solve()
    }
}