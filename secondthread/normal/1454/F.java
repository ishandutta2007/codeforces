import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			int[] prefixMaxes=new int[n], suffixMaxes=new int[n];
			prefixMaxes[0]=a[0];
			suffixMaxes[n-1]=a[n-1];
			for (int i=1; i<n; i++) prefixMaxes[i]=Math.max(prefixMaxes[i-1], a[i]);
			for (int i=n-2; i>=0; i--) suffixMaxes[i]=Math.max(suffixMaxes[i+1], a[i]);
			RMQ rmq=new RMQ(a);
			HashMap<Integer, Integer> firstTimeSuffixMaxIs=new HashMap<>(), 
					lastTimeSuffixMaxIs=new HashMap<>();
			for (int i=0; i<n; i++) lastTimeSuffixMaxIs.put(suffixMaxes[i], i);
			for (int i=n-1; i>=0; i--) firstTimeSuffixMaxIs.put(suffixMaxes[i], i);
			for (int l=0; l+2<n; l++) {
				int value=prefixMaxes[l];
				int min=Math.max(l+2, firstTimeSuffixMaxIs.getOrDefault(value, n+1));
				int max=lastTimeSuffixMaxIs.getOrDefault(value, -1);
				while (min<=max) {
					int mid=(min+max)/2;
					if (rmq.query(l+1, mid-1)==value) {
						System.out.println("YES");
						int midSize=mid-l-1;
						int rightSize=n-mid;
						System.out.println((l+1)+" "+midSize+" "+rightSize);
						continue outer;
					}
					else if (rmq.query(l+1, mid-1)<value) {
						max=mid-1;
					}
					else {
						min=mid+1;
					}
				}
			}
			System.out.println("NO");
		}
	}
	
	static class RMQ {
		int[] vs;
		int[][] lift;

		public RMQ(int[] vs) {
			this.vs = vs;
			int n = vs.length;
			int maxlog = Integer.numberOfTrailingZeros(Integer.highestOneBit(n)) + 2;
			lift = new int[maxlog][n];
			for (int i = 0; i < n; i++)
				lift[0][i] = vs[i];
			int lastRange = 1;
			for (int lg = 1; lg < maxlog; lg++) {
				for (int i = 0; i < n; i++) {
					lift[lg][i] = Math.min(lift[lg - 1][i], lift[lg - 1][Math.min(i + lastRange, n - 1)]);
				}
				lastRange *= 2;
			}
		}

		public int query(int low, int hi) {
			int range = hi - low + 1;
			int exp = Integer.highestOneBit(range);
			int lg = Integer.numberOfTrailingZeros(exp);
			return Math.min(lift[lg][low], lift[lg][hi - exp + 1]);
		}
	}


	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	
}