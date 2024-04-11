import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
3
1 2 3
 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			int i1=0, i2=n-1;
			while (i1<i2 && a[i1]==a[i2]) {
				i1++;
				i2--;
			}
			if (i1>=i2) {
				System.out.println("YES");
			}
			else {
				if (check(a, i1, i2, a[i1]) || check(a, i1, i2, a[i2])) {
					System.out.println("YES");
				}
				else {
					System.out.println("NO");
				}
			}
		}
	}
	
	static boolean check(int[] a, int i1, int i2, int toRemove) {
		while (true) {
			while (i1<a.length && a[i1]==toRemove) i1++;
			while (i2>=0 && a[i2]==toRemove) i2--;
			if (i2<=i1) {
				break;
			}
			if (a[i1]!=a[i2]) return false;
			i1++;
			i2--;
		}
//		System.out.println("Returning true with toRemove "+toRemove);
		return true;
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