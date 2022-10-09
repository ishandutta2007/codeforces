import java.util.*;
import java.io.*;

public class A {
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		fs.next();
		String alpha="abcdefghijklmnopqrstuvwxyz";
		String alphaUpper=alpha.toUpperCase();
		boolean[] hits=new boolean[26];
		String line=fs.next();
		for (char c:line.toCharArray())
			if (alpha.contains(c+""))
				hits[alpha.indexOf(c+"")]=true;
			else
				hits[alphaUpper.indexOf(c+"")]=true;
		for (boolean b:hits) {
			if (!b) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
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