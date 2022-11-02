import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
    var (n, m) = readLine()!!.split(' ').map(String::toInt)
    var s = Array(n, { readLine()!! })

    var sx = 0
    var sy = 0
    var lx = 0
    var ly = 0
    var ex = 0
    var ey = 0
    for (i in 0..n-1) for (j in 0..m-1) {
        if (s[i][j] == 'Y') {
            sx = i
            sy = j
        } else if (s[i][j] == 'B') {
            lx = i
            ly = j
        } else if (s[i][j] == 'T') {
            ex = i
            ey = j
        }
    }

    val bad = { x: Int, y: Int ->
        x < 0 || x >=n || y < 0 || y >= m || s[x][y] == 'X'
    }

    var v = Array(n, { Array(m, { Array(n, { Array(m, {'?'}) }) }) })
    var dis = Array(n, { Array(m, { Array(n, { Array(m, {0}) }) }) })
    v[sx][sy][lx][ly] = '!'
    var q = mutableListOf(sx, sy, lx, ly)
    val dx = listOf(1, 0, -1, 0)
    val dy = listOf(0, 1, 0, -1)
    var qi = 0
    while (qi < q.size) {
        sx = q[qi++]
        sy = q[qi++]
        lx = q[qi++]
        ly = q[qi++]
        val d = dis[sx][sy][lx][ly]
        for (di in 0..3) {
            val nsx = sx + dx[di]
            val nsy = sy + dy[di]
            if (bad(nsx, nsy)) continue
            var nlx = lx
            var nly = ly
            var push = false
            if (nsx == lx && nsy == ly) {
                nlx += dx[di]
                nly += dy[di]
                push = true
            }
            if (bad(nlx, nly)) continue
            if (v[nsx][nsy][nlx][nly] != '?') continue
            q.add(nsx)
            q.add(nsy)
            q.add(nlx)
            q.add(nly)
            if (push) v[nsx][nsy][nlx][nly] = "SENW"[di]
            else v[nsx][nsy][nlx][nly] = "senw"[di]
            dis[nsx][nsy][nlx][nly] = d + 1
        }
    }

    var best_d = 1000000000
    var best_di = -1
    for (di in 0..3) {
        sx = ex - dx[di]
        sy = ey - dy[di]
        if (bad(sx, sy)) continue
        if (v[sx][sy][ex][ey] == '?') continue
        val d = dis[sx][sy][ex][ey]
        if (d < best_d) {
            best_d = d
            best_di = di
        }
    }
    if (best_di == -1) {
        println("NO")
    } else {
        var sol: MutableList<Char> = mutableListOf()
        sx = ex - dx[best_di]
        sy = ey - dy[best_di]
        lx = ex
        ly = ey
        while (v[sx][sy][lx][ly] != '!') {
            val c = v[sx][sy][lx][ly]
            sol.add(c)
            val push = c.isUpperCase()
            var di = -1
            if (c == 's' || c == 'S') di = 0
            if (c == 'e' || c == 'E') di = 1
            if (c == 'n' || c == 'N') di = 2
            if (c == 'w' || c == 'W') di = 3
            sx -= dx[di]
            sy -= dy[di]
            if (push) {
                lx -= dx[di]
                ly -= dy[di]
            }
        }
        sol.reverse()
        println("YES")
        println(sol.joinToString(""))
    }
}