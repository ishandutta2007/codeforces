import java.util.PriorityQueue

class PairComparator {
  companion object : Comparator<Pair<Int, Int>> {
    override fun compare(a: Pair<Int, Int>, b: Pair<Int, Int>): Int = when {
      a.first != b.first -> a.first - b.first
      else -> a.second - b.second
    }
  }
}

fun solve() {
	val (n, m, k) = readInts()
	val balls = MutableList(n, { i -> i })
	val distance = MutableList(n, { _ -> n + 5 })
	distance[k - 1] = 0
	for (i in 0 until m) {
		val (x, y) = readInts()
		distance[balls[x - 1]] = Math.min(distance[balls[x - 1]], distance[balls[y - 1]] + 1)
		distance[balls[y - 1]] = Math.min(distance[balls[y - 1]], distance[balls[x - 1]] + 1)
		balls[x - 1] = balls[y - 1].also { balls[y - 1] = balls[x - 1] }
	}

	val answer = List(n, { i -> if (distance[balls[i]] >= n) -1 else distance[balls[i]] })
	println(answer.joinToString(separator=" "))
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