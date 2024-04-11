fun main(){
    val n=readLine()!!.toInt()
    val s=readLine()!!.toCharArray()
    if(n==1){
        println("Yes")
        return
    }
    var cnt=Array(26){0}
    for(c in s)++cnt[c-'a']
    var fg=false
    for(i in cnt)if(i>=2){
        fg=true
        break
    }
    if(fg)println("Yes")
    else println("No")
}