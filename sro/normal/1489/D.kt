import java.util.*
import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }
private fun ReadIntArray() = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
private fun ReadLongArray() = readLine()!!.split(" ").map { it.toLong() }.toLongArray()

fun main() {
	var n = readInt()
	var a = Array(n, { i -> readLn() })
	for (i in 0..n - 1) for (j in i + 1..n - 1) if (a[i].length > a[j].length) {
		var tmp = a[i]
		a[i] = a[j]
		a[j] = tmp
	}
	for (i in 0..n - 2) if (!a[i + 1].contains(a[i])) {
		println("NO")
		return
	}
	println("YES")
	for (i in 0..n - 1) println(a[i])
}