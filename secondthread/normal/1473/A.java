import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
/*

Problem Quality:


Feedback:



 */
public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), cap=fs.nextInt();
			int[] a=fs.readArray(n);
			ruffle_sort(a);
			int m2=Integer.MAX_VALUE/3, m1=Integer.MAX_VALUE/3;
			for (int i=0; i<n; i++) {
				int val=a[i];
				val=Math.min(val, m1+m2);
				if (val<m1) {
					m2=m1;
					m1=val;
				}
				else if (val<m2) {
					m2=val;
				}
				if (val>cap) {
					System.out.println("NO");
					continue outer;
				}
			}
			System.out.println("YES");
		}
	}

	static void ruffle_sort(int[] a) {
		//shandom_ruffle
		Random r=new Random();
		int n=a.length;
		for (int i=0; i<n; i++) {
			int oi=r.nextInt(n);
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