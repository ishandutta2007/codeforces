import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/* 
 * Subscribe to galen_colin!
 * https://tinyurl.com/galencolin
*/

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		test:for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt();
			int[] xs=new int[n], ys=new int[n];
			for (int i=0; i<n; i++) {
				xs[i]=fs.nextInt();
				ys[i]=fs.nextInt();
			}
			outer: for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					if (Math.abs(xs[i]-xs[j])+Math.abs(ys[i]-ys[j])>k) continue outer;
				}
				System.out.println(1);
				continue test;
			}
			System.out.println(-1);
		}
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
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