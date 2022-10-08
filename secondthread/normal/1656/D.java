import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

/*

1+2 = odd > 1 => 2
1+2+3 + 3x => multiple of 6 => 3
1+2+3+4 +4x => 10+4x = %4==2 => 10

n is an odd number that's at least 3 => 2
n is a multiple of 6 => 3
n=3+2x


 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			long n=fs.nextLong();
			// long n=100+tt;
			if (n==1) {
				out.println(-1);
				continue outer;
			}
			else if (n%2==1) {
				out.println(2);
				continue outer;
			}
			if (Long.bitCount(n)==1) {
				out.println(-1);
				continue outer;
			}
			long powerOf2=1l<<Long.numberOfTrailingZeros(n);
			if (check(n, powerOf2*2)) {
				out.println(powerOf2*2);
				continue outer;
			}
			else {
				if (check(n, n/powerOf2)) {
					out.println(n/powerOf2);
					continue outer;
				}
			}
			throw null;
		}
		// out.println("Missed "+nBreaks);
		out.close();
		
	}

	static boolean check(long n, long cand) {
		if (cand>=1.1e9) return false;
		long toSub=(cand*(cand+1))/2;
		if (n<toSub) return false;
		if ((n-toSub)%cand==0) {
			return true;
		}
		return false;
	}
	
	static final Random random=new Random();
	static final int mod=998244353;
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return (a*b)%mod;
	}
	static long exp(long base, long exp) {
		if (exp==0) return 1;
		long half=exp(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	static long[] factorials=new long[2_000_001];
	static long[] invFactorials=new long[2_000_001];
	static void precompFacts() {
		factorials[0]=invFactorials[0]=1;
		for (int i=1; i<factorials.length; i++) factorials[i]=mul(factorials[i-1], i);
		invFactorials[factorials.length-1]=exp(factorials[factorials.length-1], mod-2);
		for (int i=invFactorials.length-2; i>=0; i--)
			invFactorials[i]=mul(invFactorials[i+1], i+1);
	}
	
	static long nCk(int n, int k) {
		return mul(factorials[n], mul(invFactorials[k], invFactorials[n-k]));
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}


	static class PollardRho {
		static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a % b); }
	
		static Random r = new Random();
	
		static ArrayList<Long> getPrimeFactors(long n) {
			ArrayList<Long> factors = new ArrayList<>();
			getPrimeFactors(n, factors);
			// Collections.sort(factors); if you want multiplicities in a row
			return factors;
		}
	
		static void getPrimeFactors(long n, ArrayList<Long> factors) {
			if (n <= 1) {
			} else if (BigInteger.valueOf(n).isProbablePrime(30))  factors.add(n);
			else {
				long d = rho(n);  getPrimeFactors(d, factors);
				getPrimeFactors(n / d, factors);
			}
		}
	
		// returns a small non-trivial divisor of n (n must not be prime)
		static long rho(long n) {
			if ((n & 1) == 0)  return 2;
			long x, y, d;  BigInteger ab, nb;
	
			nb = BigInteger.valueOf(n);
			do {
				ab = BigInteger.valueOf(Math.abs(r.nextInt(100_000)) + 2);
				x = y = Math.abs(r.nextInt(100_000)) + 2;
				do {
					x = poly(x, ab, nb);  y = polypoly(y, ab, nb);
					d = gcd(n, Math.abs(x - y));
				} while (d == 1);
			} while (d == n);
			return d;
		}
	
		static long poly(long x, BigInteger ab, BigInteger nb) {
			BigInteger xb = BigInteger.valueOf(x);
			return xb.multiply(xb).add(ab).mod(nb).longValue();
		}
	
		static long polypoly(long x, BigInteger ab, BigInteger nb) {
			BigInteger xb = BigInteger.valueOf(x), p = xb.multiply(xb).add(ab);
			return p.multiply(p).add(ab).mod(nb).longValue();
		}
	}
	
}