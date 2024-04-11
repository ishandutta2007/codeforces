import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class _112E {

	public static void main(String[] args) {
//		System.out.println(2&9);
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		int NBITS=22;
		int[] dp=new int[1<<NBITS];
		Arrays.fill(dp, -1);
		for (int i:a) dp[i]=i;
		for (int exp=0; exp<NBITS; exp++) {
			for (int i=0; i<1<<NBITS; i++) {
				if ((i&(1<<exp))!=0) {
					if (dp[i]==-1) {
						dp[i]=dp[i-(1<<exp)];
					}
					else {
						//we already have an answer
					}
				}
				else {
					//this bit is a zero, so keep it as a zero
				}
			}
		}
		PrintWriter out=new PrintWriter(System.out);
		for (int i=0; i<n; i++) {
			int full=(1<<NBITS)-1;
			int target=full^(a[i]);
			out.print(dp[target]+" ");
		}
		out.println();
		out.close();
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