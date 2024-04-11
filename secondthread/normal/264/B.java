import java.util.*;
import java.io.*;

public class A {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		int max=1;
		HashMap<Integer, Integer> best=new HashMap<>();
		for (int j=0; j<n; j++) {
			ArrayList<Integer> primeFacts=primeFactors(a[j]);
			int nextBest=0;
			for (int i:primeFacts)
				nextBest=Math.max(nextBest, best.getOrDefault(i, 0));
			nextBest++;
			for (int i:primeFacts)
				best.put(i, nextBest);
			max=Math.max(max, nextBest);
		}
		System.out.println(max);
	}
	
	private static ArrayList<Integer> primeFactors(int n) {
		ArrayList<Integer> toReturn=new ArrayList<>();
		int o=n;
		for (int i=2; i*i<=o; i++) {
			if (n%i==0) {
				toReturn.add(i);
				while (n%i==0)
					n/=i;
			}
		}
		if (n!=1)
			toReturn.add(n);
		return toReturn;
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