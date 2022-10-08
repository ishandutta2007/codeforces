import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Pair[] pairs=new Pair[n];
		for (int i=0; i<n; i++) pairs[i]=new Pair(fs.nextInt(), fs.nextInt());
		Arrays.sort(pairs);
		int last=pairs[0].b;
		for (Pair p:pairs) {
			if (last>p.b) {
				System.out.println("Happy Alex");
				return;
			}
			last=p.b;
		}
		System.out.println("Poor Alex");
	}
	
	static class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a=a;
			this.b=b;
		}
		
		public int compareTo(Pair o) {
			if (a!=o.a) return Integer.compare(a, o.a);
			return Integer.compare(b, o.b);
		}
	}
	
	public void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreElements())
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
	}

}