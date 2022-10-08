import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=fs.readArray(n);
		long[] cs=new long[n+1];
		for (int i=1; i<=n; i++) cs[i]=cs[i-1]+a[i-1];
		RMQ rmq=new RMQ(cs);
		
		int[] firstOccurranceOf=new int[61];
		int OFFSET_INDEX=30;
		Arrays.fill(firstOccurranceOf, n);
		long ans=0;
		for (int l=n-1; l>=0; l--) {
			//include this left point
			firstOccurranceOf[a[l]+OFFSET_INDEX]=l;
			int betterIndex=n;
			for (int removed=30; removed>=-30; removed--) {
				//query the max CS in range [firstOccurenceOf[removed+OFFSETIndex] .. betterIndex]
				if (firstOccurranceOf[removed+OFFSET_INDEX]<betterIndex) {
					long maxQuery=rmq.query(firstOccurranceOf[removed+OFFSET_INDEX]+1, betterIndex);
					long realValue=maxQuery-cs[l]-removed;
					ans=Math.max(ans, realValue);
				}
				
				betterIndex=Math.min(betterIndex, firstOccurranceOf[removed+OFFSET_INDEX]);
			}
		}
		System.out.println(ans);
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class RMQ {
		long[] vs;
		long[][] lift;

		public RMQ(long[] vs) {
			this.vs = vs;
			int n = vs.length;
			int maxlog = Integer.numberOfTrailingZeros(Integer.highestOneBit(n)) + 2;
			lift = new long[maxlog][n];
			for (int i = 0; i < n; i++)
				lift[0][i] = vs[i];
			int lastRange = 1;
			for (int lg = 1; lg < maxlog; lg++) {
				for (int i = 0; i < n; i++) {
					lift[lg][i] = Math.max(lift[lg - 1][i], lift[lg - 1][Math.min(i + lastRange, n - 1)]);
				}
				lastRange *= 2;
			}
		}

		public long query(int low, int hi) {
			int range = hi - low + 1;
			int exp = Integer.highestOneBit(range);
			int lg = Integer.numberOfTrailingZeros(exp);
			return Math.max(lift[lg][low], lift[lg][hi - exp + 1]);
		}
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