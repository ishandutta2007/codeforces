import java.io.*;
import java.util.*;

public class R305qGMikeAndFriends {

	static int n,N,Q;
	static StringBuilder S;
	static int start[], len[];
	static int sa[], rank[], lcp[];
	static int logs[],z[][];
	static Query q[];
	static int[] ans;
	static BIT bit;

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		N = in.nextInt();
		Q = in.nextInt();

		S = new StringBuilder("");
		len = new int[N + 1];

		for (int i = 1; i <= N; i++) {
			int x = in.snext();
			while (in.isSpaceChar(x))
				x = in.snext();
			while (!in.isSpaceChar(x)) {
				S.append((char) x);
				len[i]++;
				x = in.snext();
			}
			S.append('$');
		}

		n = S.length();
		start = new int[N + 2];

		int which = 1;
		for (int i = 0; i < n; i++) {
			if (S.charAt(i) == '$') {
				which++;
				start[which] = i + 1;
			}
		}

		// System.out.println("S " + S);
		// System.out.println("start " + Arrays.toString(start));
		
		buildSA();
		buildLCP();
		buildLogs();
		buildSparseTableMin();

		// System.out.println("sa " + Arrays.toString(sa));
		// System.out.println("lcp " + Arrays.toString(lcp));
		// System.out.println("rank " + Arrays.toString(rank));

		q = new Query[2*Q];
		for(int q=0;q<Q;q++)
			go(in.nextInt(),in.nextInt(),in.nextInt(),q);
	
		solveQueriesOffline();
		
		for(int q=0;q<Q;q++)
			w.println(ans[2*q + 1] - ans[2*q]);
		
		w.close();
	}
	
	public static void solveQueriesOffline(){
		//System.out.println("OrderedQuer " + Arrays.deepToString(q));
		Arrays.sort(q);
		//System.out.println("SortedQuer " + Arrays.deepToString(q));
		
		ans = new int[2*Q];
		int curr = 0;
		bit = new BIT(n);
				
		for(int i=0;i<2*Q;i++){
			while(curr < q[i].k){
				++curr;
				for(int j=start[curr];j<start[curr+1] - 1;j++){
					//System.out.println(rank[j]);
					bit.update(rank[j] + 1);
				}
			}
			//System.out.println(q[i].l + " " + q[i].r);
			ans[q[i].idx] = bit.query(q[i].l + 1, q[i].r + 1);
		} 
	}
	
	public static void go(int l,int r,int k,int id){
		int idx = rank[start[k]];
		//System.out.println(id + " " + idx);
		
		int right = -1,start = idx,end = n,mid;
		
		while(start < end){
			mid = (start + end) >> 1;
			if(queryMin(idx,mid) >= len[k]){
				right = mid;
				start = mid + 1;
			}
			else
				end = mid;
		}
		
		int left = -1;
		start = 0; end = idx;
		
		while(start < end){
			mid = (start + end) >> 1;
			if(queryMin(mid,idx-1) >= len[k])
				left = end = mid;
			else
				start = mid + 1;
		}
		
		if(right != -1 && right != n-1)
			right++;
		if(left == -1)
			left = idx;
		if(right == -1)
			right = idx;
		
		q[2*id] = new Query(left,right,l-1,2*id);
		//System.out.println(2*id + " " + q[2*id]);
		q[2*id + 1] = new Query(left,right,r,2*id+1);
		//System.out.println((2*id + 1) + " " + q[2*id + 1]);
	}
	
	public static void buildLogs(){
		logs = new int[n+1];
	    int g=2;
	    while(g <= n){
	    	logs[g] = 1;
	    	g = (g << 1);
		}
	    for(int i=1;i<=n;i++)
	    	logs[i] += logs[i - 1];
	}
	
	public static void buildSparseTableMin(){
		int p,g; 
		z = new int[21][n];
		for(int i=0;i<n;i++)
			z[0][i] = lcp[i];
		for (int j = 1; (1<<j) < n; j++)
	         for (int i = 0; i + (1<<j) <= n; i++){
	        	 g=z[j-1][i];
	        	 p=z[j-1][i + (1<<(j-1))];
	             z[j][i]= g<p?g:p;
	          }
	}
	
	public static int queryMin(int l,int r){
		int k = logs[r - l + 1];
		return z[k][l] <= z[k][r - (1<<k) + 1] ? z[k][l] : z[k][r - (1<<k) + 1];
	}

	public static void buildSA() {
		Integer[] order = new Integer[n];
		for (int i = 0; i < n; i++)
			order[i] = n - 1 - i;

		Arrays.sort(order, new myComp());

		sa = new int[n];
		int[] classes = new int[n];
		for (int i = 0; i < n; i++) {
			sa[i] = order[i];
			classes[i] = S.charAt(i);
		}

		for (int len = 1; len < n; len *= 2) {
			int[] c = classes.clone();
			for (int i = 0; i < n; i++)
				classes[sa[i]] = i > 0 && c[sa[i - 1]] == c[sa[i]]
						&& sa[i - 1] + len < n
						&& c[sa[i - 1] + len / 2] == c[sa[i] + len / 2] ? classes[sa[i - 1]] : i;

			int[] cnt = new int[n];
			for (int i = 0; i < n; i++)
				cnt[i] = i;
			
			int[] s = sa.clone();
			for (int i = 0; i < n; i++) {
				int s1 = s[i] - len;
				if (s1 >= 0)
					sa[cnt[classes[s1]]++] = s1;
			}
		}

	}

	public static void buildLCP() {
		rank = new int[n];
		for (int i = 0; i < n; i++)
			rank[sa[i]] = i;
		
		lcp = new int[n];
		
		for (int i = 0, h = 0; i < n; i++) {
			if (rank[i] < n - 1) {
				for (int j = sa[rank[i] + 1]; Math.max(i, j) + h < S.length() && S.charAt(i + h) == S.charAt(j + h); ++h)
					;
				lcp[rank[i]] = h;
				if (h > 0)
					--h;
			}
		}
	}

	public static class myComp implements Comparator<Integer> {
		public int compare(Integer a, Integer b) {
			return Character.compare(S.charAt(a), S.charAt(b));
		}
	}
	
	public static class BIT{
		int tree[];
		BIT(int n){
			tree = new int[n + 1];
		}
		
		void update(int idx){
			while(idx <= n){
				tree[idx]++;
				idx += (idx & -idx);
			}
		}
		
		int query(int l,int r){
			return read(r) - read(l-1);
		}
		
		int read(int idx){
			int sum = 0;
			while(idx > 0){
				sum += tree[idx];
				idx -= (idx & -idx);
			}
			return sum;
		}
	}
	
	//number of elements from l to r less than <= k
	public static class Query implements Comparable<Query>{
		int l,r,k,idx;
		Query(int l,int r,int k,int idx){
			this.idx = idx;
			this.l = l;
			this.r = r;
			this.k = k;
		}
		public int compareTo(Query o){
			return Integer.compare(k, o.k);
		}
		public String toString(){
			return l + " " + r + " " + k + " " + idx;
		}
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			int res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}

		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			long res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}

		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}

}