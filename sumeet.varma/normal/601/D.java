import java.io.*;
import java.util.*;

//java.is.awesome

public class R333qD {

	static int n;
	static int c[];
	static char s[];
	static ArrayList<Integer> g[];
	static int idx[][], tot[];
	static int max, ans;
	
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		c = in.nextIntArray(n);
		s = in.readString().toCharArray();

		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<Integer>();
		
		for(int i = 1; i < n; i++){
			int u = in.nextInt() - 1;
			int v = in.nextInt() - 1;
			g[u].add(v);
			g[v].add(u);
		}

		idx = new int[n][26];
		tot = new int[n];
		max = -1; ans = 0;
		dfs(0 , -1);
		
		w.println(max);
		w.println(ans);
		w.close();
	}
	
	public static void dfs(int curr, int prev){
		tot[curr] = 1;
		for(int next : g[curr]){
			if(next != prev){
				dfs(next, curr);
				if(idx[curr][s[next] - 'a'] == 0){
					idx[curr][s[next] - 'a'] = next;
					tot[curr] += tot[next];
				}
				else{
					tot[curr] -= tot [ idx[curr][s[next] - 'a'] ];
					merge(idx[curr][s[next] - 'a'], next);
					tot[curr] += tot [ idx[curr][s[next] - 'a'] ];
				}
			}
		}
		if(tot[curr] + c[curr] > max){
			max = tot[curr] + c[curr];
			ans = 0;
		}
		if(tot[curr] + c[curr] == max)
			ans++;
	}
	
	static void merge(int u, int v){
		tot[u] = 1;
		for(int i = 0; i < 26; i++){
			if(idx[v][i] > 0){
				if(idx[u][i] > 0)
					merge(idx[u][i] , idx[v][i]);
				else
					idx[u][i] = idx[v][i];
			}
			if(idx[u][i] > 0)
				tot[u] += tot[idx[u][i]];
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