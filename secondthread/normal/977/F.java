

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Stack;
import java.util.StringTokenizer;

public class F {

	public static void solve(FastScanner fs) {	
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			HashMap<Integer, Integer> map=new HashMap<>();
			HashMap<Integer, Integer> lastUsed=new HashMap<>();
			int[] from=new int[n];
			Arrays.fill(from, -1);
			for (int i=0; i<a.length; i++) {
				if (map.containsKey(a[i]-1)) {
					from[i]=lastUsed.get(a[i]-1);
					lastUsed.put(a[i], i);
					map.put(a[i], map.get(a[i]-1)+1);
				}
				else {
					map.put(a[i], 1);
					lastUsed.put(a[i], i);
				}
			}
			int max=0;
			int maxEnd=0;
			for (int i:map.keySet()) {
				if (map.get(i)>max) {
					max=map.get(i);
					maxEnd=lastUsed.get(i);
				}
			}
			System.out.println(max);
			Stack<Integer> stk=new Stack<>();
			while (maxEnd!=-1) {
				stk.push(maxEnd);
				maxEnd=from[maxEnd];
			}
			
			while (!stk.isEmpty()) {
				System.out.print((stk.pop()+1)+" ");
			}
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