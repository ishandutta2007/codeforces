import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

/*

 */
public class C {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			ArrayList<Edge>[] nodes=new ArrayList[n];
			for (int i=0; i<n; i++) nodes[i]=new ArrayList<>();
			Edge[] edges=new Edge[n-1];
			for (int i=1; i<n; i++) {
				edges[i-1]=new Edge(fs.nextInt()-1, fs.nextInt()-1);
				nodes[edges[i-1].from].add(edges[i-1]);
				nodes[edges[i-1].to].add(edges[i-1]);
			}
			
			//check if impossible
			for (int i=0; i<n; i++) {
				if (nodes[i].size()>2) {
					out.println(-1);
					continue outer;
				}
			}
			
			int endpoint=0;
			for (int i=1; i<n; i++) if (nodes[i].size()==1) endpoint=i;
			Edge from=null;
			ArrayList<Edge> edgesSorted=new ArrayList<>();
			while (true) {
//				System.out.println("At "+endpoint+" "+from);
				if (nodes[endpoint].get(0)==from) {
					if (nodes[endpoint].size()==1) break;
					from=nodes[endpoint].get(1);
				}
				else
					from=nodes[endpoint].get(0);
				endpoint^=from.from^from.to;
				edgesSorted.add(from);
			}
			for (int i=0; i<edgesSorted.size(); i++) edgesSorted.get(i).color=2+i%2;
			for (int i=0; i<n-1; i++) {
				out.print(edges[i].color+" ");
			}
			out.println();
		}
		out.close();
	}
	
	static class Edge {
		int from, to;
		int color;
		public Edge(int from, int to) {
			this.from=from;
			this.to=to;
		}
		public String toString() {
			return from+" "+to;
		}
	}
	
	static final Random random=new Random();
	static final int mod=1_000_000_007;
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
	}
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return (a*b)%mod;
	}
	static long exp(long base, long exp) {
		if (exp==0) return 1;
		long half=exp(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
	}
	static long[] factorials=new long[2_000_001];
	static long[] invFactorials=new long[2_000_001];
	static void precompFacts() {
		factorials[0]=invFactorials[0]=1;
		for (int i=1; i<factorials.length; i++) factorials[i]=mul(factorials[i-1], i);
		invFactorials[factorials.length-1]=exp(factorials[factorials.length-1], mod-2);
		for (int i=invFactorials.length-2; i>=0; i--)
			invFactorials[i]=mul(invFactorials[i+1], i+1);
	}
	
	static long nCk(int n, int k) {
		return mul(factorials[n], mul(invFactorials[k], invFactorials[n-k]));
	}
	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
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