import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class G3 {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), toAdd=fs.nextInt();
		long[] difficulties=new long[n], costs=new long[n];
		for (int i=0; i<n; i++) {
			difficulties[i]=fs.nextInt();
			costs[i]=toAdd-fs.nextInt();
		}
		
		//if they are all negative, just pick the best one
		boolean allNeg=true;
		long maxDiff=0;
		for (long l:costs) {
			if (l>0) allNeg=false;
			maxDiff=Math.max(maxDiff, l);
		}
		if (allNeg) {
			System.out.println(maxDiff);
			return;
		}
		
		//otherwise we can actually make money and we don't need to worry about adding zeros
		Event[] events=new Event[n-1];
		for (int i=0; i+1<n; i++) events[i]=new Event(i, difficulties[i+1]-difficulties[i]);

		long best=0;
		Treap[] treaps=new Treap[n];
		for (int i=0; i<n; i++) {
			treaps[i]=new Treap(costs[i]);
			best=Math.max(best, treaps[i].maxInternal);
		}
		Arrays.sort(events);
		for (Event e:events) {
			long cost=e.delta*e.delta;
			int lInd=e.leftIndex;
			Treap lRoot=Treap.getRoot(treaps[lInd]);
			Treap rRoot=Treap.getRoot(treaps[lInd+1]);
			Treap newRoot=Treap.merge(lRoot, rRoot);
			long newBest=newRoot.maxInternal;
			best=Math.max(best, newBest-cost);
		}
		System.out.println(best);
	}
	
	static class Event implements Comparable<Event> {
		int leftIndex;
		long delta;
		public Event(int leftIndex, long delta) {
			this.leftIndex=leftIndex;
			this.delta=delta;
		}
		
		public int compareTo(Event o) {
			return Long.compare(delta, o.delta);
		}
	}

	static final Random rand=new Random(5);
	// lower priority on top, all methods return the new treap root
	// To add new seg-tree supported properties, edit recalc()
	// To add lazyprop values, edit recalc() and prop()

	// If you only add by merging, skip add() and rebalance()
	// If you don't need lazyprop, skip prop() and rangeAdd()
	static class Treap {
		long data;
		int priority;
		Treap[] kids=new Treap[2];
		Treap par;
		
		int subtreeSize;
		long sum;
		long maxPrefix;
		long maxSuffix;
		long maxInternal;
		
		public Treap(long data) {
			this.data=data;
			priority=rand.nextInt();
			recalc(this);
		}
		
		//returns lefthalf, rightHalf
		//nInLeft is size of left treap, aka index of first thing in right treap
		static Treap[] split(Treap me, int nInLeft) {
			if (me==null) return new Treap[] {null, null};
			if (size(me.kids[0])>=nInLeft) {
				if (me.kids[0]!=null) me.kids[0].par=null;
				Treap[] leftRes=split(me.kids[0], nInLeft);
				me.kids[0]=leftRes[1];
				if (me.kids[0]!=null) me.kids[0].par=me;
				recalc(me);
				return new Treap[] {leftRes[0], me};
			}
			else {
				nInLeft=nInLeft-size(me.kids[0])-1;
				if (me.kids[1]!=null) me.kids[1].par=null;
				Treap[] rightRes=split(me.kids[1], nInLeft);
				me.kids[1]=rightRes[0];
				if (me.kids[1]!=null) me.kids[1].par=me;
				recalc(me);
				return new Treap[] {me, rightRes[1]};
			}
		}
		
		static Treap merge(Treap l, Treap r) {
			if (l==null) return r;
			if (r==null) return l;
			if (l.priority<r.priority) {
				l.kids[1]=merge(l.kids[1], r);
				l.kids[1].par=l;
				recalc(l);
				return l;
			}
			else {
				r.kids[0]=merge(l, r.kids[0]);
				r.kids[0].par=r;
				recalc(r);
				return r;
			}
		}
		
		static void recalc(Treap me) {
			if (me==null) return;
			me.subtreeSize=1;
			me.sum=me.data;
			for (Treap t:me.kids) if (t!=null) me.subtreeSize+=t.subtreeSize;
			for (Treap t:me.kids) if (t!=null) me.sum+=t.sum;
			me.maxInternal=0;
			for (Treap t:me.kids) if (t!=null) me.maxInternal=Math.max(me.maxInternal, t.maxInternal);
			me.maxInternal=Math.max(me.maxInternal, maxSuffix(me.kids[0])+me.data+maxPrefix(me.kids[1]));
			me.maxPrefix=0;
			me.maxPrefix=Math.max(me.maxPrefix, Math.max(maxPrefix(me.kids[0]), sum(me.kids[0])+me.data+maxPrefix(me.kids[1])));
			me.maxSuffix=0;
			me.maxSuffix=Math.max(me.maxSuffix, Math.max(maxSuffix(me.kids[1]), sum(me.kids[1])+me.data+maxSuffix(me.kids[0])));
		}
		
		static long maxPrefix(Treap t) {
			return t==null?0:t.maxPrefix;
		}
		
		static long maxSuffix(Treap t) {
			return t==null?0:t.maxSuffix;
		}
		
		static long sum(Treap t) {
			return t==null?0:t.sum;
		}
		
		static int size(Treap t) {
			return t==null?0:t.subtreeSize;
		}
		
		static Treap getRoot(Treap t) {
			while (t.par!=null) t=t.par;
			return t;
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}