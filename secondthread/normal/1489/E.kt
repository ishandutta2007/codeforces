import java.lang.Integer.min

fun main() {
    val q=readLine()!!.toInt();
    val indexOf= mutableMapOf<Int, Int>();
    var (l, r) = listOf(0, 1)
    repeat(q) {
        val line=readLine()!!;
        val id=line.split(" ")[1].toInt();
        if (line[0]=='L') {
            indexOf[id] = l--;
        }
        else if (line[0]=='R') {
            indexOf[id] = r++;
        }
        else {
            val index=indexOf[id]!!;
            println(min(index-l, r-index)-1);
        }
    }
}