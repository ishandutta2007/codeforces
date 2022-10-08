import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		long n=fs.nextLong(), oBase=fs.nextLong();
		long base=oBase;
		
		long nZeros=Long.MAX_VALUE;
		//prime factorize base
		ArrayList<Long> primes=new ArrayList<>();
		ArrayList<Integer> primeTimes=new ArrayList<>();
		for (long prime=2; prime*prime<=oBase; prime++) {
			int times=0;
			while (base%prime==0) {
				base/=prime;
				times++;
			}
			if (times!=0) {
				primes.add(prime);
				primeTimes.add(times);
			}
		}
		if (base!=1) {
			primes.add(base);
			primeTimes.add(1);
		}
		
		for (int index=0; index<primes.size(); index++) {
			long p=primes.get(index), times=primeTimes.get(index);
			long appears=countTimes(p, n);
			appears/=times;
			nZeros=Math.min(appears, nZeros);
		}
		System.out.println(nZeros);
	}
	
	static long countTimes(long prime, long n) {
		long ans=0;
		long cur=1;
		while (true) {
			try {
				cur=Math.multiplyExact(cur, prime);
			} catch(Throwable T) {
				break;
			}
			ans+=n/cur;
			
		}
		return ans;
	}
	
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
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
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}

}