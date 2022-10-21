fun nextInt() = readLine()!!.toInt()
fun nextInts() = readLine()!!.split(" ").map { it.toInt() }
fun next() = readLine()!!

fun main(args: Array<String>) {
    val t = nextInt()
    for(T in 1..t) {
        var(n, k) = nextInts()
        var s = next()
        var ava = 0
        var cur = 0
        for(c in s){
        	if(c == '('){
        		cur++
        	}
        	else if(c == ')'){
        		cur--
        	}
        	if(cur == 0){
        		ava++
        	}
        }
        if(k <= (n-2*ava)/2){
        	println(k+ava)
        }
        else{
        	println(n/2)
        }
    }
}