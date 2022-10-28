import java.io.*;
import java.util.*;

public class R325qB {
	
	static int n,k;
	static char g[][];
	static int start[],end[];
	static int row[];
	static boolean dp[][],done[][];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int t = in.nextInt();
		
		while(t-- > 0){
			n = in.nextInt();
			k = in.nextInt();
			
			g = new char[3][n];
			for(int i=0;i<3;i++)
				g[i] = in.readString().toCharArray();
			
			start = new int[26];
			end = new int[26];
			row = new int[26];
			Arrays.fill(start, -1);
			Arrays.fill(end, -1);
			Arrays.fill(row,-1);
			
			int sx = -1,sy = -1;
			
			for(int i=0;i<3;i++){
				for(int j=0;j<n;j++){
					if(g[i][j] == 's'){
						sx = i;
						sy = j;
					}
					else if(g[i][j] != '.'){
						if(start[g[i][j] - 'A'] == -1)
							start[g[i][j] - 'A'] = j;
						row[g[i][j] - 'A'] = i;
						end[g[i][j] - 'A'] = j;
					}
				}
			}
			
			/*
			System.out.println(Arrays.toString(start));
			System.out.println(Arrays.toString(end));
			System.out.println(Arrays.toString(row));
			System.out.println(sx + " " + sy);
			*/
			
			dp = new boolean[3][n];
			done = new boolean[3][n];
			
			w.println(go(sx,sy) ? "YES" : "NO");
		}
		
		w.close();
	}
	
	public static boolean go(int x,int y){
		if(x < 0 || x >= 3)	return false;
		if(y == n)	return true;
		if(!done[x][y]){
			done[x][y] = true;
			dp[x][y] = false;
			if(check(x,y+1,y)){
				if(check(x,y+1,y+1) && check(x,y+1,y))
					dp[x][y] |= go(x,y+1);
				if(check(x-1,y+1,y+1) && check(x-1,y+1,y))
					dp[x][y] |= go(x-1,y+1);
				if(check(x+1,y+1,y+1) && check(x+1,y+1,y))
					dp[x][y] |= go(x+1,y+1);
			}
		}
		return dp[x][y];
	}
	
	static boolean check(int x,int y,int z){
		if(x < 0 || x >= 3)	return false;
		for(int i=0;i<26;i++){
			if(row[i] == x){
				int currStart = start[i] - 2*z;
				int currEnd = end[i] - 2*z;
				if(y >= currStart && y <= currEnd)
					return false;
			}
		}
		return true;
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