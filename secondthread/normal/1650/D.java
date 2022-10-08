import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
/*
1
3
3 1 2
 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			int[] ans=new int[n];
			for (int i=0; i<n; i++) a[i]--;
			for (int toPutInPlace=n-1; toPutInPlace>=0; toPutInPlace--) {
				int indexOf=0;
				while (a[indexOf]!=toPutInPlace) indexOf++;
				ans[toPutInPlace] = (indexOf-toPutInPlace+(toPutInPlace+1))%(toPutInPlace+1);
				csl(a, toPutInPlace+1, ans[toPutInPlace]);
			}
			for (int i:ans) System.out.print(i+" ");
			System.out.println();
		}
	}
	
	static void csl(int[] a, int prefixSize, int by) {
		by=(by%prefixSize+prefixSize)+prefixSize;
		int[] newA=new int[prefixSize];
		for (int i=0; i<prefixSize; i++) {
			newA[i]=a[(i+by)%prefixSize];
		}
		for (int i=0; i<prefixSize; i++)
			a[i]=newA[i];
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