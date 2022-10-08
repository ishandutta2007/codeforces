import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), x=fs.nextInt(), y=fs.nextInt();
			int best=Integer.MAX_VALUE;
			int[] bestA=null;
			for (int start=1; start<=50; start++) {
				for (int diff=1; diff<=50; diff++) {
					int[] a=gen(n, start, diff);
					boolean hasX=false, hasY=false;
					for (int i:a) {
						if (i==x) hasX=true;
						if (i==y) hasY=true;
					}
					if (hasX&&hasY && a[n-1]<best) {
						best=a[n-1];
						bestA=a;
					}
				}
			}
			for (int i:bestA)
				System.out.print(i+" ");
			System.out.println();
		}
	}
	
	static int[] gen(int n, int start, int diff) {
		int[] a=new int[n];
		a[0]=start;
		for (int i=1; i<n; i++) a[i]=a[i-1]+diff;
		return a;
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