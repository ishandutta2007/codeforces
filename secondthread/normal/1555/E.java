import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

/*
 * 0 1 2 3 4 5
 * 01234567890
 */
public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int m=fs.nextInt();
		ST st=new ST(0, (m-1)*2);
		Seg[] segs=new Seg[n];
		for (int i=0; i<n; i++) 
			segs[i]=new Seg((fs.nextInt()-1)*2, (fs.nextInt()-1)*2, fs.nextInt());
		Arrays.sort(segs);
		
		int l=0, r=-1;
		long ans=Long.MAX_VALUE;
		outer: while (l<n) {
			while (st.min()==0) {
				r++;
				if (r>=n) break outer;
				st.rangeAdd(segs[r].l, segs[r].r, 1);
			}
			//TODO: consider possible answer
			ans=Math.min(ans, segs[r].cost-segs[l].cost);
			
			st.rangeAdd(segs[l].l, segs[l].r, -1);
			l++;
		}
		System.out.println(ans);
	}
	
	static class Seg implements Comparable<Seg> {
		int l, r, cost;
		public Seg(int l, int r, int cost) {
			this.l=l;
			this.r=r;
			this.cost=cost;
		}
		public int compareTo(Seg o) {
			return Integer.compare(cost, o.cost);
		}
	}

	static class ST {
		int leftmost, rightmost, toProp, min;
		ST lChild, rChild;
		
		public ST(int l, int r) {
			leftmost=l;
			rightmost=r;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)/2;
				lChild=new ST(l, mid);
				rChild=new ST(mid+1, r);
			}
		}
		
		public void recalc() {
			if (lChild!=null)
				min=Math.min(lChild.min(), rChild.min());
		}
		public void prop() {
			if (leftmost!=rightmost) {
				lChild.toProp+=toProp;
				rChild.toProp+=toProp;
				toProp=0;
			}
			recalc();
		}
		
		void rangeAdd(int l, int r, int d) {
			if (l>rightmost || r<leftmost) return;
			if (l<=leftmost && r>=rightmost) {
				toProp+=d;
				return;
			}
			lChild.rangeAdd(l, r, d);
			rChild.rangeAdd(l, r, d);
			
			recalc();
		}
		
		int min() {
			return min+toProp;
		}
		
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}