import java.util.*;
import java.io.*;

public class A {
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), l=fs.nextInt();
		int[] a=fs.readArray(n);
		Arrays.sort(a);
		double best=Math.max(a[0], l-a[n-1]);
		for (int i=0; i<n-1; i++) best=Math.max(best, (a[i+1]-a[i])/2.0);
		System.out.printf("%.10f\n", best);
	}
	
	private static boolean possible(int n, int rocketWeight, int[] planetLiftoffWeightPerFuel, int[] planetLandWeightPerFuel, double fuel) {
		for (int i=0; i<n; i++) {
			double newCost=(rocketWeight+fuel)/planetLiftoffWeightPerFuel[i];
			if (newCost>fuel) return false;
			fuel-=newCost;
			newCost=(rocketWeight+fuel)/planetLandWeightPerFuel[(i+1)%n];
			if (newCost>fuel) return false;
			fuel-=newCost;
		}
		return true;
	}
	
	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
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