
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	static int mod=1_000_000_007;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int[][] counts=new int[10][200_001];
		for (int i=0; i<10; i++) counts[i]=sim(i, 2_000_01);
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), steps=fs.nextInt();
			long ans=0;
			for (char c:(n+"").toCharArray())
				ans+=counts[c-'0'][steps];
			out.println(ans%mod);
		}
		out.close();
	}
	static int[] sim(int start, int steps) {
		int[] counts=new int[10];
		counts[start]++;
		int[] ans=new int[steps];
		ans[0]=1;
		int sum=1;
		int[] newCounts=new int[10];
		for (int step=1; step<steps; step++) {
			Arrays.fill(newCounts, 0);
			for (int i=0; i<9; i++)
				newCounts[i+1]=counts[i];
			newCounts[0]=counts[9];
			newCounts[1]=add(newCounts[1], counts[9]);
			sum=add(sum, counts[9]);
			int[] temp=counts;
			counts=newCounts;
			newCounts=temp;
			ans[step]=sum;
		}
		return ans;
	}
	
	static int add(int a, int b) {
		if (a+b>=mod) return a+b-mod;
		return a+b;
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
		
		int[] readArray(int n) {
			int[] a=new int[n]; 
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		int nextInt () {
			return Integer.parseInt(next());
		}
	}

}