import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[] line=fs.next().toCharArray();
			char[][] perms=new char[n][n];
			perms[0]=line;
			for (int len=2; len<=n; len++) {
				int flipTimes=(n-len+1);
				if (flipTimes%2==0) {
					for (int i=0; i<len-1; i++) {
						perms[len-1][n-1-i]=line[len-2-i];
					}
				}
				else {
					for (int i=0; i<len-1; i++) {
						perms[len-1][n-1-i]=line[i];
					}
				}
				for (int i=len-1; i<n; i++) {
					perms[len-1][i-len+1]=line[i];
				}
			}
			int min=0;
			for (int i=1; i<n; i++) {
				min=mindex(perms, min, i);
			}
			for (int start=0; start<n; start++) {
				for (char c:perms[start]) {
//					System.out.print(c);
				}
//				System.out.println();
			}
			for (char c:perms[min]) System.out.print(c);
			System.out.println();
			System.out.println(Math.max(min+1, 1));
		}
	}
	
	static int mindex(char[][] perms, int a, int b) {
		for (int i=0; i<perms[0].length; i++) {
			if (perms[a][i]!=perms[b][i]) {
				if (perms[a][i]<perms[b][i]) return a;
				else return b;
			}
		}
		return a;
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