import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			Pair[] pairs=new Pair[n];
			for (int i=0; i<n; i++) pairs[i]=new Pair(i, fs.nextInt());
			Arrays.sort(pairs);
			if (pairs[0].val+pairs[1].val<=pairs[n-1].val) {
				int[] ans= {pairs[0].index, pairs[1].index, pairs[n-1].index};
				Arrays.sort(ans);
				System.out.println(ans[0]+" "+ans[1]+" "+ans[2]);
			}
			else {
				System.out.println(-1);
			}
		}
	}

	static final Random random=new Random();
	
	static class Pair implements Comparable<Pair>{
		int index, val;
		public Pair(int index, int val) {
			this.index=index+1;
			this.val=val;
		}
		
		public int compareTo(Pair o) {
			return Integer.compare(val, o.val);
		}
	}
	
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