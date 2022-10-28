import java.io.*;
import java.util.*;

public class R333qATheTwoRoutes {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		int m = in.nextInt();
		
		
		boolean rail[][] = new boolean[n + 1][n + 1];
		
		while(m-- > 0){
			int u = in.nextInt();
			int v = in.nextInt();
			rail[u][v] = rail[v][u] = true;
		}
		
		boolean yes = !rail[1][n];
		
		Queue<Integer> q = new LinkedList<Integer>();
		boolean vis[] = new boolean[n + 1];
		int ans[] = new int[n + 1];
		Arrays.fill(ans, (int)1e8);
		vis[1] = true;
		q.add(1);
		ans[1] = 0;
		
		while(!q.isEmpty()){
			int curr = q.remove();
			for(int i=1;i<=n;i++){
				if(!vis[i] && rail[curr][i] == yes){
					vis[i] = true;
					ans[i] = ans[curr] + 1;
					q.add(i);
				}
			}
		}
		
		w.println(ans[n] >= (int)1e8 ? -1 : ans[n]);
		w.close();
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		
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
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}

}