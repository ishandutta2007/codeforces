import java.io.*;
import java.util.*;

//java.is.awesome

public class R302qBDestroyingRoads{

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		
		@SuppressWarnings("unchecked")
		ArrayList<Integer> g[] = new ArrayList[n];
		for(int i = 0; i < n; i++)
			g[i] = new ArrayList<Integer>();
		
		for(int i = 0; i < m; i++){
			int u = in.nextInt() - 1;
			int v = in.nextInt() - 1;
			g[u].add(v);
			g[v].add(u);
		}
		
		int d[][] = new int[n][n];
		
		for(int i = 0; i < n; i++){
			Arrays.fill(d[i], 1000000);
			d[i][i] = 0;
			Queue<Integer> q = new ArrayDeque<Integer>();
			q.add(i);
			while(!q.isEmpty()){
				int c = q.remove();
				for(int x : g[c]){
					if(d[i][c] + 1 < d[i][x]){
						d[i][x] = 1 + d[i][c];
						q.add(x);
					}
				}
			}
		}
		
		int s1 = in.nextInt() - 1;
		int t1 = in.nextInt() - 1;
		int l1 = in.nextInt();
		
		int s2 = in.nextInt() - 1;
		int t2 = in.nextInt() - 1;
		int l2 = in.nextInt();
		
		if(d[s1][t1] > l1 || d[s2][t2] > l2){
			System.out.println(-1);
			return;
		}
		
		int ans = m - d[s1][t1] - d[s2][t2];
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				{
					int d1 = d[s1][i] + d[i][j] + d[j][t1];
					int d2 = d[s2][i] + d[i][j] + d[j][t2];
					if(d1 <= l1 && d2 <= l2)
						ans = Math.max(ans, m - (d1 + d2 - d[i][j]));
				}
				{
					int d1 = d[s1][i] + d[i][j] + d[j][t1];
					int d2 = d[s2][j] + d[j][i] + d[i][t2];
					if(d1 <= l1 && d2 <= l2)
						ans = Math.max(ans, m - (d1 + d2 - d[i][j]));
				}
			}
		}
		
		w.println(ans);
		w.close();
	}
	
	static class Pair implements Comparable<Pair>{
		int idx,x,y;
		Pair(int idx, int x, int y){
			this.idx = idx;
			this.x = x;
			this.y = y;
		}
		public int compareTo(Pair o){
			int z = Long.compare(x * 1L * o.y, o.x * 1L * y);
			return z == 0 ? Integer.compare(idx, o.idx) : z;
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