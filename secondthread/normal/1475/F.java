import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[][] a=new char[n][n], b=new char[n][n];
			for (int y=0; y<n; y++)
				a[y]=fs.next().toCharArray();
			for (int y=0; y<n; y++)
				b[y]=fs.next().toCharArray();
			if (a[0][0]!=b[0][0]) flipRow(a, 0);
			for (int i=1; i<n; i++) if (a[0][i]!=b[0][i]) flipCol(a, i);
			for (int i=1; i<n; i++) if (a[i][0]!=b[i][0]) flipRow(a, i);
			for (int i=0; i<n; i++)
				for (int j=0; j<n; j++)
					if (a[i][j]!=b[i][j]) {
						System.out.println("NO");
						continue outer;
					}
			System.out.println("YES");
		}
	}
	
	static void flipRow(char[][] a, int r) {
		for (int i=0; i<a.length; i++)
			a[r][i]=(a[r][i]=='0'?'1':'0');
	}
	
	static void flipCol(char[][] a, int c) {
		for (int i=0; i<a.length; i++)
			a[i][c]=(a[i][c]=='0'?'1':'0');
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