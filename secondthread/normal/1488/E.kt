import java.lang.Integer.max

/*
1
6
2 1 3 1 5 2
 */
fun main() {
    val T=readLine()!!.toInt();
    repeat(T) {
        val n=readLine()!!.toInt();
        val a=readLine()!!.split(" ").map{it.toInt()};
        val firstIndexOf=IntArray(n+1) {-1}
        val lastIndexOf=IntArray(n+1) {-1}

        for (i in 0 until n) lastIndexOf[a[i]]=i;
        for (i in n-1 downTo 0) firstIndexOf[a[i]]=i;

        val st=SegTree(0, n-1);
        var ans=0;
        for (i in n-1 downTo 0) {
            if (i==lastIndexOf[a[i]]) {
                //just set to 1
                ans=max(ans, 1);
                st.update(i, 1);
            }
            else {
                st.update(i, 1);
                val between=st.rangeQMax(i+1, lastIndexOf[a[i]]-1);
                ans=max(ans, between+2);

                st.update(lastIndexOf[a[i]], between+2);
            }

        }
        println(ans);
    }
}

class SegTree (val leftmost: Int,val rightmost: Int){
    val lChild: SegTree?;
    val rChild: SegTree?;
    var rangeMax: Int = 0;

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

    fun update(index: Int, setTo:Int) {
        if (leftmost==rightmost) {
            rangeMax=setTo;
            return;
        }
        if (index<=lChild!!.rightmost) lChild!!.update(index, setTo);
        else rChild!!.update(index, setTo);
        recalc();
    }

    fun rangeQMax(l: Int, r: Int): Int {
        if (l>rightmost) return 0;
        if (r<leftmost) return 0;
        if (l<=leftmost && r>=rightmost) return rangeMax;
        return max(lChild!!.rangeQMax(l, r), rChild!!.rangeQMax(l, r));
    }

    fun recalc() {
        if (leftmost==rightmost) {
            return;
        }
        rangeMax=max(lChild!!.rangeMax, rChild!!.rangeMax);
    }
}