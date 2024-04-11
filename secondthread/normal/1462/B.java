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

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		test: for (int tt=0; tt<T; tt++) {
			char[] target="2020".toCharArray();
			int n=fs.nextInt();
			char[] line=fs.next().toCharArray();
			outer: for (int l=0; l<=4;l++) {
				for (int toCheck=0; toCheck<l; toCheck++) {
					if (target[toCheck]!=line[toCheck]) continue outer;
				}
				for (int toCheck=0; toCheck<4-l; toCheck++) {
					if (line[n-1-toCheck]!=target[4-1-toCheck]) continue outer;
				}
				System.out.println("YES");
				continue test;
			}
			System.out.println("NO");
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