

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {

	public static void solve(FastScanner fs) {	
		int n=fs.nextInt();
		Seg[] segs=new Seg[n*(n+1)/2];
		int index=0;
		for (int i=0; i<=n; i++) {
			for (int j=i+1; j<=n; j++) {
//				System.out.println(i+" "+j);
				segs[index++]=new Seg(i, j);
			}
		}
		Arrays.sort(segs);
//		System.out.println(Arrays.toString(segs));
		
		int layersUsed=1;
		int lastPossibleStart=0;
		boolean[] used=new boolean[segs.length];
		outer:while (containsFalse(used)) {
			for (int i=0; i<segs.length; i++) {
				if (!used[i]&&segs[i].start>=lastPossibleStart) {
//					System.out.println(segs[i]);
					lastPossibleStart=segs[i].end;
					used[i]=true;
					continue outer;
				}
			}
			layersUsed++;
			lastPossibleStart=0;
		}
		System.out.println(layersUsed);
	}
	
	private static boolean containsFalse(boolean[] a) {
		for (boolean b:a)
			if (!b)
				return true;
		return false;
	}

	private static class Seg implements Comparable<Seg> {
		private int start, end;
		public Seg(int start, int end) {
			this.start=start;
			this.end=end;
		}
		
		int length() {
			return end-start+1;
		}
		
		private boolean intersects(Seg o) {
			if (start>=o.end||end<=o.start)
				return false;
			return true;
		}

		public int compareTo(Seg o) {
			if (start!=o.start)
				return start-o.start;
			return o.length()-length();
		}
		
		public String toString() {
			return "("+start+", "+end+")";
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
	}
}