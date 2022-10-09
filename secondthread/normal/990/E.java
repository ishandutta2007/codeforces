

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class E {

	public static void solve(FastScanner fs) {	
		int length=fs.nextInt();
		int numBlocked=fs.nextInt();
		int maxLamp=fs.nextInt();
		boolean[] road=new boolean[length];
		Arrays.fill(road, true);
		for (int i=0; i<numBlocked; i++) road[fs.nextInt()]=false;
		
		long[] lampCosts=fs.readLongArray(maxLamp);
		int[] lastValidSpot=new int[length];
		if (!road[0]) {
			System.out.println(-1);
			return;
		}
		
		for (int i=1; i<length; i++) {
			if (road[i]) lastValidSpot[i]=i;
			else lastValidSpot[i]=lastValidSpot[i-1];
		}
		long bestCost=Long.MAX_VALUE;
		outer: for (int dist=0; dist<maxLamp; dist++) {
			int count=1, pos=0;
			while (pos+dist+1<length) {
				if (lastValidSpot[pos+dist+1]<=pos)
					continue outer;
				else {
					count++;
					pos=lastValidSpot[pos+dist+1];
				}
			}
			bestCost=Math.min(bestCost, count*lampCosts[dist]);
		}
		if (bestCost==Long.MAX_VALUE) {
			System.out.println(-1);
		}
		else {
			System.out.println(bestCost);
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