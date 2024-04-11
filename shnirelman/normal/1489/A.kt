import java.util.*

fun main(args : Array<String>) {
    var n = readLine()!!.toInt()

    var a = readLine()!!.split(" ").map({it.toInt()}).toMutableList()

    var st = TreeSet<Int>()

    var x : Int = 0

    var ans = mutableListOf<Int>()

    //var ans = MutableList<Int>(0, x)

    var i = n - 1

    while(i >= 0) {
        //print(i)
        if(!st.contains(a[i])) {
            ans.add(a[i])
            st.add(a[i])
        }
        i--
    }

    print("${ans.size} \n")
    i = ans.size - 1
    while(i >= 0) {
        print("${ans[i]} ")
        i--
    }
}