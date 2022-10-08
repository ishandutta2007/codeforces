import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {
/*
0000 0000
   0 1111
   
   Any zeros
   two strings
 */
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			char[] a=fs.next().toCharArray();
			int zindex=-1;
			for (int i=0; i<n; i++) if (a[i]=='0') zindex=i;
			if (zindex==-1) {
				print(1, n-1, 0, n-2);
			}
			else if (zindex<n/2) {
				//0 1
				print(zindex, n-1, zindex+1, n-1);
			}
			else {
				print(0, zindex, 0, zindex-1);
			}
		}
	}

	static void print(int a, int b, int c, int d) {
		a++;
		b++;
		c++;
		d++;
		System.out.println(a+" "+b+" "+c+" "+d);
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