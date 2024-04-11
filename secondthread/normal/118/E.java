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


3 3
1 2
2 3
3 1
 */
public class Temp {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
//		int T=fs.nextInt();
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int m=fs.nextInt();
			adj=new ArrayList[n];
			visited=new boolean[n];
			preorder=new int[n];
			lowlink=new int[n];
			Edge[] edges=new Edge[m];
			for (int i=0; i<n; i++) adj[i]=new ArrayList<>();
			for (int i=0; i<m; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				edges[i]=new Edge(a, b);
				adj[a].add(edges[i]);
				adj[b].add(edges[i]);
			}
			dfs(0, null);
			boolean possible=true;
//			System.out.println("Visited "+Arrays.toString(visited));
//			System.out.println("Preorder "+Arrays.toString(preorder));
//			System.out.println("Lowlink "+Arrays.toString(lowlink));
			for (boolean b:visited) {
				if (!b) possible=false;
			}
			for (int i=1; i<n; i++) if (preorder[i]==lowlink[i]) possible=false;
			if (!possible) {
				out.println(0);
			}
			else {
				for (Edge e:edges) {
					out.println(e.root+1+" "+(e.o(e.root)+1));
				}
			}
			
		}
		out.close();
	}
	
	static int globalInd=0;
	static boolean[] visited;
	static int[] preorder;
	static int[] lowlink;
	static ArrayList<Edge>[] adj;
	
	static void dfs(int at, Edge par) {
		visited[at]=true;
		lowlink[at] = preorder[at]=globalInd++;
		for (Edge e:adj[at]) {
			if (e==par) continue;
			int to=e.o(at);
			e.setRoot(at);
			if (visited[to]) {
				//then update lowlink
				lowlink[at]=Math.min(lowlink[at], preorder[to]);
			}
			else {
				dfs(to, e);
				lowlink[at]=Math.min(lowlink[at], lowlink[to]);
			}
		}
	}
	
	static class Edge {
		int a, b;
		int root=-1;
		public Edge(int a, int b) {
			this.a=a;
			this.b=b;
		}
		int o(int me) {
			return me^a^b;
		}
		public void setRoot(int root) {
			if (this.root==-1) {
				this.root=root;
			}
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