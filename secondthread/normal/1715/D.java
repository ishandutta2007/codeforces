import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

public class D {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt(), m=fs.nextInt();
		ArrayList<Edge>[] graph=new ArrayList[n];
		for (int i=0; i<n; i++) graph[i]=new ArrayList<>();
		for (int i=0; i<m; i++) {
			int from=fs.nextInt()-1, to=fs.nextInt()-1, val=fs.nextInt();
			graph[from].add(new Edge(from, to, val));
			graph[to].add(new Edge(to, from, val));
		}
		long[] answers=new long[n];
		for (int bit=0; bit<30; bit++) {
			solveForBit(bit, graph, n, answers);
		}
		for (int i=0; i<n; i++) out.print(answers[i]+" ");
		out.println();
		out.close();
	}
	
	static boolean has(int val, int bit) {
		return (val&(1<<bit))!=0;
	}
	
	static void solveForBit(int bit, ArrayList<Edge>[] graph, 
			int n, long[] answers) {
		boolean[] isOne=new boolean[n];
		boolean[] forcedZero=new boolean[n];
		boolean[] forcedOne=new boolean[n];
		for (int i=0; i<n; i++) {
			for (Edge e:graph[i]) {
				if (!has(e.val, bit)) {
					forcedZero[i]=true;
				}
				else if (e.to==i) {
					forcedOne[i]=true;
				}
			}
		}
		
		for (int i=0; i<n; i++) {
			if (forcedOne[i]) {
				isOne[i]=true;
				continue;
			}
			if (forcedZero[i]) {
				isOne[i]=false;
				continue;
			}
			//can we make this a zero
			for (Edge e:graph[i]) {
				//e better be a 1, otherwise we'd be a forced zero
				if (e.to<i && !isOne[e.to]) {
					//then we're forced to be a one by him
					isOne[i]=true;
				}
				if (forcedZero[e.to]) {
					isOne[i]=true;
				}
			}
		}
		for (int i=0; i<n; i++) {
			if (isOne[i]) {
				answers[i]+=1<<bit;
			}
		}
	}
	
	
	static class Edge {
		int from, to, val;
		public Edge(int from, int to, int val) {
			this.from=from;
			this.to=to;
			this.val=val;
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