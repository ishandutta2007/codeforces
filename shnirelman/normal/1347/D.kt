fun main() {
    var t = readLine()!!.toInt()
    for(q in 0..t - 1) {
        var n = readLine()!!.toInt()
        var a = readLine()!!.split(" ").map({it.toInt()})

        var l = 0
        var r = n - 1
        var sa = 0
        var sb = 0
        var cnt = 0
        var lst = 0

        while(l <= r) {
            var cur = 0
            if(cnt % 2 == 0) {
                while(l <= r && cur <= lst) {
                    sa += a[l]
                    cur += a[l]
                    l++
                }
            } else {
                while(r >= l && cur<= lst) {
                    sb += a[r]
                    cur += a[r]
                    r--
                }
            }

            lst = cur
            cnt++
        }

        println("$cnt $sa $sb")
    }
}