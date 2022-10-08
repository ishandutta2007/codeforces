import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class B {

	static long[] a;
	static PrintWriter out;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			a=new long[n];
			for (int i=0; i<n; i++) a[i]=fs.nextLong();
			long sum=0;
			for (long i:a) sum+=i;
			if (sum%n!=0) {
				out.println(-1);
				continue;
			}
			out.println((n-1)*3);
			for (int o=1; o<n; o++) {
				long mod=a[o]%(o+1);
				mod=((-mod)%(o+1)+o+1)%(o+1);
				move(0, o, mod);
				move(o, 0, a[o]);
			}
			for (int o=1; o<n; o++) {
				move(0, o, sum/n);
			}
		}
		out.close();
	}
	
	static void move(int from, int to, long amount) {
		out.println(from+1+" "+(to+1)+" "+(amount/(from+1)));
		a[from]-=amount;
		a[to]+=amount;
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