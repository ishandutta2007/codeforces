

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.StringTokenizer;

public class E {

	public static void solve(FastScanner fs) {	
		int n=fs.nextInt();
		int[] goal=new int[n];
		for (int i=0; i<n; i++) goal[i]=fs.nextInt();
		int nQueries=fs.nextInt();
		HashMap<Long, Integer> existing=new HashMap<>();
		int[] free=new int[n];
		long turns=0;
		for (int i:goal) turns+=i;
		
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			int ofResource=fs.nextInt()-1;
			int amountRequired=fs.nextInt();
			int givesResource=fs.nextInt()-1;

			long compressed=(((long)(amountRequired))<<32l) + ofResource;
			if (existing.containsKey(compressed)) {
				int toRemove=existing.get(compressed);
				if (free[toRemove]<=goal[toRemove]) {
					turns++;
				}
				free[toRemove]--;
			}
			if (givesResource!=-1) {
				if (free[givesResource]<goal[givesResource]) {
					turns--;
				}
				free[givesResource]++;
				existing.put(compressed, givesResource);
			}
			else existing.remove(compressed);
			out.println(turns);
		}
		out.close();
		
	}

	
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}