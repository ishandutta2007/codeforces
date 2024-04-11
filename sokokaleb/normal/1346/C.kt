fun solve() {
	val (n, k, x, y) = readLongs()
	var elements : List<Long> = readLongs()
	elements = elements.sortedBy { it -> -it }

	var sum = elements.reduce { a, b -> a + b }
	var toRemoveSmart = 0
	for (el in elements) {
		if ((sum + n - 1) / n <= k) {
			break
		}
		toRemoveSmart += 1
		sum -= el
	}
	var toRemoveManually = elements.count { it -> it > k }

	val ans = Math.min(1L * x * toRemoveManually, 1L * x * toRemoveSmart + y)
	println(ans)
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