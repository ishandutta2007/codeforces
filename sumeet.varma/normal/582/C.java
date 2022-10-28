import java.io.*;
import java.util.*;

public class R323qC {
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		
		int a[] = new int[n];
		for(int i=0;i<n;i++)
			a[i] = in.nextInt();
		
		int GCD[] = new int[n + 1];
		for(int i=1;i<=n;i++)
			GCD[i] = gcd(i,n);
		
		int max[] = new int[n];
		int prefix[] = new int[n + 1];
		
		long ans = 0;
		
		for(int gcd=1;gcd<n;gcd++){
			
			if(n % gcd != 0)
				continue;
			
			for(int i=0;i<gcd;i++)
				max[i] = 0;
			
			for(int i=0;i<n;i++){
				int t = i % gcd;
				max[t] = Math.max(a[i], max[t]);
			}
			
			for(int i=1;i<n;i++)
				prefix[i] = prefix[i-1] + ( GCD[i] == gcd ? 1 : 0 );
			prefix[n] = prefix[n-1];
			
			int len = 0;
			
			for(int i=2*n-1;i>=0;i--){
				int val = i >= n ? a[i-n] : a[i];
				int t = i >= n ? (i - n) % gcd : i % gcd;
				if(val == max[t])
					len++;
				else
					len = 0;
				if(i < n)
					ans += prefix[Math.min(len, n)];
			}
			
		}
		
		w.println(ans);
		w.close();
	}
	
	public static int gcd(int a,int b){
		int temp=0;
		while(b!=0){
			temp = b;
			b = a%b;
			a = temp;
		}
		return a;
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