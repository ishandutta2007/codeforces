import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
//		{
//			SegTree st=new SegTree(0, 4);
//			st.add(3, 4, 7);
//			st.add(3, 4, -7);
//			st.add(0, 2, 7);
//			System.out.println(st.min());
//		}
//		if (true) return;
			
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=new int[n];
		long[] costOf=new long[n];
		for (int i=0; i<n; i++) a[i]=fs.nextInt();
		for (int i=0; i<n; i++) costOf[i]=fs.nextLong();
		int[] indexOf=new int[n+1];
		for (int i=0; i<n; i++)
			indexOf[a[i]]=i;
		SegTree st=new SegTree(0, n+1);
		for (int i=0; i<n; i++) {
			st.add(a[i], n+1, costOf[i]);
//			System.out.println("Adding cost of "+costOf[i]+" for value choices between "+a[i]+" and "+(n+1));
		}
		long best=Long.MAX_VALUE;
		for (int i=0; i+1<n; i++) {
//			System.out.println();
//			System.out.println("Processing "+a[i]);
			st.add(a[i], n+1, -costOf[i]);
			st.add(0, a[i]-1, costOf[i]);
//			System.out.println("Adding cost of "+-costOf[i]+" for value choices between "+a[i]+" and "+(n+1));
//			System.out.println("Adding cost of "+costOf[i]+" for value choices between "+0+" and "+(a[i]-1));
			long min=st.min();
//			System.out.println("Min: "+min);
			best=Math.min(best, st.min());
		}
		System.out.println(best);
	}

	static class Event implements Comparable<Event> {
		int time, x1, x2;
		long d;
		public Event(int time, int x1, int x2, long d) {
			this.time=time;
			this.x1=x1;
			this.x2=x2;
			this.d=d;
		}
		
		public int compareTo(Event o) {
			return Integer.compare(time, o.time);
		}
	}
	
	static class SegTree {
		int leftmost, rightmost;
		SegTree lChild, rChild;
		long min, toProp;
		public SegTree(int leftmost, int rightmost) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)/2;
				lChild=new SegTree(leftmost, mid);
				rChild=new SegTree(mid+1, rightmost);
			}
		}
		
		void add(int l, int r, long d) {
			if (leftmost==0 && rightmost==4) {
//				System.out.println(l+" "+r+" "+d);
			}
			if (l<=leftmost && r>=rightmost) {
				toProp+=d;
				return;
			}
			if (l>rightmost ||r <leftmost) {
				return;
			}
			lChild.add(l, r, d);
			rChild.add(l, r, d);
			recalc();
//			System.out.println("  Added "+d+" to kids of "+leftmost+" "+rightmost+" min: "+min+" toProp: "+toProp);
		}
		
		void recalc() {
			if (leftmost==rightmost) return;
//			System.out.println("    recalculating for "+leftmost+" "+rightmost+" lChild: "+lChild.min()+" rChild: "+rChild.min());
			min=Math.min(lChild.min(), rChild.min());
		}
		
		long min() {
//			if (leftmost==0 && rightmost==4) System.out.println("  For node "+leftmost+" "+rightmost+" min: "+min+" toProp "+toProp+" "+lChild.min()+" "+rChild.min());
			return min+toProp;
		}
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreTokens())
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

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

	}

}