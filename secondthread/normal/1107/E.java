import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class E {
	
	static int n;
	static int[] board;
	static int[] bonusForLength;
	
	static long[][][][] dp;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		n=fs.nextInt();
		char[] line=fs.next().toCharArray();
		board=new int[n];
		for (int i=0; i<n; i++) board[i]=line[i]-'0';
		bonusForLength=new int[n+1];
		for (int i=1; i<=n; i++) bonusForLength[i]=fs.nextInt();
		
		dp=new long[2][n][n][n];
		for (int i=0; i<dp.length; i++)
			for (int j=0; j<dp[i].length; j++)
				for (int k=0; k<dp[i][j].length; k++)
					Arrays.fill(dp[i][j][k], -1);
		
		long ans=go(board[0], 0, n-1, 0);
		System.out.println(ans);
	}
	
	static long go(int curType, int from, int to, int nContained) {
		if (from>to) return bonusForLength[nContained];
		if (dp[curType][from][to][nContained]!=-1) return dp[curType][from][to][nContained];
		long best=0;
		if (nContained!=0) {
			best=Math.max(best, bonusForLength[nContained]+go(0, from, to, 0));
			best=Math.max(best, bonusForLength[nContained]+go(1, from, to, 0));
		}
		if (curType==board[from]) {
			best=Math.max(best, go(curType, from+1, to, nContained+1));
		}
		int maxLength=nContained==0?to-from:to-from+1;
		for (int length=1; length<maxLength; length++) {
			int nextStart=from+length;
			long nextMe=go(curType, nextStart, to, nContained);
			long other1=go(0, from, nextStart-1, 0);
			long other2=go(1, from, nextStart-1, 0);
			best=Math.max(best, nextMe+Math.max(other1, other2));
		}
		return dp[curType][from][to][nContained]=best;
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