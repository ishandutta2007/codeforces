import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
/*
 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), nQ=fs.nextInt();
			char[] line=fs.next().toCharArray();
			int[] max=new int[n+1], min=new int[n+1], end=new int[n+1];
			int[] maxr=new int[n+1], minr=new int[n+1], endr=new int[n+1];
			
			int curMax=0, curMin=0, cur=0;
			for (int i=0; i<n; i++) {
				cur+=(line[i]=='+')?1:-1;
				curMax=Math.max(curMax, cur);
				curMin=Math.min(curMin, cur);
				max[i+1]=curMax;
				min[i+1]=curMin;
				end[i+1]=cur;
			}
			curMax=curMin=cur=0;
			for (int i=n-1; i>=0; i--) {
				cur+=(line[i]=='-')?1:-1;
				curMax=Math.max(curMax, cur);
				curMin=Math.min(curMin, cur);
				maxr[i]=curMax;
				minr[i]=curMin;
				endr[i]=cur;
			}
			
			// - | - - +
			for (int qq=0; qq<nQ; qq++) {
				int l=fs.nextInt()-1, r=fs.nextInt();
				int premax=max[l], premin=min[l];
				int postmax=end[l]+(maxr[r]-endr[r]);
				int postmin=end[l]+(minr[r]-endr[r]);
				
				out.println(Math.max(premax, postmax)-Math.min(premin, postmin)+1);
			}
		}
		out.close();
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