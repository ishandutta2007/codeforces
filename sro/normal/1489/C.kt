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
	var s = readLn()
	var ans = 0
	for (i in 0..n - 3) {
		if (s[i] == 'x' && s[i + 1] == 'x' && s[i + 2] == 'x') {
			++ans
		}
	}
	println(ans)
}