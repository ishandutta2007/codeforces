fun nextInt() = readLine()!!.toInt()
fun nextInts() = readLine()!!.split(" ").map { it.toInt() }
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
        var(n, x, y) = nextInts()
        
        if(x > y){
        	var z = x
        	x = y
        	y = z
        }
        var ans = 5*n
        for(i in 1..n-1){
        	if(x <= i && i+1 <= y){
        		var val1 = min((i-x)+(i-1), (x-1)+(i-1))
        		var val2 = min((n-y)+(n-(i+1)), (y-(i+1))+(n-(i+1)))
        		ans = min(ans, max(val1,val2))
        	}
        	
        }
        println(ans)
    }
}