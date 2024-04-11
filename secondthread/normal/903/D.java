import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++)
			a[i]=fs.nextInt();
		HashSet<Integer> allValues=new HashSet<>();
		for (int i:a) {
			allValues.add(i);
			allValues.add(i-1);
			allValues.add(i+1);
		}
		int[] valuesArray=new int[allValues.size()];
		int index=0;
		for (int i:allValues)
			valuesArray[index++]=i;
		
		Arrays.sort(valuesArray);
		HashMap<Integer, Integer> compress=new HashMap<>();
		int[] decompress=valuesArray;
		for (int i=0; i<decompress.length; i++)
			compress.put(decompress[i], i);
		
		int[] compressedArray=new int[n];
		for (int i=0; i<n; i++)
			compressedArray[i]=compress.get(a[i]);
		
		FenwickTree howMany=new FenwickTree(decompress.length);
		FenwickTree total=new FenwickTree(decompress.length);
		
		BigInteger finalAns=new BigInteger("0");
		for (int i:compressedArray) {
			int realValue=decompress[i];
			//count stuff
			long intermediate=0;
			long meCount=realValue*howMany.sum(0, i-2);
			long themCount=total.sum(0, i-2);
			intermediate+=meCount-themCount;
			meCount=realValue*howMany.sum(i+2, decompress.length);
			themCount=total.sum(i+2, decompress.length);
			intermediate+=meCount-themCount;
			
			finalAns=finalAns.add(new BigInteger(""+intermediate));
			
			//update fenwick trees
			howMany.upd(i, 1);
			total.upd(i, realValue);//n things, all with value 10^9
		}
		
		System.out.println(finalAns.toString());
		
	}

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
			st = new StringTokenizer("");
		}
		
		public String next() {
			if (st.hasMoreTokens())
				return st.nextToken();
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		private int nextInt() {
			return Integer.parseInt(next());
		}
		
		private long nextLong() {
			return Long.parseLong(next());
		}
		
	}

	static class FenwickTree {
		long[] vs;

		public FenwickTree(int s) {
			vs = new long[s + 5];
		}

		public long sum(int idx) {
			idx++;
			long ret = 0;
			for (int i = idx; i > 0; i -= (i & -i))
				ret += vs[i];
			return ret;
		}
		
		public long sum(int l, int r) {
			return sum(r)-sum(l-1);
		}

		public void upd(int idx, int v) {
			idx++;
			for (int i = idx; i < vs.length; i += (i & -i))
				vs[i] += v;
		}
	}

}