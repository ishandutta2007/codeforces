import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), nTowers=fs.nextInt();
			fs.next();
			
			int[] a=fs.readArray(n);
			PriorityQueue<Pair> pq=new PriorityQueue<>();
			for (int i=1; i<=nTowers; i++) pq.add(new Pair(i));
			out.println("YES");
			for (int i:a) {
				Pair addTo=pq.remove();
				addTo.sum+=i;
				pq.add(addTo);
				out.print(addTo.id+" ");
			}
			out.println();
		}
		out.close();
	}
	
	static class Pair implements Comparable<Pair> {
		int id;
		long sum=0;
		public Pair(int id) {
			this.id=id;
		}
		public int compareTo(Pair o) {
			return Long.compare(sum, o.sum);
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