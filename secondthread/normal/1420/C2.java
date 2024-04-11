import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class C2 {
	
	static long ans;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), q=fs.nextInt();
			int[] a=new int[n];
			ans=0;
			for (int i=0; i<n; i++)
				change(i, fs.nextInt(), a);
			out.println(ans);
			for (int qq=0; qq<q; qq++) {
				int from=fs.nextInt()-1, to=fs.nextInt()-1;
				int temp=a[from];
				change(from, a[to], a);
				change(to, temp, a);
				out.println(ans);	
			}
		}
		out.close();
	}

	static void change(int ind, int newVal, int[] a) {
		ans-=a[0];
		if (ind>0) ans-=Math.max(0, a[ind]-a[ind-1]);
		if (ind+1<a.length) ans-=Math.max(0, a[ind+1]-a[ind]);
		
		a[ind]=newVal;
		
		if (ind>0) ans+=Math.max(0, a[ind]-a[ind-1]);
		if (ind+1<a.length) ans+=Math.max(0, a[ind+1]-a[ind]);
		ans+=a[0];
	}
	
	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
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