

data class Edge(val from: Int, val to: Int, val cost: Long)

fun main() {
    val (n, m) = readLine()!!.split(" ").map{it.toInt()}
    val a=readLine()!!.split(" ").map { it.toLong() }
    var mindex=0;
    for (i in 0 until n)
        if (a[i]<a[mindex]) mindex=i;
    val edges= mutableListOf<Edge>();
    repeat(m) {
        val line=readLine()!!.split(" ");
        val from=line[0].toInt();
        val to=line[1].toInt();
        val cost=line[2].toLong();
        edges.add(Edge(from-1, to-1, cost));
    }
    for (i in 0 until n)
        edges.add(Edge(i, mindex, a[mindex]+a[i]));
    edges.sortBy { it.cost }
    val dj=DJS(n);
    var ans=0L
    edges.forEach{
        if (dj.join(it.from, it.to)) ans+=it.cost
    }
    println(ans);
}

class DJS(n: Int) {
    private var par: MutableList<Int> = MutableList<Int>(n) {-1}
    fun find(i: Int): Int {
        if (par[i]<0) {
            return i
        }
        else {
            par[i]=find(par[i])
            return par[i];
        }
    }
    fun join(ii: Int, jj:Int): Boolean {
        val i=find(ii);
        val j=find(jj);
        if (i==j) return false;
        if (par[i]==par[j]) par[i]--;
        if (par[i]<=par[j])
            par[j]=i;
        else
            par[i]=j;
        return true;
    }
}