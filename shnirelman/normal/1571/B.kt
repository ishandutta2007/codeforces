import java.lang.Integer.*
import java.util.*

class pii {
    var f = 0
    var s = 0

    constructor(a : Int, b : Int) {
        f = a
        s = b
    }
}

fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(case in 0 until t) {
        var n = readLine()!!.toInt()
        var (a, x) = readLine()!!.split(" ").map({it.toInt()})
        var (b, y) = readLine()!!.split(" ").map({it.toInt()})

        var c = readLine()!!.toInt()

        var res = min(x + c - a, y)

        println(res)
    }
}

/*fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(case in 0 until t) {
        var s = readLine()!!
        var a = true
        var b = true
        for(c in s) {
            if(c == '<')
                a = false
            else if(c == '>')
                b = false
        }

        var res = "?"

        if(a && b)
            res = "="
        else if(a)
            res = ">"
        else if(b)
            res = "<"
        else
            res = "?"

        println("$res")
    }
}*/