fun main(args: Array<String>) {
//    val t = readLine()!!.toInt()
    val t = 1
    repeat(t){
        val n = readLine()!!.toInt()
        val s = readLine()!!.toCharArray()
        var a = IntArray(26) {i -> 0}
        var bo = 0
        for(i in s){
            a[i-'a']++
        }
        for(i in a){
            if(i>1) bo=1
        }
        if((bo==1) or (n==1)){
            println("Yes")
        }
        else{
            println("No")
        }
    }
}