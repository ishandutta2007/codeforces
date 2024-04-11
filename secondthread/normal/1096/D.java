import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {

	static char[] letters;
	static int[] costs;
	static long[][] dp;
	static char[] hard="hard".toCharArray();
	static long oo=Long.MAX_VALUE/2;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		letters=fs.next().toCharArray();
		costs=fs.readArray(n);
		dp=new long[5][n+1];
		for (int i=0; i<dp.length; i++)
			Arrays.fill(dp[i], -1);
		long cost=go(0, 0);
		System.out.println(cost);
	}
	
	static long go(int hardUsed, int index) {
		if (dp[hardUsed][index]!=-1)
			return dp[hardUsed][index];
		if (hardUsed==4) {
			return dp[hardUsed][index]=oo;
		}
		if (index==letters.length) {
			return dp[hardUsed][index]=0;
		}
		if (letters[index]==hard[hardUsed]) {
			long min=go(hardUsed+1, index+1);
			min=Math.min(min, go(hardUsed, index+1)+costs[index]);
			return dp[hardUsed][index]=min;
		}
		else {
			return dp[hardUsed][index]=go(hardUsed, index+1);
		}
	}
	
	static class Kid {
		int id;
		int next1, next2;
		public Kid(int next1, int next2, int id) {
			this.next1=next1;
			this.next2=next2;
			this.id=id;
		}
		
		public boolean canComeAfter(Kid o) {
			return o.next1==next1||o.next2==next2||o.next1==next2||o.next2==next1;
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