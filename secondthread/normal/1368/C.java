import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int nThings=1+7*(n+1);
		boolean[][] grid=new boolean[15][15];
		System.out.println(nThings);
		System.out.println("0 0");
		int x=0;
		for (int times=0; times<=n; times++) {
			System.out.println((x+1)+" "+x);
			System.out.println((x)+" "+(x+1));
			System.out.println((x+2)+" "+x);
			System.out.println((x)+" "+(x+2));
			System.out.println((x+2)+" "+(x+1));
			System.out.println((x+1)+" "+(x+2));
			System.out.println((x+2)+" "+(x+2));
			x+=2;
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