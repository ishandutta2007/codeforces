import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt();
			int[] a=fs.readArray(n);
			boolean haveZero=false;
			for (int i=0; i<n; i++) {
				if (a[i]>k) a[i]=-1;
				else if (a[i]==k) a[i]=0;
				else a[i]=1;
				haveZero|=a[i]==0;
			}
			if (!haveZero) {
				System.out.println("no");
				continue;
			}
			for (int i=0; i<n; i++)
				if (a[i]==-1) a[i]=0;
			if (n==1) {
				System.out.println("yes");
				continue;
			}
			for (int i=0; i+1<n; i++) {
				if (a[i]==0 && a[i+1]==0) {
					System.out.println("yes");
					continue outer;
				}
				if (i+2<n && a[i]==0 && a[i+2]==0) {
					System.out.println("yes");
					continue outer;
				}
			}
			System.out.println("no");
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