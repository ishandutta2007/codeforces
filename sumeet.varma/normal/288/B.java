import java.io.*;
import java.util.*;

public class R177qBPoloAndPenguins {

	static final int mod = (int)1e9 + 7;
	@SuppressWarnings("unchecked")
	static ArrayList<Integer> list[] = new ArrayList[9];
	static boolean vis[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		int k = in.nextInt();
		
		for(int i=0;i<k;i++)
			list[i] = new ArrayList<Integer>();
		vis = new boolean[k];
		
		long ans = pow(n-k,n-k);
		ans = (ans * k) % mod;
		
		if(k != 1){
			int cnt = 0;
			int wow = (int)pow(k,k-1);
			
			for(int i=0;i<wow;i++){
				

				Arrays.fill(vis, false);
				for(int j=0;j<k;j++)
					list[j].clear();
				
				
				int num = i;
				for(int j=1;j<k;j++){
					list[num % k].add(j);
					num /= k;
				}
			
				dfs(0);
				boolean yes = true;
				for(int j=0;j<k && yes;j++)
					yes &= vis[j];
				if(yes)	
					cnt++;
			}
			
			
						
			ans = (ans * cnt) % mod;
		}
		w.println(ans);
		
		w.close();
	}
	
	static void dfs(int x){
		if(!vis[x]){
			vis[x] = true;
			for(int next : list[x])
				dfs(next);
		}
	}
	
	static long pow(int a,int b){
		if(b == 0)
			return 1;
		long t = pow(a,b/2);
		t = (t * t ) % mod;
		if(b % 2 == 1)
			t = (t * a) % mod;
		return t;
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