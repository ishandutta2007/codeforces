import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*
 */
public class B {

	public static void main(String[] args) {
		FastScanner fs = new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=fs.nextInt();
			int minDiff=0;
			int minAdj=Integer.MAX_VALUE, maxAdj=Integer.MIN_VALUE;
			for (int i=1; i<n; i++) if (a[i]!=-1 && a[i-1]==-1) {
				minAdj=Math.min(minAdj, a[i]);
				maxAdj=Math.max(maxAdj, a[i]);
			}
			for (int i=0; i+1<n; i++) if (a[i]!=-1 && a[i+1]==-1) {
				minAdj=Math.min(minAdj, a[i]);
				maxAdj=Math.max(maxAdj, a[i]);
			}
			if (minAdj==Integer.MAX_VALUE) {
				System.out.println("0 0");
				continue;
			}
			int toPick=(maxAdj+minAdj)/2;
			for (int i=0; i<n; i++) if (a[i]==-1) a[i]=toPick;
			for (int i=0; i+1<n; i++) minDiff=Math.max(minDiff, Math.abs(a[i+1]-a[i]));
			System.out.println(minDiff+" "+toPick);
		}
	}

	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			while (!st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

}