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
        var n = readInt()
        var lo = 0
        var hi = n-1
        var arr = readInts()
        var curr = 0
        var best = 0
        var turn = 0
        var Ali = 0
        var Bo = 0
        var cn = 0
        while(lo <= hi){
            if(turn == 0){
                curr+=arr[lo]
                lo+=1
            }
            else{
                curr+=arr[hi]
                hi-=1
            }
            if(curr > best){
                cn+=1
                best = curr
                if(turn == 0){
                    turn = 1
                    Ali += curr
                }
                else{
                    turn = 0
                    Bo += curr
                }
                curr = 0
            }  
        }
        if(curr > 0){
            cn+=1
            if(turn == 0){
                    turn = 1
                    Ali += curr
                }
            else{
                turn = 0
                Bo += curr
            }
        }
        print(cn)
        print(' ')
        print(Ali)
        print(' ')
        println(Bo)
    }
   
}