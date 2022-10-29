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
        if(n <= 3){
            println(-1)
        }
        else if(n == 4){
            println("3 1 4 2")
        }
        else{
            for(i in 1..n/2){
                print(i*2-1)
                print(" ")
            }
            if(n%2 == 1){
            print(n)
            print(" ")
            }
            print(((n-1)/2)*2-2)
            print (" ")
            if(((n-1)/2)*2+2 == n){
		        print(n)
		        print(" ")
	        }
	        print(((n-1)/2)*2)
	        print(" ")
	        for(i in 0..(((n-1)/2)*2-4)-1){
	            if((((((n-1)/2)*2-4))-i) % 2 == 0){
	                print((((((n-1)/2)*2-4))-i))
	                print(" ")
	           }
	       }
	       println()
	   }    
    }
   
}