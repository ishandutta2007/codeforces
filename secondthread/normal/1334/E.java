import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class E {

	static long[] facts=new long[1_000_000];
	static long[] factInv=new long[1_000_000];
	static final long mod=998244353;
	
	public static void main(String[] args) {
		precomp();
		FastScanner fs=new FastScanner();
		long D=fs.nextLong();
		ArrayList<Long> primes=PollardRho.getPrimeFactors(D);
		Collections.sort(primes);
		
		TreeSet<Long> uniquePrimes=new TreeSet<>();
		for (long l:primes) uniquePrimes.add(l);
		int nPrimes=uniquePrimes.size();
		HashMap<Long, Integer> compress=new HashMap<>();
		for (long l:uniquePrimes) compress.put(l, compress.size());
		long[] uncompress=new long[nPrimes];
		int index=0;
		for (long l:uniquePrimes) uncompress[index++]=l;
		
		int[] maxCounts=new int[nPrimes];
		for (long l:primes)maxCounts[compress.get(l)]++;
		int[] counts=new int[nPrimes];
		
		HashMap<Long, Long> ans=new HashMap<>();
		while (true) {
			long val=1;
			long nWays=1;
			int totalExps=0;
			for (int i=0; i<nPrimes; i++) {
				totalExps+=counts[i];
				for (int j=0; j<counts[i]; j++)
					val*=uncompress[i];
				nWays=mul(nWays, factInv[counts[i]]);
			}
			nWays=mul(nWays, facts[totalExps]);
			ans.put(val, nWays);
			if (counts.length==0) {
				ans.put(1l, 1l);
				break;
			}
			counts[0]++;
			int digit=0;
			while (digit<nPrimes && counts[digit]>maxCounts[digit]) {
				counts[digit]=0;
				digit++;
				if (digit<nPrimes) counts[digit]++;
			}
			if (digit>=nPrimes) break;
		}
		
		int Q=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<Q; qq++) {
			long a=fs.nextLong(), b=fs.nextLong();
			long gcd=gcd(a, b);
			long w1=ans.get(a/gcd);
			long w2=ans.get(b/gcd);
			out.println(mul(w1, w2));
		}
		out.close();
	}
	
	static void precomp() {
		facts[0]=factInv[0]=1;
		for (int i=1; i<facts.length; i++)
			facts[i]=mul(facts[i-1], i);
		factInv[factInv.length-1]=modInv(facts[facts.length-1]);
		for (int i=factInv.length-2; i>=0; i--)
			factInv[i]=mul(factInv[i+1], i+1);
	}
	
	static long mul(long a, long b) {
		return a*b%mod;
	}
	
	static long modInv(long x) {
		return pow(x, mod-2);
	}
	
	static long pow(long base, long exp) {
		if (exp==0) return 1;
		long half=pow(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}

	static long gcd(long a, long b) {
		return b==0?a:gcd(b, a%b);
	}
	
	static class PollardRho {
		static Random r=new Random();

		static ArrayList<Long> getPrimeFactors(long n) {
			ArrayList<Long> factors=new ArrayList<>();
			getPrimeFactors(n, factors);
			// Collections.sort(factors); if you want multiplicities in a row
			return factors;
		}

		static void getPrimeFactors(long n, ArrayList<Long> factors) {
			if (n<=1) {
			} else if (BigInteger.valueOf(n).isProbablePrime(30))
				factors.add(n);
			else {
				long d=rho(n);
				getPrimeFactors(d, factors);
				getPrimeFactors(n/d, factors);
			}
		}

		// returns a small non-trivial divisor of n (n must not be prime)
		static long rho(long n) {
			if (n<=3)
				return -1;
			if ((n&1)==0)
				return 2;
			long x, y, d;
			BigInteger ab, nb;

			nb=BigInteger.valueOf(n);
			do {
				ab=BigInteger.valueOf(Math.abs(r.nextInt(100_000))+2);
				x=y=Math.abs(r.nextInt(100_000))+2;
				do {
					x=poly(x, ab, nb);
					y=polypoly(y, ab, nb);
					d=gcd(n, Math.abs(x-y));
				} while (d==1);
			} while (d==n);
			return d;
		}

		
		
		static long poly(long x, BigInteger ab, BigInteger nb) {
			BigInteger xb=BigInteger.valueOf(x);
			return xb.multiply(xb).add(ab).mod(nb).longValue();
		}

		static long polypoly(long x, BigInteger ab, BigInteger nb) {
			BigInteger xb=BigInteger.valueOf(x), p=xb.multiply(xb).add(ab);
			return p.multiply(p).add(ab).mod(nb).longValue();
		}
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}

}