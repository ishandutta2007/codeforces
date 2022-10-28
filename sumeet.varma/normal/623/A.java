import java.io.*;
import java.util.*;

public class AimTechqA {

	static int n,m;
	static boolean g[][];
	static int cnt[];
	static int ans[];
	static boolean yes;
	
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		m = in.nextInt();
		
		g = new boolean[n][n];
		
		for(int i = 0; i < m; i++){
			int u = in.nextInt() - 1;
			int v = in.nextInt() - 1;
			g[u][v] = g[v][u] = true;
		}
		
		cnt = new int[n];
		for(int i = 0; i < n; i++)
			for(boolean x : g[i])
				if(x)
					cnt[i]++;
		
		ans = new int[n];
		Arrays.fill(ans, -1);
		yes = true;
		
		for(int i = 0; i < n; i++){
			if(cnt[i] == (n - 1)){
				ans[i] = 1;
			}
		}
		
		for(int i = 0; i < n; i++){
			if(ans[i] == -1){
				boolean now[] = new boolean[n];
				for(int j = 0; j < n; j++)
					if(g[i][j] && ans[j] == -1)
						now[j] = true;
				now[i] = true;
				for(int j = 0; j < n; j++){
					if(now[j]){
						for(int k = 0; k < n; k++){
							if(k == j || ans[k] == 1)
								continue;
							if(now[k])
								yes &= g[j][k];
							else
								yes &= !g[j][k];
						}
						ans[j] = 0;
					}
				}
				break;
			}
		}
		
		for(int i = 0; i < n; i++){
			if(ans[i] == -1){
				boolean now[] = new boolean[n];
				for(int j = 0; j < n; j++)
					if(g[i][j] && ans[j] == -1)
						now[j] = true;
				now[i] = true;
				for(int j = 0; j < n; j++){
					if(now[j]){
						for(int k = 0; k < n; k++){
							if(k == j || ans[k] == 1)
								continue;
							if(now[k])
								yes &= g[j][k];
							else
								yes &= !g[j][k];
						}
						ans[j] = 2;
					}
				}
				break;
			}
		}
		
		for(int i = 0; i < n; i++)
			yes &= ans[i] != -1;
		
		if(yes){
			w.println("Yes");
			for(int i = 0; i < n; i++)
				w.print((char)(ans[i] + 'a'));
		}
		else
			w.println("No");
		w.close();
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