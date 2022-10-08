import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.StringTokenizer;
/*


Set of known nodes
priority queue of options
take min option
update all adjant

Option: [node, cost]


 */
public class C {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
//		int T=fs.nextInt();
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), m=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node(i+1);
			for (int i=0; i<m; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[b].adj.add(nodes[a]);
				nodes[a].adjSize++;
//				nodes[b].adj.add(nodes[a]);
			}
			
			nodes[n-1].cost=0;
			PriorityQueue<Option> pq=new PriorityQueue<>();
			pq.add(new Option(nodes[n-1], 0));
			while (!pq.isEmpty()) {
				Option toTake=pq.remove();
				if (toTake.n.included)
					continue;
				toTake.n.included=true;
				//consider all of n's new options
				for (Node nn:toTake.n.adj) {
					if (nn.included) continue;
					Option o = nn.onNewNodeLegal(toTake.n, toTake.cost);
					pq.add(o);
				}
			}
			
//			for (Node nn:nodes) {
//				System.out.println(nn.id+" "+nn.cost);
//			}
			
			out.println(nodes[0].cost);
		}
		out.close();
	}
	
	static class Node {
		boolean included;
		long cost=Long.MAX_VALUE/2;
		int id;
		ArrayList<Node> adj=new ArrayList<>();
		ArrayList<Long> options=new ArrayList<>();
		int adjSize=0;
		
		public Node(int id) {
			this.id=id;
		}
		public Option onNewNodeLegal(Node next, long costToNext) {
			options.add(costToNext);
			//either keep the current cost, or take the worst of left
			cost=Math.min(cost, costToNext+1+(adjSize-options.size()));
//			System.out.println("At node "+id+" cost to "+next.id+" "+costToNext+" " +adj.size()+" "+options.size());
			return new Option(this, cost);
		}
		
	}
	
	static class Option implements Comparable<Option> {
		Node n;
		long cost;
		public Option (Node n, long cost) {
			this.n=n;
			this.cost=cost;
		}
		public int compareTo(Option o) {
			return Long.compare(cost, o.cost);
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