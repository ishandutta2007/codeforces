private fun readLn() = readLine()!!
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() } 

fun main() {
	var (t) = readInts();
	repeat(t) {
    		var (a, b) = readInts()
   		println(a + b)
	}
}