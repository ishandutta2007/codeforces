import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class OldC {

	public static void solve(FastScanner fs) {	
		BigInteger numCandies=new BigInteger(""+fs.nextLong());
		BigInteger numPeople=new BigInteger(""+fs.nextLong());
		BigInteger maxCandiesPerSwipe=new BigInteger(""+fs.nextLong());
		BigInteger maxCandieTakes=new BigInteger(""+fs.nextInt());
		BigInteger best=maxCandiesPerSwipe;
		
		for (BigInteger candyTakes=new BigInteger("2"); candyTakes.compareTo(maxCandieTakes)<=0; 
				candyTakes=candyTakes.add(BigInteger.ONE)) {
			BigInteger first=maxCandiesPerSwipe;
			BigInteger second=numCandies.divide(candyTakes.multiply(numPeople).subtract(numPeople).add(BigInteger.ONE));
			BigInteger min=first.compareTo(second)<0?first:second;
			if (best.compareTo(candyTakes.multiply(min))<0)
				best=candyTakes.multiply(min);
		}
		System.out.println(best);
		
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