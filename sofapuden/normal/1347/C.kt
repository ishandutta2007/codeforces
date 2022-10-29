private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun toCharacterArray(str: String): CharArray {
	return str.toCharArray()
}

fun main(args:Array<String>){
    val t = readInt()
    repeat(t){
        var x = readLn()
        val chars: CharArray = toCharacterArray(x)
        var cnt = chars.size-1
        var ans = 0
        var cop = x.toInt()
        while(cop>0){
            if(cop%10 != 0){
            ans+=1}
            cop/=10
        }
        println(ans)
        for(i in chars){
            if(i != '0'){
                print(i)
                repeat(cnt){
                    print(0)
                }
                print(' ')
            }
            cnt-=1
        }
        println()
        
    }
   
}