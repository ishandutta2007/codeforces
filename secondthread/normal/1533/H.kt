import java.io.BufferedReader
import java.io.IOException
import java.io.InputStreamReader
import java.util.*

fun count(grid: Array<BooleanArray>, w: Int, h:Int): Long {
    //count the number of full rectangles in O(size)
    val numAbove=Array<IntArray>(w+1) {IntArray(h) {0} }
    for (x in 0 until w) {
        var count=0;
        for (y in 0 until h) {
            if (grid[x][y]) count++;
            else count=0;
            numAbove[x][y]=count;
        }
    }
    var ans=0L;
    for (y in 0 until h) {
        //maintain a stack
        val stk=IntArray(w+1);
        val stkCount=IntArray(w+1);
        var stkPtr=0;
        var stkSum=0;
        for (x in 0 until w+1) {
            val curHeight=numAbove[x][y];
            var countToAdd=1;
            while (stkPtr>0 && stk[stkPtr-1]>curHeight) {
                val removedHeight = stk[--stkPtr];
                val removedCount=stkCount[stkPtr];
                stkSum-=removedHeight * removedCount;
                countToAdd+=removedCount;
            }
            stk[stkPtr]=curHeight;
            stkCount[stkPtr++]=countToAdd;
            stkSum+=countToAdd * curHeight;
            ans+=stkSum;
        }

    }
    return ans;
}

fun main() {
//    val parts=readLine()!!.split(" ").map { it.toInt() }
//    val w=parts[0]
//    val h=parts[1]
//    val grid=Array<String>(w) {readLine()!!};
//    val start=System.currentTimeMillis();
//    val w=800;
//    val h=800;
//    val grid=Array(w){""};
    val fs=FastScanner();
    val w=fs.nextInt();
    val h=fs.nextInt();
    val grid = Array(w) {fs.next().toCharArray()};
    val ansForMask = LongArray(1 shl 5);
    for (mask in 0 until (1 shl 5)) {
        val boolGrid=Array(w) {BooleanArray(h)};
        for (x in 0 until w) {
            for (y in 0 until h) {
                val char=grid[x][y].toInt()-'A'.toInt();
                boolGrid[x][y] = (mask and (1 shl char)) != 0
            }
        }
        ansForMask[mask]=count(boolGrid, w, h);
    }
    val realAnsForMask = LongArray(1 shl 5);
    for (superMask in 0 until (1 shl 5)) {
        var count=0L;
        for (subMask in 0 until (1 shl 5)) {
            if ((subMask and superMask) != subMask) continue;
            val bitChanges = Integer.bitCount(superMask)-Integer.bitCount(subMask);
            if (bitChanges % 2==0) {
                count+=ansForMask[subMask];
            }
            else {
                count-=ansForMask[subMask];
            }
        }
        realAnsForMask[superMask]=count;
    }

    //TODO: calculate sum of masks by bitcounts
    val answers = LongArray(6) {0};
    for (i in 0 until (1 shl 5))
        answers[Integer.bitCount(i)]+=realAnsForMask[i];
    for (i in 1..5) {
        print("${answers[i]} ");
    }
    println();
//    println("Took ${System.currentTimeMillis()-start}");
}

internal class FastScanner {
    var br = BufferedReader(InputStreamReader(System.`in`))
    var st = StringTokenizer("")
    operator fun next(): String {
        while (!st.hasMoreTokens()) try {
            st = StringTokenizer(br.readLine())
        } catch (e: IOException) {
            e.printStackTrace()
        }
        return st.nextToken()
    }

    fun nextInt(): Int {
        return next().toInt()
    }

    fun readArray(n: Int): IntArray {
        val a = IntArray(n)
        for (i in 0 until n) a[i] = nextInt()
        return a
    }

    fun nextLong(): Long {
        return next().toLong()
    }
}