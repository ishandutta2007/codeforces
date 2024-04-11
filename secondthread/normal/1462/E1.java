import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/* 
 * Subscribe to galen_colin!
 * https://tinyurl.com/galencolin
*/
public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=3, rangeSize=2;// k=fs.nextInt(), rangeSize=fs.nextInt();
			int[] a=fs.readArray(n);
			int[] freq=new int[n+1];
			for (int i:a) freq[i]++;
			int[] cs=new int[freq.length+1];
			for (int i=1; i<cs.length; i++) cs[i]=cs[i-1]+freq[i-1];
			long ways=0;
			for (int max=0; max<freq.length; max++) {
				int nLessThan=cs[max]-cs[Math.max(0, max-rangeSize)];
				for (int toInclude=1; toInclude<=freq[max]; toInclude++) {
					if (nLessThan+toInclude<k) continue;
					long toAdd=nC2(nLessThan+toInclude-1);
					ways+=toAdd;
				}
			}
			out.println(ways);
		}
		out.close();
	}
	
	static long nC2(long n) {
		return n*(n-1)/2;
	}

	static void ruffle_sort(int[] a) {
		//shandom_ruffle
		Random r=new Random();
		int n=a.length;
		for (int i=0; i<n; i++) {
			int oi=r.nextInt(i);
			int temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
		}
		
		//sort
		Arrays.sort(a);
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