fun main() {
    var t = readLine()!!.toInt()
    for(q in 0..t - 1) {
        var n = readLine()!!.toInt()
        //var a : MutableList<Int> = MutableList<Int>()
        var a = mutableListOf<Int>()
        var p = 1
        for(i in 0..4) {
            var x = n / p % 10
            if(x != 0)
                a.add(x * p)
            p *= 10
        }

        println("${a.size}")
        for(x in a)
            print("$x ")
        println()
    }
}