


fun main(args : Array<String>) {
    var _t = readLine()!!.toInt()
    for(test in 0 until _t) {
        var n = readLine()!!.toInt()
        var a = readLine()!!.split(" ").map{it.toInt()}.toMutableList()

        for(i in 1 until n) {
            if(a[i] != a[0]) {
                if((i != 1) or (a[1] != a[2])) {
                    println(i + 1)
                } else {
                    println(1);
                }
                break;
            }
        }
    }
}