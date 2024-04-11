import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/*
3
3
1 0 1
 */
public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			//if the first goes from last, then last, 1, 2, ...
			//if they all go in from last, then 1, 2, ... last
			//if then go in then out, then 1, 2, ... last, 3, 4
			
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			if (a[0]==1) {
				//last -> first
				System.out.print(n+1+" ");
				for (int i=1; i<=n; i++) System.out.print(i+" ");
			}
			else {
				int firstOne=n;
				for (int i=n-1; i>=0; i--) if (a[i]==1) firstOne=i;
				for (int i=0; i<n; i++) {
					System.out.print(i+1+" ");
					if (firstOne==i+1) System.out.print(n+1+" ");
				}
			}
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