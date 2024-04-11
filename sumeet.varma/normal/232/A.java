import java.io.*;
import java.util.*;

public class R144qACycles {

	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int k = in.nextInt();
		pro(k);

		w.close();
	}
	
	static void pro(int K){
		int KK = K;
		
		boolean g[][] = new boolean[101][101];
		for(int i = 0; i + 1 < 100; i++)
			g[i][i + 1] = g[i + 1][i] = true;
		
		for(int i = 2; i < 100; i++){
			for(int j = 0,x = 1; j + 1 < i && x <= K; j++, x++){
				K -= x;
				g[j][i] = g[i][j] = true;
			}
		}
		
		System.out.println(100);
		for(int i = 0; i < 100; i++){
			for(int j = 0; j < 100; j++)
				System.out.print(g[i][j] ? 1 : 0);
			System.out.println();
		}
		
		/*
		int ans = 0;
		for(int i = 0; i < 100; i++)
			for(int j = i + 1; j < 100; j++)
				for(int k = j + 1; k < 100; k++)
					if(g[i][j] && g[j][k] && g[k][i])
						ans++;
		for(int i = 0; i < 100; i++)
			for(int j = 0; j < 100; j++)
				if(g[i][j] != g[j][i])
					System.out.println("WA");
		for(int i = 0; i < 100; i++)
			if(g[i][i])
				System.out.println("WA");
		System.out.println(ans == KK);*/
	}
	
	static void solve(int k){
		int x = k;
		int y = 0;
		ArrayList<Integer> id = new ArrayList<Integer>();
		ArrayList<Integer> sz = new ArrayList<Integer>();
		int set[] = new int[101];
		
		for(int j = 100; j >= 3; j--){
			int K = j * (j - 1) * (j - 2) / 6;
			while(true){
				if(K <= x && y + j <= 97){
					y += j;
					x -= K;
					id.add(y - j);
					sz.add(j);
				}
				else
					break;
			}
			
		}
		
		while(y < 100){
			for(int i = 0; i < sz.size(); i++){
				for(int j = sz.get(1) ; j >= 2; j--){
					int now = j * (j - 1) / 2;
					if(now <= x){
						x -= now;
						set[i] = j;
						break;
					}
				}
			}
			y++;
		}
		
		System.out.println(x);
	}
	
	static void go(int k){
		boolean g[][] = new boolean[101][101];
		for(int i = 0; i < 100; i++)
			for(int j = 0; j < 100; j++)
				g[i][j] = true;
		for(int i = 0; i < 100; i++)
			g[i][i] = false;
	
		int com[][] = new int[101][101];
		for(int i = 0; i < 100; i++)
			for(int j = i + 1; j < 100; j++)
				com[i][j] = 100 - 2;
		
		int ans = 100 * 99 * 98 / 6;
		while(ans > k){
			for(int i = 0; i < 100; i++){
				for(int j = i + 1; j < 100; j++){
					if(g[i][j] && ans - com[i][j] >= k){
						g[i][j] = false;
						ans -= com[i][j];
						com[i][j] = 0;
						for(int x = 0; x < 100; x++){
							if((g[i][x] || g[x][i]) && (g[j][x] || g[x][j])){
								com[x][i]--;
								com[i][x]--;
								com[x][j]--;
								com[j][x]--;
							}
						}
					}
				}
			}
			System.out.println(ans);
		}
	
		System.out.println(ans);
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