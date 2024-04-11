import java.io.*;
import java.util.*;

public class WunderFundqD {

	static int n;
	static long x,y;
	static ArrayList<Integer> g[];
	static int MD[][];
	static int c[];
	static final int INF = (int)2e8;
	
	public static void main(String args[]) throws Exception {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		x = in.nextInt();
		y = in.nextInt();
		
		g = new ArrayList[n];
		for(int i = 0; i < n; i++)
			g[i] = new ArrayList<Integer>();
			
		for(int i = 1; i < n; i++){
			int u = in.nextInt() - 1;
			int v = in.nextInt() - 1;
			g[u].add(v);
			g[v].add(u);
		}
		
		MD = new int[n][2];
		c = new int[n];
		dfs(0, -1);
		
		int maxDegree = 0;
		for(int i = 0; i < n; i++)
			maxDegree = Math.max(maxDegree, g[i].size());
		
		long maxNonTree = n - 1;
		if(maxDegree == n - 1)
			maxNonTree--;
		long ans = maxNonTree * y + (n - 1 - maxNonTree) * x;
		long maxTree = Math.max(MD[0][0], MD[0][1]);
		ans = Math.min(ans, maxTree * x + (n - 1 - maxTree) * y);
		//System.out.println(maxNonTree + " " + maxTree);
		
		w.println(ans);
		w.close();
	}
	
	static void dfs(int curr, int prev){
		for(int next : g[curr]){
			if(next != prev){
				dfs(next, curr);
				c[curr]++;
			}
		}
		if(c[curr] == 0)
			MD[curr][0] = MD[curr][1] = 0;
		else{
			int sum = 0;
			int pro[] = new int[c[curr]];
			int x = 0;
			for(int next : g[curr]){
				if(next != prev){
					sum += MD[next][0];
					pro[x++] = MD[next][0] - MD[next][1];
				}
			}
			Arrays.sort(pro);
			MD[curr][1] = sum;
			MD[curr][1] = Math.max(MD[curr][1], sum - pro[0] + 1);
			MD[curr][0] = MD[curr][1];
			if(c[curr] >= 2)
				MD[curr][0] = Math.max(MD[curr][0], sum - pro[0] - pro[1] + 2);
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

		public int[] nextIntArray(int n) {
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
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