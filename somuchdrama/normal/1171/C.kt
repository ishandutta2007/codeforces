fun main(args: Array<String>) {
    val t=readLine()!!.toInt()
    repeat(t){
        var s=readLine()!!.toCharArray().sortedArray()
        if(s[0]==s[s.size-1])println(-1)
        else println(s)
    }
}