import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class E {
	
	static int[][] dp;
	static int[] a;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		a=new int[n+1];
		for (int i=0; i<n; i++) a[i]=fs.nextInt();
		dp=new int[n][n+1];
		for (int i=0; i<dp.length; i++)
			Arrays.fill(dp[i], -1);
		int ans=go(0, n);
		System.out.println(ans);
	}
	
	static int go(int index, int depthInd) {
		if (index==a.length-1) return 0;
//		System.out.println(index+" "+depthInd);
		if (dp[index][depthInd]!=-1) return dp[index][depthInd];
		int ans;
		if (a[depthInd]<a[index]) {
			//height increases
			ans=1+go(index+1, depthInd);
			ans=Math.min(ans, a[index]-a[depthInd]+go(index+1, index));
		}
		else {
			ans=go(index+1, index);
		}
		
		return dp[index][depthInd]=ans;
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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