
/*
thoughts on round 728

4
a
b
ab
ae
aea
eab

aeab

PSSPPS
 */
fun main() {
    val n = readLine()!!.toInt();
    val strings = mutableListOf<String>();
    for (i in 0 until 2*n-2)
        strings.add(readLine()!!);
    val sortedByLen = strings.sortedBy { it.length }
    val full1SB=StringBuilder();
    val full2SB=StringBuilder();
    val big1=sortedByLen[sortedByLen.size-2];
    val big2=sortedByLen.last();
    full1SB.append(big1);
    full1SB.append(big2.last());
    full2SB.append(big2);
    full2SB.append(big1.last());
    val full1=full1SB.toString();
    val full2=full2SB.toString();

    var v1Works=true;
    var v2Works=true;
    for (i in 0 until sortedByLen.size step 2) {
        if ((full1.startsWith(sortedByLen[i]) && full1.endsWith(sortedByLen[i+1])) ||
                (full1.startsWith(sortedByLen[i+1]) && full1.endsWith(sortedByLen[i]))) {
        }
        else {
            v1Works=false;
        }
        if ((full2.startsWith(sortedByLen[i]) && full2.endsWith(sortedByLen[i+1])) ||
                (full2.startsWith(sortedByLen[i+1]) && full2.endsWith(sortedByLen[i]))) {
        }
        else {
            v2Works=false;
        }
    }
    val used=if (v1Works) full1 else full2;
    if (!v1Works && !v2Works) throw Error();

    val usedPrefix = BooleanArray(n){false};
    for (s in strings) {
        if (usedPrefix[s.length]) print('S');
        else if (used.startsWith(s)) {
            usedPrefix[s.length]=true;
            print('P')
        }
        else print('S')
    }

    println();
}