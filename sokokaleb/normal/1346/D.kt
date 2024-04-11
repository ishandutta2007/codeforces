fun solve() {
	val (n, m) = readInts()
	val As = MutableList(n + 1, { _ -> 0 })
	var edges = List(m, { _ -> MutableList(3, { _ -> 0 }) })
	for (i in 0 until m) {
		val (x, y, w) = readInts()
		As[x] = Math.max(As[x], w)
		As[y] = Math.max(As[y], w)
		edges.get(i).set(0, x)
		edges.get(i).set(1, y)
		edges.get(i).set(2, w)
	}

	if (edges.any { edge -> Math.min(As[edge[0]], As[edge[1]]) != edge[2] }) {
		println("NO")
		return
	}

	println("YES")
	println(As.subList(1, n + 1).joinToString(separator=" "))
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