fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    repeat(t){
        val s = readLine()!!.toCharArray()
        var bo = 0
        s.sort()
        val c = s[0]
        for(i in s){
            if(i!=c) bo=1
        }
        if(bo==1){
            println(s)
        }
        else{
            println(-1)
        }
    }
}