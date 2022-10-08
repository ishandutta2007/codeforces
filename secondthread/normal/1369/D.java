import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int MAX=3_000_000;
		long MOD=1_000_000_007;
		long[] ans=new long[MAX];
		boolean[] usingTop=new boolean[MAX];
		ans[3]=1;
		usingTop[3]=true;
		for (int i=4; i<MAX; i++) {
			ans[i]=(2*ans[i-2]+ans[i-1])%MOD;
			if (usingTop[i-2] || usingTop[i-1]) {
				usingTop[i]=false;
			}
			else {
				usingTop[i]=true;
				ans[i]=(ans[i]+1)%MOD;
			}
		}
		
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			out.println((4*ans[fs.nextInt()])%MOD);
		}
		out.close();
		
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