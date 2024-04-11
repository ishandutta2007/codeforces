import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class B {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			long n=fs.nextInt(), mod=fs.nextInt();
			long ans=1;
			long exp=4;
			while (true) {
				long prevExp=exp/2;
				long thingsInRange=Math.min(exp-1, n)-(prevExp-1);
				ans=(ans+(ans*thingsInRange))%mod;
				ans=(ans+thingsInRange)%mod;
				
				if (exp>n) break;
				exp*=2;
			}
			System.out.println(ans);
		}
		
	}
	
	static boolean works(int[] a) {
		int n=a.length;
		for (int i=1; i<n; i++) 
			if (a[i]<=a[i-1]) return false;
		int xor=a[0];
		for (int i=1; i<n; i++) {
			int nexor=xor^(a[i]);
			if (nexor>=xor) return false;
			xor=nexor;
		}
		return true;
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