import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class B {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int nRed=fs.nextInt(), nGreen=fs.nextInt(), nBlue=fs.nextInt();
			int[] reds=new int[nRed];
			TreeSet<Integer> greens=new TreeSet<>(), blues=new TreeSet<>();
			for (int i=0; i<nRed; i++) reds[i]=fs.nextInt();
			for (int i=0; i<nGreen; i++) greens.add(fs.nextInt());
			for (int i=0; i<nBlue; i++) blues.add(fs.nextInt());
			long ans=Long.MAX_VALUE;
			for (int i:reds)
				ans=Math.min(ans, solveRedPicked(i, greens, blues));
			System.out.println(ans);
		}
	}
	
	static long solveRedPicked(int red, TreeSet<Integer> greens, TreeSet<Integer> blues) {
		long ans=Long.MAX_VALUE;
		Integer greenAbove=greens.ceiling(red);
		if (greenAbove!=null) ans=Math.min(ans, solve2Picked(red, greenAbove, blues));
		Integer greenBelow=greens.floor(red);
		if (greenBelow!=null) ans=Math.min(ans, solve2Picked(red, greenBelow, blues));
		
		Integer blueAbove=blues.ceiling(red);
		if (blueAbove!=null) ans=Math.min(ans, solve2Picked(red, blueAbove, greens));
		Integer blueBelow=blues.floor(red);
		if (blueBelow!=null) ans=Math.min(ans, solve2Picked(red, blueBelow, greens));
		return ans;
	}
	
	static long solve2Picked(int red, int green, TreeSet<Integer> blues) {
		int mid=(red+green)/2;
		Integer aboveI=blues.ceiling(mid);
		Integer belowI=blues.floor(mid);
		long ans=Long.MAX_VALUE;
		if (aboveI!=null) {
			long blue=(int)aboveI;
			ans=Math.min(ans, (blue-red)*(long)(blue-red)+(blue-green)*(long)(blue-green)+(green-red)*(long)(green-red));
		}
		if (belowI!=null) {
			long blue=(int)belowI;
			ans=Math.min(ans, (blue-red)*(long)(blue-red)+(blue-green)*(long)(blue-green)+(green-red)*(long)(green-red));
		}
		return ans;
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}