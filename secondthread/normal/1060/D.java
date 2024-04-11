import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class D {
	static long mod=998244353;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		PriorityQueue<Integer> l=new PriorityQueue<>(), r=new PriorityQueue<>();
		long total=n;
		for (int i=0; i<n; i++) {
			int ll=fs.nextInt(), rr=fs.nextInt();
			total+=ll+rr;
			l.add(ll);
			r.add(rr);
		}
		while (!l.isEmpty()) {
			int ll=l.poll(), rr=r.poll();
			total-=Math.min(ll, rr);
		}
		System.out.println(total);
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