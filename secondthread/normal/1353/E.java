import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) throws FileNotFoundException {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
//		Scanner fs=new Scanner(new File("E.in"));
//		PrintWriter out=new PrintWriter(new File("E.out"));
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt();
			char[] line=fs.next().toCharArray();
			boolean[] a=new boolean[n];
			for (int i=0; i<n; i++) a[i]=line[i]=='1';
			int[] forOffset=new int[k];
			for (int i=0; i<n; i++) if (a[i]) forOffset[i%k]++;
			int forOffsetSum=0;
			for (int i:forOffset) forOffsetSum+=i;
			long best=n+1;
			for (int offset=0; offset<k; offset++) {
				int penalty=forOffsetSum-forOffset[offset];
//				System.out.println("Penalty for offset: 0");
				boolean[] smaller=new boolean[(n-offset+k-1)/k];
				for (int i=0; i<smaller.length; i++)
					smaller[i]=a[offset+k*i];
				best=Math.min(best, penalty+go(smaller));
			}
			out.println(best);
		}
		out.close();
	}
	
	static long go(boolean[] a) {
		int nOnes=0;
		for (boolean b:a) if (b) nOnes++;
		long ans=Math.max(0, nOnes-1);
		int n=a.length;
		SegTree st=new SegTree(0, n-1);
		for (int l=n-1; l>=0; l--) {
			if (a[l]) {
				nOnes--;
				st.update(0, l-1, 1);
			}
			else {
				st.update(l, n-1, 1);
			}
			ans=Math.min(ans, nOnes+st.rangeMin(l, n-1));
		}
		return ans;
	}
	
	static class SegTree {
		int leftmost, rightmost;
		SegTree lChild, rChild;
		int min, offset;
		
		public SegTree(int leftmost, int rightmost) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)/2;
				lChild=new SegTree(leftmost, mid);
				rChild=new SegTree(mid+1, rightmost);
			}
		}
		
		public void update(int l, int r, int by) {
			if (l<=leftmost && r>=rightmost) {
				offset+=by;
				return;
			}
			if (l>rightmost ||r<leftmost) return;
			lChild.update(l, r, by);
			rChild.update(l, r, by);
			recalc();
		}
		
		public void recalc() {
			if (leftmost==rightmost) return;
			min=Math.min(lChild.min(), rChild.min());
		}
		
		public int min() {
			return min+offset;
		}
		
		public long rangeMin(int l, int r) {
			if (l<=leftmost && r>=rightmost) return min();
			if (l>rightmost || r<leftmost) return Long.MAX_VALUE/2;
			return offset+Math.min(lChild.rangeMin(l, r), rChild.rangeMin(l, r));
		}
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