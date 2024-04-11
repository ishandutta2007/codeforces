import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/* 
 * Subscribe to galen_colin!
 * https://tinyurl.com/galencolin
*/

public class Temp {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int l=0, r=n-1;
			int[] a=fs.readArray(n);
			boolean left=true;
			while (l<=r) {
				if (left) {
					System.out.print(a[l++]+" ");
				}
				else {
					System.out.print(a[r--]+" ");
				}
				left^=true;
			}
			System.out.println();
		}
	}

	static void ruffle_sort(int[] a) {
		//shandom_ruffle
		Random r=new Random();
		int n=a.length;
		for (int i=0; i<n; i++) {
			int oi=r.nextInt(i);
			int temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
		}
		
		//sort
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