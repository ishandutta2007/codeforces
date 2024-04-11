import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
3
7
3 1 6 6 3 1 1
8
1 1 4 4 4 7 8 8
7
4 2 5 2 6 2 7

1
8
1 1 4 4 4 7 8 8
 */
public class B {
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=fs.nextInt()-1;
			int[] lastIndexOf=new int[n];
			int[] firstIndexOf=new int[n];
			Arrays.fill(lastIndexOf, -1);
			Arrays.fill(firstIndexOf, -1);
			for (int i=0; i<n; i++) lastIndexOf[a[i]]=i;
			for (int i=n-1; i>=0; i--) firstIndexOf[a[i]]=i;
			SegTree st=new SegTree(0, n-1);
			int[] bound=new int[n];
			Arrays.fill(bound, -1);
			int realBound=n;
			for (int value=n-1; value>=0; value--) {
				if (lastIndexOf[value]==-1) continue;
				int maxQuery=st.min(0, lastIndexOf[value]);
				realBound=Math.min(realBound, maxQuery==Integer.MAX_VALUE?n:maxQuery);
				bound[value]=realBound;
				st.set(firstIndexOf[value], value);
			}
			int[] cs=new int[n+1];
			for (int i=1; i<cs.length; i++)
				cs[i]=cs[i-1]+(lastIndexOf[i-1]==-1?0:1);
			int ans=0;
			for (int i=0; i<n; i++) {
				if (bound[i]==-1) continue;
				ans=Math.max(ans, cs[bound[i]]-cs[i]);
			}
			out.println(cs[n]-ans);
		}
		out.close();
	}
	
	static class SegTree {
		SegTree lChild, rChild;
		int leftmost, rightmost;
		int min=Integer.MAX_VALUE;
		public SegTree(int leftmost, int rightmost) {
			this.leftmost=leftmost;
			this.rightmost=rightmost;
			if (leftmost!=rightmost) {
				int mid=(leftmost+rightmost)/2;
				lChild=new SegTree(leftmost, mid);
				rChild=new SegTree(mid+1, rightmost);
			}
		}
		
		public void set(int index, int val) {
			min=Math.min(min, val);
			if (leftmost==rightmost) return;
			if (index<=lChild.rightmost)
				lChild.set(index, val);
			else
				rChild.set(index, val);
		}
		
		public int min(int l, int r) {
			if (l<=leftmost&&r>=rightmost) return min;
			if (l>rightmost||r<leftmost) return Integer.MAX_VALUE;
			return Math.min(lChild.min(l, r), rChild.min(l, r));
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
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
	}

}