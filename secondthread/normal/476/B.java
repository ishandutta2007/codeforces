import java.util.*;
import java.io.*;

public class A {
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		String l1=fs.next();
		int count1=0, count2=0;
		for (char c:l1.toCharArray()) if (c=='+') count1++;
		int qs=0;
		String l2=fs.next();
		for (char c:l2.toCharArray())
			if (c=='+') count2++;
			else if (c=='?') qs++;
		int correct=0, incorrect=0;
		for (int i=0; i<1<<qs; i++) if (Integer.bitCount(i)+count2==count1) correct++; else incorrect++;
		
		System.out.printf("%.10f\n", (correct)/(double)(correct+incorrect));
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