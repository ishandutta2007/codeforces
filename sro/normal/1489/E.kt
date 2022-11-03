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

val a = Array(200005){0}
fun main() {
	var q = readInt()
	var l = 1
	var r = 0
	while (q --> 0) {
		val (op, idx) = readStrings()
		val id = idx.toInt()
		if (op == "L") {
			--l
			a[id] = l
		} else if (op == "R") {
			++r
			a[id] = r
		} else {
			println(min(a[id] - l, r - a[id]))
		}
	}
}