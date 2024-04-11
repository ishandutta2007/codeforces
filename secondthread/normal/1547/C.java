import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int k=fs.nextInt(), n=fs.nextInt(), m=fs.nextInt();
			int[] a=fs.readArray(n), b=fs.readArray(m);
			int p=0, q=0;
			ArrayList<Integer> res=new ArrayList<>();
			for (int i=0; i<n+m; i++) {
				if (p<n && a[p] <= k) {
					res.add(a[p]);
					if (a[p]==0) k++;
					p++;
				}
				else if (q<m && b[q] <= k) {
					res.add(b[q]);
					if (b[q]==0) k++;
					q++;
				}
				else {
					System.out.println(-1);
					continue outer;
				}
			}
			for (int i:res) System.out.print(i+" ");
			System.out.println();
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