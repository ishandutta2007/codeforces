private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt() 
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
	    var t = readInt()
    	repeat(t) {
            var (x, y) = readInts();
            var k = 0;
            var s = y / x;
            var ans = y % x;
            while (s > 0) {
                ans += s  % 10;
                s = s / 10;
            }
            
            println(ans);
        }
}