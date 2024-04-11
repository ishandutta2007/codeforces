private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toLong() } // list of ints

fun main() {
    var t = readInt();
    repeat(t) {
        var n = readInt();
        var numbers = readInts();
        var i = 0;
        var ans: Long = 0;
        repeat(n) {
            var tans: Long = 0;
            var j = 0;
            repeat(n) {
                if (numbers[j] >= numbers[i]) tans = tans + numbers[i];
                j = j + 1;
            }
            i = i + 1;
            if (tans > ans) ans = tans;
        }
        
        println(ans);
    }   
}