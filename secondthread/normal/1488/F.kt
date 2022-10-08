import java.util.*

val BLOCK_SIZE=400;

class Query(val l: Int, val r: Int) {
    var ans=-1L;
}

fun main() {
    val n=readLine()!!.toInt();
    val a=readLine()!!.split(" ").map{it.toInt()};
    val nQueries=readLine()!!.toInt();
    val queriesUnsorted=Array<Query>(nQueries) {
        val (l, r) = readLine()!!.split(" ").map{it.toInt()};
        Query(l-1, r-1);
    };
    val queries=queriesUnsorted.clone();
    queries.sortBy{it.r};
    val st=SegTree(0, n-1);
    val stack=Stack<Int>()
    var qIndex=0;
    for (i in 0 until n) {
//        println("Processing i: $i");
        val cur=a[i];
        //TODO: update segtree
        while (!stack.isEmpty() && a[stack.peek()]<=cur) {
            stack.pop();
//            println("  Popping from stack")
        }
        val prev=if (stack.isEmpty()) 0 else stack.peek() +1;
        st.rangeSet(prev, i, cur);
//        println("  range setting $prev $i $cur");
        stack.add(i);

        //TODO: answer queries with q.r == i
        while (qIndex<nQueries && queries[qIndex].r==i) {
            val qq=queries[qIndex]
            qq.ans=st.rangeQSum(qq.l, qq.r);
//            println("  Answer to query is ${qq.ans}");
            qIndex++;
        }
    }
    println(queriesUnsorted.map{it.ans}.joinToString(" "));
}

class SegTree (val leftmost: Int,val rightmost: Int){
    val lChild: SegTree?;
    val rChild: SegTree?;
    var setTo: Int = -1;
    var sum = 0L;

    init {
        if (leftmost==rightmost) {
            lChild=null;
            rChild=null;
        }
        else {
            val mid=(leftmost+rightmost)/2;
            lChild=SegTree(leftmost, mid);
            rChild=SegTree(mid+1, rightmost);
        }
    }

    fun rangeQSum(l: Int, r: Int): Long {
        if (r<leftmost || l>rightmost) return 0;
        if (l<=leftmost && r>=rightmost) return sum();
        prop();
        return lChild!!.rangeQSum(l, r)+ rChild!!.rangeQSum(l, r);
    }

    fun sum(): Long {
        if (setTo==-1) return sum;
        return setTo.toLong()*(rightmost-leftmost+1);
    }

    fun prop() {
        if (setTo==-1) return;
        if (leftmost==rightmost) {
            sum=setTo.toLong();
            return;
        }
        lChild!!.rangeSet(leftmost, rightmost, setTo);
        rChild!!.rangeSet(leftmost, rightmost, setTo);
        setTo=-1;
        recalc();
    }

    fun rangeSet(l: Int, r: Int, setToo: Int) {
        if (l>rightmost || r<leftmost) return;
        if (l<=leftmost && r>=rightmost) {
            setTo = setToo;
            return;
        }
        prop();
        lChild!!.rangeSet(l, r, setToo);
        rChild!!.rangeSet(l, r, setToo);
        recalc();
    }

    fun recalc() {
        if (leftmost==rightmost) {
            return;
        }
        sum=lChild!!.sum()+rChild!!.sum();
    }
}