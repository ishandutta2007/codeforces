fun solve() {
	val (n, k1, k2) = readLongs()
	val workday = readLn()

	var ans = 0L
	var current = 0L
	for (c in workday) {
		when (c) {
			'0' -> { current = 0L }
			'1' -> {
				val nambah = Math.min(k1, k2 - current)
				ans += nambah
				current = nambah
			}
		}
	}

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