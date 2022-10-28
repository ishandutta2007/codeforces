import java.io.*;
import java.util.*;

//java.is.awesome

public class R302qDRoadImprovement{
	
	static int n;
	static ArrayList<Integer> g[];
	static int p[], pid[];
	static final int mod = (int)1e9 + 7;
	static long down[];
	static long up[];
	static long pre[][], suf[][];

	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		
		p = new int[n];
		pid = new int[n];
		
		g = new ArrayList[n];
		for(int i = 0; i < n; i++)
			g[i] = new ArrayList<Integer>();
		
		for(int i = 1; i < n; i++){
			p[i] = in.nextInt() - 1;
			pid[i] = g[p[i]].size();
			g[p[i]].add(i);
		}
		
		pre = new long[n][];
		suf = new long[n][];
		for(int i = 0; i < n; i++){
			pre[i] = new long[g[i].size()];
			suf[i] = new long[g[i].size()];
		}
		
		down = new long[n];
		dfs(0);
		
		/*System.out.println(Arrays.toString(down));
		System.out.println(Arrays.toString(pre[0]));
		System.out.println(Arrays.toString(suf[0]));*/
		
		up = new long[n];
		dfs2(0);
		
		for(int i = 0; i < n; i++)
			w.print(((up[i] * down[i]) % mod) + " ");
		
		w.println();
		w.close();
	}
	
	static void dfs(int c){
		down[c] = 1;
		for(int i = 0; i < g[c].size(); i++){
			int next = g[c].get(i);
			dfs(next);
			pre[c][i] = (1 + down[next]) % mod;
			down[c] = (down[c] * (1 + down[next])) % mod;
			if(i != 0)
				pre[c][i] = (pre[c][i - 1] * pre[c][i]) % mod;
		}
		for(int i = g[c].size() - 1; i >= 0; i--){
			int next = g[c].get(i);
			suf[c][i] = (1 + down[next]) % mod;
			if(i + 1 < g[c].size())
				suf[c][i] = (suf[c][i] * suf[c][i + 1]) % mod;	
		}
	}
	
	static void dfs2(int c){
		if(c == 0)
			up[c] = 1;
		else{
			up[c] = up[p[c]];
			if(pid[c] - 1 >= 0)
				up[c] = (up[c] * pre[p[c]][pid[c] - 1]) % mod;
			if(pid[c] + 1 < g[p[c]].size())
				up[c] = (up[c] * suf[p[c]][pid[c] + 1]) % mod;
			up[c] = (1 + up[c]) % mod;
		}
		for(int x : g[c])
			dfs2(x);
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