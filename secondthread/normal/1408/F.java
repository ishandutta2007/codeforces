import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		if (Integer.bitCount(n)==1) {
			ArrayList<Pair> res=solve(n);
			System.out.println(res.size());
			for (Pair p:res) System.out.println(p);
			return;
		}
		int highestBit=Integer.highestOneBit(n);
		ArrayList<Pair> g1=solve(highestBit), g2=solve(highestBit);
		for (Pair p:g2) {
			p.i+=n-highestBit;
			p.j+=n-highestBit;
		}
		System.out.println(g1.size()+g2.size());
		for (Pair p:g1) System.out.println(p);
		for (Pair p:g2) System.out.println(p);
	}

	static ArrayList<Pair> solve(int n) {
		if (Integer.bitCount(n)!=1) throw null;
		ArrayList<Pair> res=new ArrayList<>();
		for (int e=0; 1<<e<n; e++) {
			boolean[] used=new boolean[n];
			for (int i=0; i<n; i++) {
				if (used[i]) continue;
				used[i]=used[i^(1<<e)]=true;
				res.add(new Pair(i, i^(1<<e)));
			}
		}
		return res;
	}
	
	static class Pair {
		int i, j;
		
		public Pair(int i, int j) {
			this.i=i;
			this.j=j;
		}
		
		public String toString() {
			return (i+1)+" "+(j+1);
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