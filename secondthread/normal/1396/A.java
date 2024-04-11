import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=1;//fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			if (n==1) {
				out.println("1 1");
				out.println(0);
				out.println("1 1");
				out.println(0);
				out.println("1 1");
				out.println(-a[0]);
			}
			else {
				out.println(1+" "+n);
				for (int i=0; i<n; i++) {
					out.print(-a[i]*(long)n+" ");
				}
				out.println();
				out.println("1 "+(n-1));
				for (int i=0; i+1<n; i++) {
					out.print(a[i]*(long)(n-1)+" ");
				}
				out.println();
				out.println("2 "+(n));
				for (int i=1; i+1<n; i++) {
					out.print("0 ");
				}
				out.println(a[n-1]*(long)(n-1)+" ");
			}
		}
		out.close();
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