import kotlin.math.max

fun main() {
    val line=readLine()!!;
    val n=line.length;
    val zeroCountAtMe=IntArray(n);
    val oneCountAtMe=IntArray(n);
    var zeroCount=0;
    line.forEach { if (it=='0') zeroCount++ }
    var oneCount=n-zeroCount;
    val indexOfKthZero=IntArray(zeroCount);
    val indexOfKthOne=IntArray(oneCount);
    zeroCount=0;
    oneCount=0;
    for (i in 0 until n) {
        zeroCountAtMe[i]=zeroCount;
        oneCountAtMe[i]=oneCount;
        if (line[i]=='0') {
            indexOfKthZero[zeroCount]=i;
            zeroCount++;
        }
        else {
            indexOfKthOne[oneCount]=i;
            oneCount++;
        }
    }

    for (jumpBy in 1..n) {
        //assume we haven't counted this index
        var at=0;
        var steps=0;
        while (true) {
            steps++;
            val startZCount = zeroCountAtMe[at]
            val startOCount = oneCountAtMe[at]
            if (startZCount + jumpBy >= zeroCount) break;
            if (startOCount + jumpBy >= oneCount) break;
            val nextO=indexOfKthOne[startOCount+jumpBy];
            val nextZ=indexOfKthZero[startZCount+jumpBy];
            at= max(nextO, nextZ)
        }

        print("$steps ")
    }
    println();
}