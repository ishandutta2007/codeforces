import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int sx=fs.nextInt(), sy=fs.nextInt();
			int endx=fs.nextInt(), endy=fs.nextInt();
			int mx=fs.nextInt(), my=fs.nextInt();
			if (sx!=endx && sy!=endy) {
				System.out.println(Math.abs(sx-endx)+Math.abs(endy-sy));
			}
			else {
				if (sx==endx && sx==mx && Math.abs(my-sy) + Math.abs(endy-my) == Math.abs(endy-sy)) {
					System.out.println(Math.abs(sx-endx)+Math.abs(endy-sy)+2);
				}
				else if (sy==endy && sy==my && Math.abs(mx-sx) + Math.abs(endx-mx) == Math.abs(endx-sx)) {
					System.out.println(Math.abs(sx-endx)+Math.abs(endy-sy)+2);
				}
				else {
					System.out.println(Math.abs(sx-endx)+Math.abs(endy-sy));
				}
			}
		}
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