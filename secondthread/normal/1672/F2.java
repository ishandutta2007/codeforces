import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

/*
1
6
1 2 3 4 4 4
4 4 4 1 2 3
5
1 2 4 4 4
4 4 1 2 4

5
1 2 3 4 4
4 4 1 2 3

1
3
2 3 1
1 2 3

1
5
1 3 2 5 4
2 5 1 4 3

6 
[3, 5, 3, 5, 5, 2]
[2, 3, 5, 3, 5, 5]

1
6 
2 3 5 3 5 5
3 5 3 5 5 2

6 
5 4 3 5 4 3
3 3 4 4 5 5


1
6 
5 4 3 5 4 3
3 3 4 4 5 5

 */
public class F4 {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer: for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			int[] b=fs.readArray(n);
			
//			Node[] nodes=new Node[n+1];
			Node[] nodes2=new Node[n+1];
//			for (int i=0; i<=n; i++) nodes[i]=new Node(i);
			for (int i=0; i<=n; i++) nodes2[i]=new Node(i);
			for (int i=0; i<n; i++) {
//				nodes[a[i]].adj.add(nodes[b[i]]);
				nodes2[a[i]].adj.add(nodes2[b[i]]);
			}
//			Node maxFreq=nodes[0];
//			for (Node nn:nodes)
//				if (nn.adj.size()>maxFreq.adj.size())
//					maxFreq=nn;
			
			Node maxFreq2=nodes2[0];
			for (Node nn:nodes2)
				if (nn.adj.size()>maxFreq2.adj.size())
					maxFreq2=nn;
			
			for (Node nn:nodes2) {
				if (nn==maxFreq2) continue;
				for (Node nnn:nn.adj) nnn.indegree++;
			}
			ArrayDeque<Node> bfs=new ArrayDeque<>();
			for (Node nn:nodes2) {
				if (nn==maxFreq2) continue;
				if (nn.indegree==0) bfs.addLast(nn);
			}
			while (!bfs.isEmpty()) {
				Node next=bfs.remove();
				for (Node nn:next.adj) {
					if (nn==maxFreq2) continue;
					nn.indegree--;
					if (nn.indegree==0) bfs.addLast(nn);
				}
			}
			boolean works=true;
			for (Node nn:nodes2) works&=nn.indegree==0 || nn==maxFreq2;
			System.out.println(works?"AC":"WA");
			
//			maxFreq.isMax=true;
//			for (Node nn:nodes) {
//				if (nn.full()) continue;
//				nn.dfs();
//			}
//			for (Node nn:nodes) {
//				if (nn.extraLoopStarts>0) {
//					System.out.println("WA");
//					continue outer;
//				}
//			}
//			System.out.println("AC");
		}
	}
	
	
	//every time you start at a node (except for the first time), you create a new loop
	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int edgeAt=0;
		int value;
		int extraLoopStarts=0;
		boolean isMax=false;
		int indegree=0;
		public Node(int value) {
			this.value=value;
		}
		public void dfs() {
			if (isMax) return;
			if (edgeAt!=0) extraLoopStarts++;
			while (!full()) {
				Node to=adj.get(edgeAt);
				edgeAt++;
				
				to.dfs();
			}
		}
		
		boolean full() {
			return edgeAt==adj.size();
		}
	}
	
	
	static final Random random=new Random(7);
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