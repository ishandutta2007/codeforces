import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			boolean[][] board=new boolean[n][n];
			for (int y=0; y<n; y++) {
				char[] line=fs.next().toCharArray();
				for (int x=0; x<n; x++) board[x][y]=line[x]=='1';
			}
			for (int x=0; x<n; x++)
				for (int y=0; y<n; y++) {
					if (!board[x][y]) continue;
					if (x==n-1 || y==n-1) continue;
					if (board[x+1][y] || board[x][y+1]) continue;
					System.out.println("NO");
					continue outer;
				}
			System.out.println("YES");
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