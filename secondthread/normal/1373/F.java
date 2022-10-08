import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
2
1 1
10 10

1
4
2 3 4 5
3 7 2 2
 */
public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=new int[n+n], b=new int[n+n];
			for (int i=0; i<n; i++) a[i]=a[i+n]=fs.nextInt();
			for (int i=0; i<n; i++) b[i]=b[i+n]=fs.nextInt();
			long[] diffs=new long[n+n];
			for (int i=0; i<diffs.length; i++) diffs[i]=a[i]-b[i];
			long diffSum=0;
			for (long l:diffs) diffSum+=l;
			if (diffSum>0) {
				System.out.println("NO");
				continue;
			}
			long[] diffCS=new long[n+n+1];
			for (int i=1; i<diffCS.length; i++) diffCS[i]=diffs[i-1]+diffCS[i-1];
//			System.out.println("Differences: "+Arrays.toString(diffs));
//			System.out.println("DiffCS: "+Arrays.toString(diffCS));
			RMQLowMemory rmq=new RMQLowMemory(diffCS);
			for (int l=0; l<n; l++) {
				long csToSub=diffCS[l+1];
				long farCS=rmq.query(l+2, l+n);
				long rangeSum=farCS-csToSub;
//				System.out.println("At l: "+l+" rangeSum: "+rangeSum);
//				System.out.println("  toSub: "+csToSub+" farCS: "+farCS);
				if (rangeSum>b[l]) {
					System.out.println("NO");
					continue outer;
				}
			}
			System.out.println("YES");
		}
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	//#
	/*
	A memory efficient RMQ with O(n) precomp and O(1) queries.
	Compared to a normal RMQ, this has:
		~5 times faster precomp
		~1.8 times slower queries
		~10 times less memory usage
		
	Queries have slightly more overhead, so if you are doing more than O(n) 
	queries and aren't tight on memory, a regular rmq will probably be faster.
	 */
	//$
	static class RMQLowMemory {
		final static int blockSize=32;
		int[] low;
		long[] a;
		long[][] lift;
		
		public RMQLowMemory(long[] aFake) {
			a=new long[aFake.length];
			for (int i=0; i<a.length; i++) a[i]=-aFake[i];
			
			int n=a.length, m=0;
			low=new int[n];
			for (int i=0; i<n; low[i]=++m, m<<=1, i++)
				while (m!=0 && a[i-Integer.numberOfTrailingZeros(m)]>=a[i])
					m-=Integer.lowestOneBit(m);
			
			int nn=(n+blockSize-1)>>5;
			int maxlog = Integer.numberOfTrailingZeros(Integer.highestOneBit(nn)) + 2;
			lift = new long[maxlog][nn];
			Arrays.fill(lift[0], Long.MAX_VALUE);
			for (int i = 0; i < n; i++)
				lift[0][i/blockSize]=Math.min(lift[0][i/blockSize], a[i]);

			int lastRange = 1;
			for (int lg = 1; lg < maxlog; lg++, lastRange<<=1)
				for (int i = 0; i < nn; i++)
					lift[lg][i] = Math.min(lift[lg - 1][i], lift[lg - 1][Math.min(i + lastRange, nn - 1)]);
			
		}
		
		long query(int low, int high) {
			high++;
			int lowBlock=(low+blockSize-1)>>5, highBlock=high>>5;
			long crossBlock=acrossBlockQuery(lowBlock, highBlock);
			long edge1=edgeQuery(Math.max(low, high-blockSize), high);
			long edge2=edgeQuery(low, Math.min(low+blockSize-1, high));
			return -Math.min(Math.min(edge1, edge2), crossBlock);
		}

		long acrossBlockQuery(int lBlock, int hBlock) {
			if (lBlock>=hBlock) return Integer.MAX_VALUE;
			int exp = Integer.highestOneBit(hBlock-lBlock);
			int lg = Integer.numberOfTrailingZeros(exp);
			return Math.min(lift[lg][lBlock], lift[lg][hBlock - exp]);
		}
		
		long edgeQuery(int l, int h) {
			int mask=(int) (low[h-1]&((1l<<h-l)-1));
			int moveLeft=Integer.numberOfTrailingZeros(Integer.highestOneBit(mask));
			return a[h-1-moveLeft];
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