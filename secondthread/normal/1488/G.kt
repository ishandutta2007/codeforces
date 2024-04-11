import java.util.*

data class PQEntry(val id: Int, val value: Int) {}

fun count(x: Int, used: BooleanArray):Int {
    var count=0;
    for (i in x+x until used.size step x)
        if (!used[i]) count++;
//    println("Counting $x returns $count");
    return count;
}
fun main() {
    val n = readLine()!!.toInt();
    var timesReliedOn = IntArray(n+1) {0};
    var used = BooleanArray(n+1) {false};
    val compareByValue: Comparator<PQEntry> = compareBy { -it.value }
    val pq = PriorityQueue<PQEntry> (compareByValue);

    var answers= mutableListOf<Int>();
    answers.add(0);
    for (i in 1 until n+1) {
        pq.add(PQEntry(i, count(i, used)-timesReliedOn[i]));
    }
    var sum=0;
    repeat(n-1) {
        while (pq.peek().value != count(pq.peek().id, used)-timesReliedOn[pq.peek().id]) {
//            println(" skipping instance of ${pq.peek().id} ${pq.peek().value}");
            pq.remove();
        }

        val toUseItem=pq.remove();
        val toUse = toUseItem.id;
        sum+=toUseItem.value;
//        println("Using $toUse ${toUseItem.value}");
        answers.add(sum);
        used[toUse]=true;
        for (i in toUse+toUse until timesReliedOn.size step toUse) {
            timesReliedOn[i]++
            pq.add(PQEntry(i, count(i, used)-timesReliedOn[i]));
            //TODO: update all factors of ourselves??
        };
    }

    answers.reverse();
    println(answers.joinToString(" "));
}