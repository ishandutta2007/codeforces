

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	//dp[firstInLoop][index][indentLevel]
	private static int[][][] dp;
	private static boolean[] wasLoop;
	private static int MOD=1000000007;
	private static int n;
	
	public static void solve(FastScanner fs) {	
		n=fs.nextInt();
		dp=new int[2][n][n];
		for (int i=0; i<dp.length; i++)
			for (int j=0; j<dp[i].length; j++)
				Arrays.fill(dp[i][j], -1);
		wasLoop=new boolean[n];
		for (int i=0; i<n; i++)
			wasLoop[i]=fs.next().equals("f");
		
		int ans=go(0, 0, 0);
		System.out.println(ans);
	}
	
	private static int go(int firstInLoop, int index, int indentLevel) {
		if (index>=n)//base case
			return 1;
		if (dp[firstInLoop][index][indentLevel]!=-1)
			return dp[firstInLoop][index][indentLevel];
		
		//if I am forced, just do it
		if (firstInLoop==1)
			return dp[firstInLoop][index][indentLevel]=go(wasLoop[index]?1:0, index+1, indentLevel+(wasLoop[index]?1:0));
		
		//if I am on the end level, I don't have a choice
		if (indentLevel==0) {
			return dp[firstInLoop][index][indentLevel]=go(wasLoop[index]?1:0, index+1, wasLoop[index]?1:0);
		}
		else {
			//otherwise, add all the possibilities
			int total=0;
			total+=go(firstInLoop, index, indentLevel-1);
			total+=go(wasLoop[index]?1:0, index+1, indentLevel+(wasLoop[index]?1:0));
			total%=MOD;
			return dp[firstInLoop][index][indentLevel]=total;
		}
	}

	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
}