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
public class D {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		//TODO: hardcode n==2 case
		PrintWriter out=new PrintWriter(System.out);
		int T=1;
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node(i);
			for (int i=1; i<n; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
			}
			Ans ans=nodes[0].goAllowed(null);
			if (n==2) ans.maxNodes=2;
			out.println(ans.maxNodes+" "+ans.minCost);
			//TODO: rebuild
			nodes[0].buildbackAllowed(null);
			for (Node nn:nodes) {
				if (nn.taken)
					out.print(nn.adj.size()+" ");
				else
					out.print(1+" ");
			}
			out.println();
		}
		out.close();
	}
	
	static class Ans {
		int maxNodes;
		int minCost;
		public String toString() {
			return maxNodes+" $"+minCost;
		}
	}
	static Ans better(Ans a, Ans b) {
		if (a==null) return b;
		if (b==null) return a;
		if (a.maxNodes!=b.maxNodes) return a.maxNodes<b.maxNodes?b:a;
		return b.minCost<=a.minCost?b:a;
		
	}
	
	static class Node {
		Ans ifAllowed, ifNotAllowed;
		ArrayList<Node> adj=new ArrayList<>();
		int id;
		boolean taken=false;
		
		public Node(int id) {
			this.id=id;
		}
		
		public void buildbackAllowed(Node root) {
			Ans ifTake=new Ans();
			ifTake.maxNodes+=1;
			ifTake.minCost+=adj.size();
			for (Node nn:adj) if (nn!=root) {
				Ans kidAns=nn.goNotAllowed(this);
				ifTake.maxNodes+=kidAns.maxNodes;
				ifTake.minCost+=kidAns.minCost;
			}
			Ans ifDont=goNotAllowed(root);
			if (better(ifTake, ifDont)==ifTake) {
				taken=true;
				for (Node nn:adj) if (nn!=root) {
					nn.buildbackNotAllowed(this);
				}
			}
			else {
				for (Node nn:adj) if (nn!=root) {
					nn.buildbackAllowed(this);
				}
			}
		}
		public void buildbackNotAllowed(Node root) {
			for (Node nn:adj) if (nn!=root) {
				nn.buildbackAllowed(this);
			}
		}
		public Ans goAllowed(Node root) {
			if (ifAllowed!=null) return ifAllowed;
			Ans ifTake=new Ans();
			ifTake.maxNodes+=1;
			ifTake.minCost+=adj.size();
			for (Node nn:adj) if (nn!=root) {
				Ans kidAns=nn.goNotAllowed(this);
				ifTake.maxNodes+=kidAns.maxNodes;
				ifTake.minCost+=kidAns.minCost;
			}
			Ans ifDont=goNotAllowed(root);
			return ifAllowed=better(ifTake, ifDont);
		}
		public Ans goNotAllowed(Node root) {
			if (ifNotAllowed!=null) return ifNotAllowed;
			ifNotAllowed=new Ans();
			ifNotAllowed.minCost++;
			for (Node nn:adj) if (nn!=root) {
				Ans kidAns=nn.goAllowed(this);
				ifNotAllowed.maxNodes+=kidAns.maxNodes;
				ifNotAllowed.minCost+=kidAns.minCost;
			}
			return ifNotAllowed;
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