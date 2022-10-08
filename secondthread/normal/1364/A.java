import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), x=fs.nextInt();
			int[] a=fs.readArray(n);
			long[] cs=new long[n+1];
			for (int i=1; i<=n; i++) cs[i]=cs[i-1]+a[i-1];
			if (x==1) {
				System.out.println(-1);
				continue;
			}
			int lastIndex=0;
			for (int i=0; i<n; i++) if (a[i]%x!=0) lastIndex=i;
			int ans=-1;
			for (int start=0; start<n; start++) {
				long fullSum=cs[n]-cs[start];
				if (fullSum%x!=0) ans=Math.max(ans, n-start);
				long partial=cs[lastIndex]-cs[start];
				if (partial%x!=0) ans=Math.max(ans, lastIndex-start);
			}
			System.out.println(ans);
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