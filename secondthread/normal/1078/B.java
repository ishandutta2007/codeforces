import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
	
	static short[][][] dp;
	static int n;
	static int[] a;
	static int[] nextDifferent;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		n=fs.nextInt();
		a=fs.readArray(n);
		Arrays.sort(a);
		nextDifferent=new int[n];
		nextDifferent[n-1]=n;
		for (int i=n-2; i>=0; i--) {
			if (a[i]!=a[i+1])
				nextDifferent[i]=i+1;
			else
				nextDifferent[i]=nextDifferent[i+1];
		}
		dp=new short[n][n*101][n+1];
		for (int i=0; i<n; i++)
			for (int j=0; j<dp[i].length; j++)
				Arrays.fill(dp[i][j], (short)-1); 
		
		int[] cs=new int[101];
		for (int i:a) cs[i]++;
		int numUnique=0;
		for (int i:cs)
			if (i!=0)
				numUnique++;
		if (numUnique==2) {
			System.out.println(n);
			return;
		}
		int best=0;
		for (int number=0; number<=100; number++) {
			for (int count=1; count<=cs[number]; count++) {
				int total=number*count;
				int ways=go(0, total, count);
//				System.out.println("ways to get "+total+": "+ways);
				if (ways==1) {
					best=Math.max(best, count);
				}
			}
		}
		System.out.println(best);
	}
	
	
	static short go(int position, int totalLeft, int numberToPick) {
		if (totalLeft<0||totalLeft>n*100||numberToPick<0)
			return 0;
		if (position==n) {
			if (totalLeft==0&&numberToPick==0)
				return 1;
			return 0;
		}
		if (dp[position][totalLeft][numberToPick]!=-1)
			return dp[position][totalLeft][numberToPick];
		int total=0;
		//don't take it
		total+=go(nextDifferent[position], totalLeft, numberToPick);
		
		//take it
		total+=go(position+1, totalLeft-a[position], numberToPick-1);
		total=Math.min(total, 2);
		return dp[position][totalLeft][numberToPick]=(short)total;
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