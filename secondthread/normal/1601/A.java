import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			boolean allZ=true;
			for (int i:a) if (i!=0) allZ=false;
			if (allZ) {
//				out.println(n);
				for (int i=1; i<=n; i++) out.print(i+" ");
				out.println();
				continue;
			}
			boolean[] works=new boolean[n+1];
			Arrays.fill(works, true);
			for (int bit=0; bit<30; bit++) {
				int count=0;
				for (int i:a) {
					if ((i&(1<<bit))!=0) count++;
				}
				if (count!=0) {
					for (int i=1; i<=n; i++) works[i]&=count%i==0;
				}
			}
			for (int i=1; i<=n; i++) if (works[i]) out.print(i+" ");
			out.println();
		}
		out.close();
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