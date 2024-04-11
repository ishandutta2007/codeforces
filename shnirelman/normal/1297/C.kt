val INF : Int = 1000000000

fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(q in 0..(t - 1)) {
        var n = readLine()!!.toInt()

        var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()

        //print("$a")

        var mn : Int = INF
        var mx : Int = -INF

        var sum = 0

        for(x in a) {
            if(x < 0) {
                mx = Math.max(mx, x)
            } else if(x > 0) {
                mn = Math.min(mn, x)
                sum += x
            }

        }

        var y : Int

        if(-mx < mn) {
            y = mx
            sum += mx
        } else {
            y = mn
            sum -= mn
        }

        print("$sum\n")

        var fl : Boolean = false
        for(x in a) {
            var res : Int
            if(x > 0)
                res = 1
            else
                res = 0

            if(!fl && x == y) {
                fl = true
                res = (res + 1) % 2
            }

            print("$res")
        }

        print("\n")
    }
}