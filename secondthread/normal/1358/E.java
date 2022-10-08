import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
/*
5
-2 -2 6
-1

5
-2 -2 6
-2

3
0 1 
-1

3
0 2 
-1

3
-1 2 
-1
 */
public class E {

	static final boolean debug=false;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] firstHalf=fs.readArray((n+1)/2);
		int secondHalf=fs.nextInt();
		int[] a=new int[n];
		for (int i=0; i<n; i++) if (i<firstHalf.length) a[i]=firstHalf[i]; else a[i]=secondHalf;
		long[] cs=new long[n+1];
		for (int i=1; i<cs.length; i++) cs[i]=cs[i-1]+a[i-1];
		if (secondHalf>=0) {
			if (cs[n]>0)
				System.out.println(n);
			else
				System.out.println(-1);
			return;
		}
		int curLen=n;
		for (int l=0; l<=n-curLen && curLen>n/2; l++) {
			int r=rightmostEndpoint(cs, l, n);
			int restriction=(r-l)+1;
			if (debug) {
				System.out.println(l+" gives length restriction "+restriction);
			}
			curLen=Math.min(curLen, restriction);
		}
		if (curLen<=n/2) {
			System.out.println(-1);
		}
		else {
			System.out.println(curLen);
		}
	}
	
	static int rightmostEndpoint(long[] cs, int l, int n) {
		int min=n/2;
		if (cs[min+1]-cs[l]<=0) return -1;
		int max=n-1;
		while (min!=max) {
			int mid=(min+max+1)/2;
			long val=cs[mid+1]-cs[l];
			if (val<=0) {
				max=mid-1;
			}
			else {
				min=mid;
			}
		}
		return min;
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