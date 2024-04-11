import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		int[] ans=new int[n];
		Arrays.fill(ans, 1_000_000);
		ArrayList<Integer> maxIndexes=new ArrayList<>();
		int prev=0;
		for (int i=0; i<n; i++) if (a[i]>prev) {
			prev=a[i];
			maxIndexes.add(i);
		}
		
		TreeSet<Integer> ts=new TreeSet<>();
		for (int i=0; i<n; i++) ts.add(i);
		
		prev=0;
		for (int index:maxIndexes) {
			while (prev<a[index]) {
				int placeAt=ts.floor(index);
				ans[placeAt]=prev++;
				ts.remove(placeAt);
			}
		}
		
		PrintWriter out=new PrintWriter(System.out);
		for (int i=0; i<n; i++) out.print(ans[i]+" ");
		out.println();
		out.close();
	}
	
	static class Pair {
		int value, index;
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