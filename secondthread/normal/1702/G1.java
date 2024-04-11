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

everything will be part of 2 paths

sort by preorder
first path will have icreasing depths, increasing preorder

Possibly a decrease in depths, still increasing preorder

You contain the next person for all but one step


 */
public class G {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) nodes[i]=new Node();
		for (int i=1; i<nodes.length; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}

		nodes[0].dfs(null, 0, 0);
		for (int i=1; i<20; i++)
			for (Node nn:nodes)
				if (nn.lift[i-1]!=null)
					nn.lift[i]=nn.lift[i-1].lift[i-1];
		
		int nq=fs.nextInt();
		test: for (int qq=0; qq<nq; qq++) {
			int qSize=fs.nextInt();
			Node[] query=new Node[qSize];
			for (int i=0; i<qSize; i++) query[i]=nodes[fs.nextInt()-1];
			Arrays.sort(query);
			int missCount=0;
			for (int i=1; i<qSize; i++) {
				if (!query[i-1].contains(query[i])) {
					missCount++;
					Node lca=query[i-1].LCA(query[i], 19);
					if (query[0]!=lca && query[0].contains(query[i])) {
						out.println("NO");
						continue test;
					}
				}
			}
			out.println(missCount>1?"NO":"YES");
		}
		out.close();
	}
	
	int counter;
	
	static class Node implements Comparable<Node> {
		int pre, post, depth;
		ArrayList<Node> adj=new ArrayList<>();
		Node[] lift=new Node[20];
		
		public int dfs(Node par, int counter, int depth) {
			pre=counter++;
			this.depth=depth;
			lift[0]=par;
			for (Node nn:adj)
				if (nn!=par)
					counter=nn.dfs(this, counter, depth+1);
			return post=counter;
		}
		boolean contains(Node o) {
			return pre<=o.pre && post>=o.post;
		}
		public int compareTo(Node o) {
			return Integer.compare(pre, o.pre);
		}
		Node atDepth(int d) {
			if (depth==d) return this;
			int goUp=depth-d;
			return lift[Integer.numberOfTrailingZeros(goUp)].atDepth(d);
		}
		Node LCA(Node o, int maxLift) {
			if (depth!=o.depth) {
				int targetD=Math.min(depth, o.depth);
				return atDepth(targetD).LCA(o.atDepth(targetD), maxLift);
			}
			if (this==o) return this;
			if (this.lift[0]==o.lift[0]) return lift[0];
			while (lift[maxLift]==o.lift[maxLift]) {
				maxLift--;
			}
			return lift[maxLift].LCA(o.lift[maxLift], maxLift);
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