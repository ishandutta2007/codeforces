import java.io.*;
import java.util.*;


public class GoodBye15qD {

	static SuffixArray_nlogn S;
	static RmqSparseTable rmq;
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();

		final int mod = (int)1e9 + 7;
		
		char s[] = in.readString().toCharArray();
		S = new SuffixArray_nlogn(s);
		S.buildSA();
		S.buildLCP();
		//System.out.println(Arrays.toString(S.sa));
		//System.out.println(Arrays.toString(S.rank));
		//System.out.println(Arrays.toString(S.lcp));
		
		rmq = new RmqSparseTable(S.lcp);
		
		int dp[][] = new int[n + 1][n + 1];
		//0 dont care // 1 care
		dp[n][n] = dp[n][n] = 1;
		
		for(int i = n - 1; i >= 0; i--){
			for(int j = n - 1; j >= i; j--){
				if(s[i] == '0')
					continue;
				int l = j - i + 1;
				dp[i][j] = dp[i][j+1];
				if(j < n - 1){
					if(j + l < n){
						int lcp = S.lcp[rmq.minPos(Math.min(S.rank[i],S.rank[j + 1]), Math.max(S.rank[i], S.rank[j + 1]) - 1)];
						if(lcp < l && s[j + lcp + 1] > s[i + lcp])
							dp[i][j] += dp[j+1][j+l];
						else{
							if(j + l + 1 <= n)
								dp[i][j] += dp[j+1][j+l+1];
						}
						if(dp[i][j] >= mod)
							dp[i][j] -= mod;
					}
				}
				else{
					dp[i][j]++;
					if(dp[i][j] >= mod)
						dp[i][j] -= mod;
				}
				//System.out.println(i + " " + j + " " +  dp[i][j]);
			}
		}

		w.println(dp[0][0]);
		w.close();
	}
	
	public boolean can(int i,int j,int k){
		if(k - j > j - i)
			return true;
		if(k - j < j - i)
			return false;
		return false;
	}
	
	public static class SuffixArray_nlogn {

		static int n;
		static char s[];
		static int sa[],rank[],lcp[];
		
		
		SuffixArray_nlogn(char o[]){
			n = o.length;
			s = new char[n];
			for(int i = 0; i < n; i++)
				s[i] = o[i];
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
				classes[i] = s[i];
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
					for (int j = sa[rank[i] + 1]; Math.max(i, j) + h < n && s[i + h] == s[j + h]; ++h)
						;
					lcp[rank[i]] = h;
					if (h > 0)
						--h;
				}
			}
			
			
		}
		
		public static class myComp implements Comparator<Integer>{
			public int compare(Integer a,Integer b){
				return Character.compare(s[a],s[b]);
			}
		}

	}

	static public class RmqSparseTable {

		  int[] logTable;
		  int[][] rmq;
		  int[] a;

		  public RmqSparseTable(int[] a) {
		    this.a = a;
		    int n = a.length;

		    logTable = new int[n + 1];
		    for (int i = 2; i <= n; i++)
		      logTable[i] = logTable[i >> 1] + 1;

		    rmq = new int[logTable[n] + 1][n];

		    for (int i = 0; i < n; ++i)
		      rmq[0][i] = i;

		    for (int k = 1; (1 << k) < n; ++k) {
		      for (int i = 0; i + (1 << k) <= n; i++) {
		        int x = rmq[k - 1][i];
		        int y = rmq[k - 1][i + (1 << k - 1)];
		        rmq[k][i] = a[x] <= a[y] ? x : y;
		      }
		    }
		  }

		  public int minPos(int i, int j) {
		    int k = logTable[j - i];
		    int x = rmq[k][i];
		    int y = rmq[k][j - (1 << k) + 1];
		    return a[x] <= a[y] ? x : y;
		  }
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar, snumChars;
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