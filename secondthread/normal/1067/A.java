import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class A {

	static int[][] dp1;
	static int[][] dp2;
	static int[] a;
	static int n;
	static int mod=998244353;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=1;//fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			n=fs.nextInt();
			a=fs.readArray(n);
			dp1=new int[201][n];
			dp2=new int[201][n];
			for	 (int i=0; i<dp1.length; i++)
				Arrays.fill(dp1[i], -1);
			for (int i=0; i<dp2.length; i++)
				Arrays.fill(dp2[i], -1);
			for (int i=n-1; i>=0; i--) {
				for (int j=1; j<=200; j++) {
					go1(j, i);
					go2(j, i);
				}
			}
			int ans=go1(1, 0);
			System.out.println(ans);
		}
	}
	
	
	static int go1(int valueOrHigher, int pos) {
		if (valueOrHigher>200)
			return 0;
		if (pos==n)
			return 0;
		if (dp1[valueOrHigher][pos]!=-1)
			return dp1[valueOrHigher][pos];
		long total=0;
		if (a[pos]==valueOrHigher||a[pos]==-1) {
			total+=ggo1(valueOrHigher+1, pos+1);
			total+=ggo2(valueOrHigher, pos+1)-ggo2(valueOrHigher-1, pos+1);
		}
		total+=go1(valueOrHigher+1, pos);
		total=(total%mod+mod)%mod;
		return dp1[valueOrHigher][pos]=(int) total;
	}
	
	static int go2(int valueOrLower, int pos) {
		if (valueOrLower<1)
			return 0;
		if (pos==n)
			return 1;
		if (dp2[valueOrLower][pos]!=-1)
			return dp2[valueOrLower][pos];
		long total=0;
		if (a[pos]==valueOrLower||a[pos]==-1) {
			total+=ggo1(valueOrLower+1, pos+1);
			total+=ggo2(valueOrLower, pos+1);
		}
		total+=go2(valueOrLower-1, pos);
		total=(total%mod+mod)%mod;
		return dp2[valueOrLower][pos]=(int) total;
	}
	
	static int ggo1(int valueOrHigher, int pos) {
		if (valueOrHigher>200)
			return 0;
		if (pos==n)
			return 0;
		return dp1[valueOrHigher][pos];
	}
	
	static int ggo2(int valueOrLower, int pos) {
		if (valueOrLower<1)
			return 0;
		if (pos==n)
			return 1;
		return dp2[valueOrLower][pos];
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