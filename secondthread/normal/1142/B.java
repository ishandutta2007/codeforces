import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int permLen=fs.nextInt(), arrLen=fs.nextInt(), nQueries=fs.nextInt();
		int[] perm=new int[permLen];
		for (int i=0; i<permLen; i++) perm[i]=fs.nextInt()-1;
		int[] indexInPerm=new int[permLen];
		for (int i=0; i<permLen; i++) indexInPerm[perm[i]]=i;
		int[] next=new int[permLen];
		for (int i=0; i<permLen; i++)
			next[i]=perm[(1+indexInPerm[i])%permLen];
		
		int[] arr=new int[arrLen];
		for (int i=0; i<arrLen; i++) arr[i]=fs.nextInt()-1;
		
		int[][] lift=new int[arrLen][20];
		int[] nextInd=new int[permLen]; Arrays.fill(nextInd, -1);
		for (int i=arrLen-1; i>=0; i--) {
			lift[i][0]=nextInd[next[arr[i]]];
			nextInd[arr[i]]=i;
		}
		
		for (int e=1; e<20; e++)
			for (int i=0; i<arrLen; i++)
				if (lift[i][e-1]==-1)
					lift[i][e]=-1;
				else
					lift[i][e]=lift[lift[i][e-1]][e-1];
		
		Query[] queries=new Query[nQueries];
		Query[] sorted=new Query[nQueries];
		for (int i=0; i<nQueries; i++) sorted[i]=queries[i]=new Query(fs.nextInt()-1, fs.nextInt()-1);
		Arrays.sort(sorted);
		int firstEnd=arrLen+1;
		int l=arrLen;
		for (Query q:sorted) {
			while (l>q.l) {
				l--;
				int end=forwardN(l, lift, permLen-1);
				if (end==-1) continue;
				else {
					firstEnd=Math.min(firstEnd, end);
				}
			}
			q.ans=firstEnd<=q.r;
		}
		PrintWriter out=new PrintWriter(System.out);
		for (Query q:queries) {
			out.print(q.ans?'1':'0');
		}
		out.println();
		out.close();
	}
	
	static int forwardN(int from, int[][] lift, int toMove) {
		if (from==-1) return -1;
		if (toMove==0) return from;
		int trailing=Integer.numberOfTrailingZeros(toMove);
		return forwardN(lift[from][trailing], lift, toMove-(1<<trailing));
	}
	
	static class Query implements Comparable<Query> {
		int l, r;
		boolean ans;
		
		public Query(int l, int r) {
			this.l=l;
			this.r=r;
		}
		
		public int compareTo(Query o) {
			return -Integer.compare(l, o.l);
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