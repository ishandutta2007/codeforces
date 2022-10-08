import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			ArrayList<Integer>[] occs=new ArrayList[n+1];
			for (int i=0; i<=n; i++) occs[i]=new ArrayList<>();
			for (int i=0; i<n; i++) occs[a[i]].add(i);
			ArrayList<Integer>[] valid=new ArrayList[n+1];
			for (int i=0; i<=n; i++) valid[i]=new ArrayList<>();
			for (int i=0; i<=n; i++) {
				occs[i].add(n);
				int gap=occs[i].get(0)+1;
				for (int j=1; j<occs[i].size(); j++) {
					gap=Math.max(gap, occs[i].get(j)-occs[i].get(j-1));
				}
				if (gap<=n) valid[gap].add(i);
			}
			int min=-1;
			for (int i=1; i<=n; i++) {
				if (valid[i].size()!=0) 
					if (min==-1 || valid[i].get(0)<min) min=valid[i].get(0);
				out.print(min+" ");
			}
			out.println();
			
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