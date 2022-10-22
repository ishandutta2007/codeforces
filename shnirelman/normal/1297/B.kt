fun main(args : Array<String>) {



    var t = readLine()!!.toInt()
    for(q in 0..(t - 1)) {
        var n = readLine()!!.toInt()


        var a = mutableListOf<Int>()
        var b = mutableListOf<Int>()


        for(i in 0..(n - 1)) {
            var sub = readLine()!!.split(" ").map({it.toInt()})
            a.add(sub[0])
            b.add(sub[1])
        }

        var c = mutableListOf<Int>()
        for(i in 0..n - 1) {
            c.add(a[i])
            c.add(b[i] + 1)
        }

        var res = false
        for(x in c) {
            var cnt = 0
            for(i in 0..n - 1)
                if(a[i] <= x && x <= b[i])
                    cnt++
            if(cnt == 1) {
                print("$x\n")
                res = true
                break
            }
        }

        if(!res)
            print("-1\n")
        //var a = readLine()!!.split(" ").map({it.toInt()})
    }
    /*var t = readLine()!!.toInt()
    for(q in 0..(t - 1)) {
        var n = readLine()!!.toInt()
        if(n < 1000) {
            print("$n\n")
        } else if(n < 999500) {
            var res = n / 1000;
            if(n - res * 1000 < 500)
                print("${res}K\n")
            else
                print("${res + 1}K\n")
        } else {
            var res = n / 1000000;
            if(n - res * 1000000 < 500000)
                print("${res}M\n")
            else
                print("${res + 1}M\n")
        }
    }*/

    /*var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()

    var mx = 0
   for(i in 0..3)
       if(a[i] > a[mx])
           mx = i

    for(i in 0..3)
        if(i != mx)
            print("${a[mx] - a[i]} ")

    */

    /*var n = readLine()!!.toInt();

    for(i in 0..(n - 1)) {
        print("$i\n")
        continue
        break
    }

    print("$n");*/
}