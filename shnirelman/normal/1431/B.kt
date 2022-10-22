const val INF : Int = 1000000000

fun main(args : Array<String>) {
    var t = readLine()!!.toInt()
    for(q in 0..(t - 1)) {
        var s = readLine()!!

        var ans = 0
        var lst : Boolean = true
        for(c in s) {
            if(c == 'w') {
                ans++
                lst = true
            } else {
                if(!lst) {
                    ans++
                    lst = true
                } else {
                    lst = false
                }
            }
                
            
        }
        print("$ans \n")
    }
}