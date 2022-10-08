import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class DNotCancer {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int h=fs.nextInt(), w=fs.nextInt();
		char[][] grid=new char[w][h];
		for (int y=0; y<h; y++) {
			char[] line=fs.next().toCharArray();
			for (int x=0; x<w; x++)
				grid[x][y]=line[x];
		}
		int[][] dp=new int[w][h];
		long ans=0;
		for (int y=0; y<h; y++) {
			for (int x=0; x<w; x++) {
				dp[x][y]=1;
				if (y<2 || x==0 || x==w-1) {
					ans++;
					continue;
				}
				if (grid[x][y]!=grid[x][y-1] || 
						grid[x][y]!=grid[x+1][y-1] || 
						grid[x][y]!=grid[x-1][y-1]||
						grid[x][y]!=grid[x][y-2]) {
					ans++;
					continue;
				}
				dp[x][y]=dp[x][y-2]+1;
				dp[x][y]=Math.min(dp[x][y], dp[x-1][y-1]+1);
				dp[x][y]=Math.min(dp[x][y], dp[x+1][y-1]+1);
				ans+=dp[x][y];
			}
		}
		System.out.println(ans);
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
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}

}