fun readLn() = readLine()!! // string line
fun readInt() = readLn().toInt() // single int
fun readStrings() = readLn().split(" ") // list of strings
fun readInts() = readStrings().map { it.toInt() } // list of ints

fun solve2(x : Int) : Int{
    return (x % 10) + if(x == 0) 0 else solve2(x / 10)
}
fun solve(x : Int, y : Int) : Int{
    return (y % x) + solve2(y/x)
}

fun main() {
    var q = readInt()

    for (i in 1..q) {
        var (x, y) = readInts()
        println(solve(x, y))
    }
}