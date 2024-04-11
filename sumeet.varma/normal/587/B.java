import java.io.*;
import java.util.*;

public class R326qB {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		final int mod = (int)1e9 + 7;
		
		int n = in.nextInt();
		long l = in.nextLong();
		int k = in.nextInt();
		
		int a[] = new int[n];
		for(int i=0;i<n;i++)
			a[i] = in.nextInt();
		
		Pair p[] = new Pair[n];
		for(int i=0;i<n;i++)
			p[i] = new Pair(i,a[i]);

		Arrays.sort(p);
		
		int dp[][] = new int[k][n];
		Arrays.fill(dp[0], 1);
		int proAns[] = new int[k];
		proAns[0] = n;
		
		for(int len=1;len<k;len++){
			
			int stillNow = 0;
			
			for(int i=0;i<n;){
				int j = i;
				while(j < n && p[j].val == p[i].val){
					stillNow += dp[len-1][p[j].idx];
					if(stillNow >= mod)	stillNow -= mod;
					j++;
				}
				for(int x=i;x<j;x++){
					dp[len][p[x].idx] = stillNow;
					proAns[len] += stillNow;
					if(proAns[len] >= mod)
						proAns[len] -= mod;
				}
				i = j;
			}
			
		}
		
		//System.out.println(Arrays.toString(dp[1]));
		
		long mainAns = 0;
		long floor = l / n;
		
		for(int i=0;i<k && floor>0;i++,floor--){
			mainAns += ((floor % mod) * proAns[i]) % mod;
			if(mainAns >= mod)	mainAns -= mod;
		}
		
		//System.out.println(mainAns);
		int left = (int)(l % n);
		floor = l / n;
		int t = (int)Math.min(floor + 1,k);
	
		for(int i=0;i<t;i++){
			int wowNow = 0;
			for(int j=0;j<left;j++){
				wowNow += dp[i][j];
				if(wowNow >= mod)
					wowNow -= mod;
			}
			mainAns += wowNow;
			if(mainAns >= mod)
				mainAns -= mod;
		}
		
		w.println(mainAns % mod);
		w.close();
	}
	
	static class Pair implements Comparable<Pair>{
		int idx,val;
		Pair(int i,int v){
			idx = i;
			val = v;
		}
		public int compareTo(Pair o){
			if(val != o.val)
				return Integer.compare(val, o.val);
			return Integer.compare(idx, o.idx);
		}
		public String toString(){
			return idx + " " + val;
		}
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