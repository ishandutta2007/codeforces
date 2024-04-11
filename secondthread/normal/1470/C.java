import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class C {

	static int n;
	static int nQueries=0;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		n=fs.nextInt();
		int k=fs.nextInt();
		int jumpBy=BigInteger.valueOf((int)Math.sqrt(n)).nextProbablePrime().intValue();
		while (gcd(n, jumpBy) !=1) {
			jumpBy = BigInteger.valueOf(jumpBy).nextProbablePrime().intValue();
		}
		if (jumpBy >= n) {
			//in case n is small
			jumpBy=1;
		}
		if (gcd(n, jumpBy)!=1) {
			System.out.println(n+" "+jumpBy);
			throw null;//while (true);
		}
		int at=0;
		while (true) {
			int val=query(at, fs);
			if (val<k) {
				//we found an instance!
				break;
			}
			else {
				at+=jumpBy;
				at%=n;
			}
		}
		int min=at, max=at+(n+1)/2-1;
		while (min!=max) {
			int mid=(min+max+1)/2;
			if (query(mid%n, fs)<k) {
				min=mid;
			}
			else {
				max=mid-1;
			}
		}
		min=(min+1)%n;
		System.out.println("! "+(min+1));
	}
	
	static int query(int x, FastScanner fs) {
		if (++nQueries >= 999) while(true);
		if (x<0 || x>=n) while(true);
		System.out.println("? "+(x+1));
		return fs.nextInt();
	}
	
	static int gcd(int a, int b) {
		if (b==0) return a;
		return gcd(b, a%b);
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

	
}