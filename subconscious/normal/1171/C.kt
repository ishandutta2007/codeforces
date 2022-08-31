fun main(){
    val t=readLine()!!.toInt()
    for(Cas in 1..t){
        val s=readLine()!!.toCharArray()
        s.sort()
        if(s[0]==s[s.size-1])println(-1)
        else println(s)
    }
}