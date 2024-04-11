import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/*
1 2 3 4 5
1 2 3 4 1

2*10^5
1000
300
17


1 2 1 2
 */
public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			ArrayList<Integer> a=new ArrayList<>(), b=new ArrayList<>();
			int n=fs.nextInt(), on=n;
			for (int i=n-1; i>2; i--) {
				while (i*(long)i<=n) {
					n=(n+i-1)/i;
					a.add(on);
					b.add(i);
				}
				a.add(i);
				b.add(on);
			}
			while (n>1) {
				n=(n+1)/2;
				a.add(on);
				b.add(2);
			}
			out.println(a.size());
			for (int i=0; i<a.size(); i++) {
				out.println(a.get(i)+" "+b.get(i));
			}
		}
		out.close();
	}
	
	static class Pair implements Comparable<Pair> {
		int index, value;
		public Pair(int index, int value) {
			this.index=index;
			this.value=value;
		}
		
		public int compareTo(Pair o) {
			if (value!=o.value) return Integer.compare(value, o.value);
			return Integer.compare(index, o.index);
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