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
	var Q = readInt()
	for (q in 1..Q) {
		var T = readLongs()
		var n = T[0]
		var a = T[1]
		var b = T[2]
		if (2 * a <= b) {
			println(n * a)
			continue
		}
		println((n / 2) * b + (n % 2) * a)
	}
}