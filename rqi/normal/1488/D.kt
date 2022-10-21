fun nextInt() = readLine()!!.toInt()
fun nextInts() = readLine()!!.split(" ").map { it.toInt() }

fun nextLong() = readLine()!!.toLong()
fun nextLongs() = readLine()!!.split(" ").map { it.toLong() }

fun next() = readLine()!!

fun min(a: Int, b: Int): Int {
	if(a < b) return a
	return b
}

fun max(a: Int, b: Int): Int {
	if(a > b) return a
	return b
}

fun main(args: Array<String>) {
    val t = nextInt()
    for(T in 1..t) {
        var(n, s) = nextLongs()
        
        var lo: Long = 1
    	var hi: Long = 1000000000000000000
    	
    	while(lo < hi){
    		var mid: Long = (lo+hi)/2+1
    		
    		var num: Long = 0
    		var cur: Long = mid
    		var i: Long = n
    		while(i >= 1){
    			if(cur == 1L){
    				num+=i
    				break
    			}
    			num+=cur
    			if(num > s) break
    			cur = (cur+1)/2
    			i--
    		}
    		
    		if(num <= s){
    			lo = mid
    		}
    		else{
    			hi = mid-1
    		}
    	}
    	
    	lo = hi
    	
    	println(lo)
    }
}