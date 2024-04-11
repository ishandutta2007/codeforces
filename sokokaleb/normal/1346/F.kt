fun calc(arr : List<Long>): Long {
	var ans = Long.MAX_VALUE
	var rightSum = 0L
	var rightCount = 0L
	for (el in arr.asReversed()) {
		rightSum += rightCount
		rightCount += el
	}
	var leftSum = 0L
	var leftCount = 0L
	for (el in arr) {
		leftSum += leftCount
		leftCount += el
		ans = Math.min(ans, leftSum + rightSum)
		rightCount -= el
		rightSum -= rightCount
	}
	return ans
}

fun solve() {
	val (n, m, q) = readInts()
	var arr_vert = MutableList(m, { _ -> 0L })
	var arr_hori = MutableList(n, { _ -> 0L })
	var arr = MutableList(n, { _ -> MutableList(m, { _ -> 0 }) })
	for (i in 0 until n) {
		for ((j, e) in readInts().withIndex()) {
			arr_vert.set(j, arr_vert[j] + e)
			arr_hori.set(i, arr_hori[i] + e)
			arr[i].set(j, e)
		}
	}

	print(calc(arr_vert) + calc(arr_hori))
	for (i in 1..q) {
		val (x, y, z) = readInts()
		arr_vert.set(y - 1, arr_vert[y - 1] - arr[x - 1][y - 1] + z)
		arr_hori.set(x - 1, arr_hori[x - 1] - arr[x - 1][y - 1] + z)
		arr[x - 1].set(y - 1, z)
		print(" ${calc(arr_vert) + calc(arr_hori)}")
	}
	println()
}

fun main(args: Array<String>) {
	solve()
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }