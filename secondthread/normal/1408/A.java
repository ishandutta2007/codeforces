import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n), b=fs.readArray(n), c=fs.readArray(n);
			int[] ans=new int[n];
			ans[0]=a[0];
			for (int i=1; i<n; i++) {
				int prev=ans[i-1];
				if (i!=n-1) {
					if (a[i]!=prev) ans[i]=a[i];
					else if (b[i]!=prev) ans[i]=b[i];
				}
				else {
					int next=ans[0];
					if (a[i]!=prev && a[i]!=next) ans[i]=a[i];
					else if (b[i]!=prev && b[i]!=next) ans[i]=b[i];
					else if (c[i]!=prev && c[i]!=next) ans[i]=c[i];
					else throw null;
				}
			}
			for (int i:ans) System.out.print(i+" ");
			System.out.println();
		}
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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