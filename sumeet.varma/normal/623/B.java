import java.io.*;
import java.util.*;

public class AimTechqB {

	static int n;
	static long A,B;
	static int a[];
	static long inf = (long)1e17;
	
	public static void main(String[] args) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		n = in.nextInt();
		A = in.nextInt();
		B = in.nextInt();

		a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		
		long ans = inf;
		
		ans = Math.min(ans, go(a[0] - 1));
		ans = Math.min(ans, go(a[0]));
		ans = Math.min(ans, go(a[0] + 1));
		ans = Math.min(ans, go(a[n - 1] - 1));
		ans = Math.min(ans, go(a[n - 1]));
		ans = Math.min(ans, go(a[n - 1] + 1));
		
		//System.out.println(go2(5));
		
		w.println(ans);
		w.close();
	}
	
	static long go(int x){
		if(x == 1)
			return inf;
		ArrayList<Integer> p = primes(x);
		long ans = inf;
		for(int y : p)
			ans = Math.min(ans, go2(y));
		return ans;
	}
	
	static long go2(int p){
		if(p == 1)
			return inf;
		
		long cost[] = new long[n];
		long pre[] = new long[n];
		long suf[] = new long[n];
		//boolean yes[] = new boolean[n];
		
		for(int i = 0; i < n; i++){
			int y = a[i] % p;
			cost[i] = Math.min(y, p - y);
			cost[i] = cost[i] == 0 ? 0 : (cost[i] == 1 ? B : inf);
			pre[i] = cost[i];
			if(i > 0)
				pre[i] += pre[i - 1];
			if(pre[i] > inf)
				pre[i] = inf;
		}
		
		for(int i = n - 1; i >= 0; i--){
			suf[i] = cost[i];
			if(i + 1 < n)
				suf[i] += suf[i + 1];
			if(suf[i] > inf)
				suf[i] = inf;
		}
		
		for(int i = n - 1; i >= 0; i--){
			suf[i] += i * A;
			if(suf[i] > inf)
				suf[i] = inf;
		}
		
		//System.out.println(Arrays.toString(cost));
		//System.out.println(Arrays.toString(pre));
		//System.out.println(Arrays.toString(suf));
		
		long ans = pre[n - 1];
		long min = n * A;
		
		for(int i = n - 1; i >= 0; i--){
			long now = pre[i] + min - (i + 1) * A;
			ans = Math.min(ans, now);
			min = Math.min(min, suf[i]);
		}
		
		for(int i = n - 1; i >= 0; i--)
			ans = Math.min(ans, suf[i]);
		
		for(int i = 0; i < n; i++)
			ans = Math.min(ans, pre[i] + (n - 1 - i) * A);
		
		return ans;
	}
	
	static ArrayList<Integer> primes(int x){
		ArrayList<Integer> p = new ArrayList<Integer>();
		for(long i = 2; i*i <= x; i++){
			if(x % i == 0){
				p.add((int)i);
				while(x % i == 0)
					x /= i;
			}
		}
		if(x != 1)
			p.add(x);
		return p;
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