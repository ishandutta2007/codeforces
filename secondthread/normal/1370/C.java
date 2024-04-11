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
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			String win="Ashishgup", lose="FastestFinger";
			if (n==1) {
				System.out.println(lose);
			}
			else if (n==2) {
				System.out.println(win);
			}
			else if (n%2==1) {
				System.out.println(win);
			}
			else {
				//power of two -> lose
				if (Integer.bitCount(n)==1) {
					System.out.println(lose);
				}
				else {
					//prime*2 -> lose
					if (prime(n/2)) {
						System.out.println(lose);
					}
					else {
						System.out.println(win);
					}
				}
			}
		}
	}
	
	static boolean prime(int n) {
		for (int i=2; i*i<=n; i++) if (n%i==0) return false;
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