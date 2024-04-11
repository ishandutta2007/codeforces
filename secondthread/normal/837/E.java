import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
/*
3 5

6 3
 */
public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		long a=fs.nextLong(), b=fs.nextLong();
		long ans=solve(a, b);
		System.out.println(ans);
	}
	
	static long solve(long a, long b) {
		if (b==0) return 0;
		ArrayList<Long> aFacts=primeFactors(a);
		long minSub=b;
		for (long l:aFacts)
			minSub=Math.min(minSub, b%l);
		b-=minSub;
		long gcd=gcd(a, b);
		a/=gcd;
		b/=gcd;
		return minSub+solve(a, b);
	}
	
	static long gcd(long a, long b) {
		if (b==0) return a;
		return gcd(b, a%b);
	}
	
	static ArrayList<Long> primeFactors(long n) {
		long on=n;
		ArrayList<Long> toReturn=new ArrayList<>();
		for (long i=2; i*i<=on; i++) {
			while (n%i==0) {
				n/=i;
				toReturn.add(i);
			}
		}
		if (n!=1) {
			toReturn.add(n);
		}
		return toReturn;
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
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
	}
}