import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			PriorityQueue<Person> pq=new PriorityQueue<>();
			for (int i=0; i<n; i++) 
				if (a[i]>0) pq.add(new Person(i+1, a[i]));
			ArrayList<Integer> ans=new ArrayList<>();
			while (pq.size()>1) {
				Person aa=pq.remove(), b=pq.remove();
				aa.x--;
				b.x--;
				ans.add(aa.id);
				ans.add(b.id);
				if (aa.x>0) pq.add(aa);
				if (b.x>0) pq.add(b);
			}
			out.println(ans.size()/2);
			for (int i=0; i<ans.size(); i+=2) {
				out.println(ans.get(i)+" "+ans.get(i+1));
			}
		}
		out.close();
	}
	
	static class Person implements Comparable<Person> {
		int id, x;
		public Person(int id, int x) {
			this.id=id;
			this.x=x;
		}
		public int compareTo(Person o) {
			return -Integer.compare(x, o.x);
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