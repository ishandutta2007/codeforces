fun readLn() = readLine()!! // string line
fun readInt() = readLn().toInt() // single int
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints

fun solve(n : Int, k : Int, s : String) : Int{
    var ans = 0
    var sum = 0
    var can = k
    for (c in s){
        sum+= if(c == '(') 1 else -1
        if(sum == 0) {
            ans++
        }
        else if(c == ')' && can > 0){
            can--
            ans++
        }
    }
    return ans
}

fun main() {
    var q = readInt()

    for (i in 1..q) {
        var (n, k) = readInts()
        println(solve(n, k, readLn()))
    }
}