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
			int n=fs.nextInt(), k=fs.nextInt();
			char[] line=fs.next().toCharArray();
			boolean[] on=new boolean[k], off=new boolean[k];
			for (int i=0; i<n; i++) {
				if (line[i]=='1') on[i%k]=true;
				if (line[i]=='0') off[i%k]=true;
			}
			boolean works=true;
			for (int i=0; i<k; i++) if (on[i]&&off[i]) works=false;
			int onCount=0, offCount=0;
			for (int i=0; i<k; i++) if (on[i]) onCount++; else if (off[i]) offCount++;
			if (onCount*2>k || offCount*2>k) works=false;
			System.out.println(works?"YES":"NO");
			
		}
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