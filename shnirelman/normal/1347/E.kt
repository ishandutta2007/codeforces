fun main() {
    var t = readLine()!!.toInt()
    for(q in 0..t - 1) {
        var n = readLine()!!.toInt()

        if(n < 4) {
            println(-1)
            continue
        } else if(n == 4) {
            println("3 1 4 2")
            continue
        }

        var a = mutableListOf<Int>()

        run {
            var i = 2
            while(i <= n) {
                a.add(i)
                i += 4
            }
        }

        run {
            var i = n / 2 * 2
            if(i % 4 == 2)
                i -= 2

            while(i > 0) {
                a.add(i)
                i -= 4
            }
        }

        run {
            var i = 1
            while(i <= n) {
                a.add(i)
                i += 2
            }
        }

        for(x in a)
            print("$x ")
        println()
    }
}