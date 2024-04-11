import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;

public class R324qD {

	public static void main(String args[]) {
		
		InputReader in = new InputReader(System.in);
		int n = in.nextInt();
		
		if(isPrime(n)){
			System.out.println(1);
			System.out.println(n);
			return;
		}
		
		if(isPrime(n-2)){
			System.out.println(2);
			System.out.println(2 + " " + (n-2));
			return;
		}
		
		boolean prime[] = sieve(2000001);
		
		for(int i=2;i<=500;i++){
			for(int j=i;j<=500;j++){
				int k = n - i - j;
				if(k >= 1 && prime[i] && prime[j] && isPrime(k) && (i+j+k) == n){
					System.out.println(3);
					System.out.println(i + " " + j + " " + k);
					return;
				}
			}
		}
		
		for(int i=3;i<=2000000;i+=2){
			if(prime[i] && (n-i-3) >=1 && isPrime(n-i-3)){
				System.out.println(3);
				System.out.println(3 + " " + i + " " + (n-i-3));
				return;
			}
		}
		
		throw new RuntimeException();
	}
	
	public static boolean[] sieve(int n){
		boolean prime[] = new boolean[n+1];
		Arrays.fill(prime,true);
		prime[0] = prime[1] = false;
		
		int m = (int) Math.sqrt(n) + 1;
		for(int i=2;i<=m;i++)
			if(prime[i]) 
				for(int k=i*i;k<=n;k+=i) 
					prime[k] = false;
		
		return prime;
	}
	
	public static boolean isPrime(int n){
		if(n <= 1) return false;
		if(n == 2) return true;
		if(n % 2 == 0) return false;
		int m = (int) (Math.sqrt(n) + 15); //2 is not a factor coz we would have returned false then
		m = Math.min(m, n-1);
		for(int i = 3;i <= m;i += 2) //if a*b = n then atleat one of a,b <= m
			if(n % i == 0) return false;
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