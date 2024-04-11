import java.io.*;
import java.util.*;

public class R331qD {
	
	/*
	static int n,h;
	static double p;
	static int x[];
	static int right[],left[];
	static double dp[][][][];
	 */
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		int h = in.nextInt();
		double p = Double.parseDouble(in.readString());
		
		int x[] = new int[n + 2];
		for(int i=1;i<=n;i++)
			x[i] = in.nextInt();
		
		x[0] = -(int)5e8;
		x[n + 1] = (int)5e8;
		
		Arrays.sort(x);
		
		int right[] = new int[n + 1];
		right[n] = n;
		for(int i=n-1;i>=1;i--){
			if(x[i+1] - x[i] >= h)
				right[i] = i;
			else
				right[i] = right[i + 1];
		}
		
		int left[] = new int[n + 1];
		left[1] = 1;
		for(int i=2;i<=n;i++){
			if(x[i] - x[i-1] >= h)
				left[i] = i;
			else
				left[i] = left[i-1];
		}
		
		double dp[][][][] = new double[2][2][n + 1][n + 1];
		
		for(int l=0;l<2;l++){
			for(int r=0;r<2;r++){
				for(int start=1,end=1;start<=n;start++,end++){
					double ans = 0;
					if(l == 1)
						ans += p * Math.min(x[start] - (x[start - 1] + h), h);
					else
						ans += p * Math.min(x[start] - x[start - 1], h);
					if(r == 1)
						ans += (1 - p) * Math.min(x[end + 1] - h - x[end], h);
					else
						ans += (1 - p) * Math.min(x[end + 1] - x[end], h);
					dp[l][r][start][end] = ans;
				}
			}
		}
		
		for(int len=1;len<n;len++){
			for(int start=1;start+len<=n;start++){
				int end = start + len;
				for(int l=0;l<2;l++){
					for(int r=0;r<2;r++){
						double ans1 = 0,ans2 = 0;
						if(l == 1)
							ans1 += p * (Math.min(x[start] - (x[start - 1] + h), h) + dp[0][r][start + 1][end]);
						else
							ans1 += p * (Math.min(x[start] - x[start - 1], h) + dp[0][r][start + 1][end]);
						
						if(right[start] >= end)
							ans1 += (1 - p) * ((x[end] - x[start]) + Math.min(h, x[end + 1] - x[end] - (r == 0 ? 0 : h)));
						else
							ans1 += (1 - p) * ((x[right[start]] - x[start] + h) + dp[1][r][right[start] + 1][end]);
						
						if(r == 1)
							ans2 += (1 - p) * (Math.min(x[end + 1] - x[end] - h, h) + dp[l][0][start][end - 1]);
						else
							ans2 += (1 - p) * (Math.min(x[end + 1] - x[end], h) + dp[l][0][start][end - 1]);
						
						if(left[end] <= start)
							ans2 += p * ( (x[end] - x[start]) + Math.min(h, x[start] - x[start - 1] - (l == 0 ? 0 : h)) );
						else
							ans2 += p * ( (x[end] - x[left[end]] + h) + dp[l][1][start][left[end] - 1]);
						
						dp[l][r][start][end] = (ans1 + ans2) / 2;
					}
				}
			}
		}
		
		w.println(dp[0][0][1][n]);
		
		w.close();
	}
	
	/*
	static double go(int l,int r,int start,int end){
		if(dp[l][r][start][end] == -1){
			
			if(start == end){
				double ans = 0;
				if(l == 1)
					ans += p * Math.min(x[start] - (x[start - 1] + h), h);
				else
					ans += p * Math.min(x[start] - x[start - 1], h);
				if(r == 1)
					ans += (1 - p) * Math.min(x[end + 1] - h - x[end], h);
				else
					ans += (1 - p) * Math.min(x[end + 1] - x[end], h);
				dp[l][r][start][end] = ans;
			}
			
			else{
				double ans1 = 0,ans2 = 0;
				if(l == 1)
					ans1 += p * (Math.min(x[start] - (x[start - 1] + h), h) + go(0,r,start + 1,end));
				else
					ans1 += p * (Math.min(x[start] - x[start - 1], h) + go(0,r,start + 1,end));
				
				if(right[start] >= end)
					ans1 += (1 - p) * ((x[end] - x[start]) + Math.min(h, x[end + 1] - x[end] - (r == 0 ? 0 : h)));
				else
					ans1 += (1 - p) * ((x[right[start]] - x[start] + h) + go(1,r,right[start] + 1,end));
				
				if(r == 1)
					ans2 += (1 - p) * (Math.min(x[end + 1] - x[end] - h, h) + go(l,0,start,end - 1));
				else
					ans2 += (1 - p) * (Math.min(x[end + 1] - x[end], h) + go(l,0,start,end - 1));
				
				if(left[end] <= start)
					ans2 += p * ( (x[end] - x[start]) + Math.min(h, x[start] - x[start - 1] - (l == 0 ? 0 : h)) );
				else
					ans2 += p * ( (x[end] - x[left[end]] + h) + go(l,1,start,left[end] - 1));
				
				dp[l][r][start][end] = (ans1 + ans2) / 2;
			}
			
		}
		
		return dp[l][r][start][end];
	}*/
	
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