import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class D {
	static long mod=998244353;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		int full=(1<<k)-1;
		int[] a=fs.readArray(n);
		HashMap<Integer, Integer> timesSeen=new HashMap<>();
		int offset=0;
		long bestCount=0;
		for (int i:a) {
			 int toZeroCount=timesSeen.getOrDefault(offset^i, 0) + (i==0?1:0);
			 int toFullCount=timesSeen.getOrDefault(full^offset^i, 0)+(i==full?1:0);
			 if (toZeroCount<toFullCount) {
				 bestCount+=toZeroCount;
			 }
			 else {
				 bestCount+=toFullCount;
				 i^=full;
			 }
			 offset^=i;
			 timesSeen.put(i^offset, timesSeen.getOrDefault(i^offset, 0)+1);
		}
		System.out.println(n*(long)(n+1)/2-bestCount);
		
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

	/*static class PollardRho {
		static Random r = new Random();

		static ArrayList<Long> getPrimeFactors(long n, boolean weak) {
			ArrayList<Long> factors = new ArrayList<>();
			getPrimeFactors(n, factors, true);
			// Collections.sort(factors); if you want multiplicities in a row
			return factors;
		}

		static void getPrimeFactors(long n, ArrayList<Long> factors, boolean first) {
			if (first) {
				long d = rho(n); 
				factors.add(d);
				factors.add(n/d);
			}
		}

		// returns a small non-trivial divisor of n (n must not be prime)
		static long rho(long n) {
			if (n <= 3)  return -1;
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
		
		static long gcd(long a, long b) {
			return b==0?a:gcd(b, a%b);
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
	*/
}