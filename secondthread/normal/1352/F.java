import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int a=fs.nextInt(), b=fs.nextInt(), c=fs.nextInt();
			if (b==0) {
				if (a!=0 && c!=0) throw null;
				if (a!=0)
					for (int i=0; i<a+1; i++) System.out.print(0);
				if (c!=0)
					for (int i=0; i<c+1; i++) System.out.print(1);
				System.out.println();
			}
			else if (b%2==1) {
				for (int i=0; i<a+1; i++) System.out.print(0);
				for (int i=0; i<b; i++) {
					if (i%2==0) System.out.print(1);
					else System.out.print(0);
				}
				for (int i=0; i<c; i++) System.out.print(1);
				System.out.println();
			}
			else {
				System.out.print(1);
				b--;
				for (int i=0; i<a+1; i++) System.out.print(0);
				for (int i=0; i<b; i++) {
					if (i%2==0) System.out.print(1);
					else System.out.print(0);
				}
				for (int i=0; i<c; i++) System.out.print(1);
				System.out.println();
			}
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while(!st.hasMoreElements())
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
		long nextLong() {
			return Long.parseLong(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}
	
	public void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

}