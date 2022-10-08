import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
/*

 */
public class C2 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), k=fs.nextInt();
			int[] a=new int[k];
			for (int i=0; i<k; i++) a[i]=i+1;
			
			int toReverse=1+(n-k);
			int startInd=k-toReverse, endInd=k-1;
			for (int i=0; i<toReverse/2; i++) {
				int l=startInd+i, r=endInd-i;
				int temp=a[l];
				a[l]=a[r];
				a[r]=temp;
			}
			
			for (int i=0; i<k; i++) out.print(a[i]+" ");
			out.println();
		}
		out.close();
	}
	
	static class Pair implements Comparable<Pair> {
		int val, ind;
		public Pair(int val, int ind) {
			this.val=val;
			this.ind=ind;
		}
		
		public int compareTo(Pair o) {
			return Integer.compare(val, o.val);
		}
	}

	static void ruffle_sort(int[] a) {
		//shandom_ruffle
		Random r=new Random();
		int n=a.length;
		for (int i=0; i<n; i++) {
			int oi=r.nextInt(n);
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