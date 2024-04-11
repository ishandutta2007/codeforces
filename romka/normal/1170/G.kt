fun main() {
    var (n, m) = readLine()!!.split(" ").map { it.toInt() }
    var nn = m
    var g = ArrayList<ArrayList<Int>>()
    var ind = ArrayList<ArrayList<Int>>()
    var deg = ArrayList<Int>()
    var used = ArrayList<Int>()
    var ue = ArrayList<Boolean>()
    var uit = 0
    var i = 0
    while (i < n) {
        g.add(ArrayList<Int>())
        ind.add(ArrayList<Int>())
        deg.add(0)
        used.add(0)
        i++
    }

    while (nn > 0) {
        nn--
        var (a, b) = readLine()!!.split(" ").map { it.toInt() }
        a--
        b--
        g[a].add(b)
        ind[a].add(nn)
        g[b].add(a)
        ind[b].add(nn)
        deg[a]++
        deg[b]++
        ue.add(false)
    }

    var qa = ArrayList<ArrayList<Int>>()

    i = 0
    var ok = true
    while (i < n) {
        if (deg[i] % 2 != 0) ok = false
        i++
    }
    i = 0
    while (i < n && ok) {
        // println("enter i = " + i.toString())
        while (deg[i] > 0 && ue[ind[i][deg[i] - 1]]) {
            deg[i]--
        }
        if (deg[i] == 0) {
            i++
            continue
        }
        // println("no continue " + i.toString())
        var st = ArrayList<Int>()
        st.add(i)
        var tos = 1
        var order = ArrayList<Int>()
        while (tos > 0) {
            var v = st[tos - 1]
            if (deg[v] == 0) {
                order.add(v)
                tos--
            } else {
                var y = g[v][deg[v] - 1]
                deg[v]--
                var qw = false
                while (ue[ind[v][deg[v]]]) {
                    if (deg[v] == 0) {
                        order.add(v)
                        tos--
                        qw = true
                        break
                    } else {
                        y = g[v][deg[v] - 1]
                        deg[v]--
                    }
                }
                if (qw) continue
                if (tos == st.size) st.add(0)
                st[tos] = y
                ue[ind[v][deg[v]]] = true
                tos++
            }
        }
        i++
        uit++

        var tno = 0
        var no = ArrayList<Int>()
        // println("order: " + order.joinToString(" "))
        for (v in order) {
            if (used[v] == uit) {
                // println("no on repeat: " + no.joinToString(" ") + ", v = " + v.toString())
                // println("tno = " + tno.toString())
                var cur = ArrayList<Int>()
                cur.add(v + 1)
                while (no[tno - 1] != v) {
                    cur.add(no[tno - 1] + 1)
                    used[no[tno - 1]] = uit - 1
                    tno--
                }
                cur.add(v + 1)
                // println("ok, add " + cur.joinToString(" "))
                qa.add(cur)
            } else {
                if (tno == no.size) no.add(0)
                no[tno] = v
                tno++
                used[v] = uit
            }
        }
        if (tno != 1) ok = false
    }


    if (!ok) {
        println("NO")
    } else {
        println("YES")
        println(qa.size)
        var sa = ArrayList<String>()
        for (va in qa)
            sa.add(va.size.toString() + " " + va.joinToString(" "))
        println(sa.joinToString("\n"))
    }
}