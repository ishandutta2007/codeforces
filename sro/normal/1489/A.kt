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
	var a = ReadIntArray()
	var b = IntArray(n)
	var m = 0
	var ap = IntArray(1005)
	for (i in 0..n - 1) {
		ap[a[i]] = i
	}
	for (i in 0..n - 1) {
		if (ap[a[i]] == i) {
			b[m] = a[i]
			m += 1
		}
	}
	println("$m")
	for (i in 0..m - 1) {
		print(b[i])
		print(' ')
	}
}