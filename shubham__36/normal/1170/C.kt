private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val t = readInt()
//    val t = 1
    repeat(t) {
        val y = readLine()!!.toCharArray()
        val x = readLine()!!.toCharArray()
        var len = 0
        var bo = 0
//        println(y.lastIndex)
        for(i in x){
            if(len > y.lastIndex){
                bo = 1
                break
            }
            if(i==y[len]) {
                len++
                continue
            }
            else if((len+1)>y.lastIndex){
                bo = 1
                break
            }
            else if((i=='+') and (y[len]=='-') and (y[len+1]=='-')) len+=2
            else{
                bo = 1
                break
            }
        }
        if((bo==1) or (len!=(y.lastIndex+1))){
            println("NO")
        }
        else{
            println("YES")
        }
    }
}