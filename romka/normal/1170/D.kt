fun main() {
    var n = readLine()!!.toInt() // read integer from the input
    var a = readLine()!!.split(" ").map { it.toInt() }
    var i = 0
    var m = 0
    while (i < n) {
        if (a[i] == -1) m++
        i++
    }
    var q = ArrayList<ArrayList<Int>>()
    var ind = ArrayList<Int>()
    i = 0
    while (i < m) {
        q.add(ArrayList<Int>())
        ind.add(i)
        i++
    }
    i = 0
    var j = 0
    while (i < n) {
        if (a[i] != -1) {
            q[ind[j]].add(a[i])
            ind.add(ind[j])
        }
        j++
        i++
    }
    println(m)
    var qa = ArrayList<String>()
    for (w in q) {
        qa.add(w.size.toString() + " " + w.joinToString(" "))
    }
    println(qa.joinToString("\n"))
}