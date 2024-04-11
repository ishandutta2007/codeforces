import java.io.*;
import java.util.*;

public class R315qC {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int p = in.nextInt();
		int q = in.nextInt();
		
		int N = (int)3e7;
		
		boolean isPrime[] = sieve(N);
		int primes = 0,pali = 0;
		int ans = 0;
		
		for(int i=1;i<=N;i++){
			if(isPrime[i])
				primes++;
			if(isPali(i))
				pali++;
			if(q * 1L * primes <= p * 1L * pali)
				ans = i;
		}
		
		w.println(ans == 0 ? "Palindromic tree is better than splay tree" : ans);
		

		w.close();
	}
	
	public static boolean isPali(int i){
		char s[] = Integer.toString(i).toCharArray();
		for(int j=0;j<s.length;j++)
			if(s[j] != s[s.length - 1- j])
				return false;
		return true;
	}
	
	public static boolean[] sieve(int n){//O(n)
		boolean prime[] = new boolean[n+1];
		Arrays.fill(prime,true);//assume all are prime except 0 and 0
		prime[0] = prime[1] = false;
		
		int m = (int) Math.sqrt(n);
		
		//going only till square root because for n if it had to have a factor it should have been before sqrt(n)//it cant have independent factors later
		
		for(int i=2;i<=m;i++)
			if(prime[i]) //if i is prime then make its multiples unprime
				for(int k=i*i;k<=n;k+=i) //multiples of i till i*i would already be unprime...so starting from i*i because such numbers would be i*j where j=2 to i-1 and they would already have been marked by those numbers
					prime[k] = false;
		
		return prime;
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