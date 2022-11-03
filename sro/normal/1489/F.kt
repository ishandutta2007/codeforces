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
	var (n, m, k) = readInts()
	var a = readInts()
	var sm = 0.toLong()
	var ans = 0.toLong()
	for (i in a.reversed()) {
		sm += i.toLong()
		if (sm > k) {
			--m
			sm = i.toLong()
			if (m == 0) break
		}
		++ans
	}
	println(ans)
}