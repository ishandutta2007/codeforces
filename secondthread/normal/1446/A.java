import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			long W=fs.nextLong();
			Item toTake=null;
			ArrayList<Item> small=new ArrayList<>();
			long smallTotal=0;
			for (int i=0; i<n; i++) {
				int weight=fs.nextInt();
				if (weight>W) continue;
				if (weight>=(W+1)/2) {
					toTake=new Item(i+1, weight);
				}
				else {
					if (smallTotal+weight<=W) {
						small.add(new Item(i+1, weight));
						smallTotal+=weight;
					}
				}
			}
			if (toTake!=null) {
				out.println(1);
				out.println(toTake.id);
			}
			else if (smallTotal>=(W+1)/2) {
				out.println(small.size());
				for (Item i:small) {
					out.print(i.id+" ");
				}
				out.println();
				
			}
			else {
				out.println(-1);
			}
		}
		out.close();
	}
	
	static class Item {
		int id, weight;
		public Item(int id, int weight) {
			this.id=id;
			this.weight=weight;
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