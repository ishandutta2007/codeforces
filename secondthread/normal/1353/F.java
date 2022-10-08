import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int h=fs.nextInt(), w=fs.nextInt();
			long[][] board=new long[w][h];
			for (int y=0; y<h; y++) for (int x=0; x<w; x++) board[x][y]=fs.nextLong();
			TreeSet<Long> setOfMins=new TreeSet<>();
			for (int x=0; x<w; x++)
				for (int y=0; y<h; y++) {
					board[x][y]-=x+y;
					setOfMins.add(board[x][y]);
				}
			long[][] minSum=new long[w][h];
			long ans=Long.MAX_VALUE;
			long oo=(long)1e18;
			long SENT=(long)-1e18;
			for (long cutoff:setOfMins) {
				for (int x=0; x<w; x++) {
					for (int y=0; y<h; y++) {
						if (board[x][y]<cutoff) {
							minSum[x][y]=SENT;
							continue;
						}
						minSum[x][y]=oo;
						if (x>0 && minSum[x-1][y]!=SENT) minSum[x][y]=Math.min(minSum[x][y], minSum[x-1][y]+board[x][y]);
						if (y>0 && minSum[x][y-1]!=SENT) minSum[x][y]=Math.min(minSum[x][y], minSum[x][y-1]+board[x][y]);
						if (minSum[x][y]==oo) minSum[x][y]=SENT;
						if (x==0 && y==0) minSum[x][y]=board[x][y];
					}
				}
				if (minSum[w-1][h-1]==SENT) continue;
				long val=minSum[w-1][h-1]-cutoff*(w+h-1);
				ans=Math.min(ans, val);
			}
			System.out.println(ans);
		}
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