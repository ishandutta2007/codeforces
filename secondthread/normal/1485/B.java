import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

//Good morning!
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		//TODO: printwriter!
		int n=fs.nextInt();
		int nQueries=fs.nextInt();
		int k=fs.nextInt();
		int[] a=fs.readArray(n);
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			int l=fs.nextInt()-1, r=fs.nextInt()-1;
			int nZeros=r-l+1;
			int nOnes=a[l]-1 + k-a[r];
			int nTwos=k-nZeros-nOnes;
			int ans=nOnes+nTwos*2;
			out.println(ans);
		}
		out.close();
	}

	// Use this instead of Arrays.sort() on an array of ints. Arrays.sort() is n^2
	// worst case since it uses a version of quicksort. Although this would never
	// actually show up in the real world, in codeforces, people can hack, so
	// this is needed.
	static void ruffleSort(int[] a) {
		//ruffle
		int n=a.length;
		Random r=new Random();
		for (int i=0; i<a.length; i++) {
			int oi=r.nextInt(n), temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
		}
		
		//then sort
		Arrays.sort(a);
	}
	
	// Use this to input code since it is faster than a Scanner
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