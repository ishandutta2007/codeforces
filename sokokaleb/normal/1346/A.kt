fun solve() {
	val (n, k) = readLongs()
	val n1 = n / (1 + k + k * k + k * k * k)
	println("${n1} ${k * n1} ${k * k * n1} ${k * k * k * n1}")
}

fun main(args: Array<String>) {
	for (i in 1..readInt()) {
		solve()
	}
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }