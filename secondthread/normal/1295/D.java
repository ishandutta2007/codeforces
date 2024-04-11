import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int t=fs.nextInt();
		for (int tt=0; tt<t; tt++) {
			long a=fs.nextLong(), b=fs.nextLong();
			long gcd=gcd(a, b);
			b/=gcd;
			System.out.println(phi(b));
		}
	}
	
	static long phi(long n) {
		ArrayList<Factor> facts=getPrimeFactorsOf(n);
		long ans=1;
		for (Factor f:facts) {
			long prod=f.factor-1;
			for (int i=1;i<f.times; i++) prod*=f.factor;
			ans*=prod;
		}
		return ans;
	}
	
	static ArrayList<Factor> getPrimeFactorsOf(long n) {
		ArrayList<Factor> toReturn=new ArrayList<>();
		long on=n;
		for (int i=2; i*(long)i<=on; i++) {
			if (n%i!=0) continue;
			int count=0;
			while (n%i==0) {
				n/=i;
				count++;
			}
			toReturn.add(new Factor(i, count));
		}
		if (n!=1) {
			toReturn.add(new Factor(n, 1));
		}
		return toReturn;
	}
	
	static long gcd(long a, long b) {
		return b==0?a:gcd(b,a%b);
	}
	
	static class Factor {
		long factor;
		int times;
		public Factor(long factor, int times) {
			this.factor=factor;
			this.times=times;
		}
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
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}