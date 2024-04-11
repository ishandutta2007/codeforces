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

1
5
1 2 3 4 5
2 3 1 5 4

2
6
1 2 3 4 5 6
2 3 4 1 6 5
6
1 2 3 4 5 6
2 1 4 5 6 3

5
1 2 3 4 5
1 2 4 5 3

 */

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n), b=fs.readArray(n);
			for (int i=0; i<n; i++) {
				a[i]--;
				b[i]--;
			}
			Node[] nodes=new Node[n];
			for (int i=0; i<n; i++) nodes[i]=new Node(i);
			for (int i=0; i<n; i++) {
				nodes[a[i]].adj.add(nodes[b[i]]);
				nodes[b[i]].adj.add(nodes[a[i]]);
			}

			ArrayList<ArrayList<Node>> groups=new ArrayList<>();
			for (Node nn:nodes) {
				if (nn.hit) continue;
				Node at=nn;
				Node to=at.adj.get(0);
				ArrayList<Node> group=new ArrayList<>();
				group.add(at);
				at.hit=true;
				while (!to.hit) {
					group.add(to);
					Node next=to.other(at);
					at=to;
					to=next;
					at.hit=true;
				}
				groups.add(group);
			}
			Collections.sort(groups, (aa, bb) -> Integer.compare(aa.size()%2, bb.size()%2));
			int low=0, high=n-1;
			boolean toLow=true;

			//if this is an odd group, we should just skip the last one
			for (ArrayList<Node> group:groups) {
				for (int i=0; i<group.size(); i++) {
					Node nn=group.get(i);
					if (group.size()%2==1 && i==group.size()-1) {
						//last one, ignore this
						if (group.size()!=1) {
							nn.label=group.get(0).label;
						}
					}
					else {
						if (toLow) {
							nn.label=low++;
						}
						else {
							nn.label=high--;
						}
						toLow^=true;
					}
				}
			}
			long ans=0;
			for (Node nn:nodes) {
				for (Node nnn:nn.adj) {
					ans+=Math.abs(nn.label-nnn.label);
				}
			}
			out.println(ans/2);
		}
		out.close();
	}

	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int id;
		boolean hit=false;
		int label=0;
		public Node(int id) {
			this.id=id;
		}
		Node other(Node me) {
			if (adj.get(0)==me) return adj.get(1);
			return adj.get(0);
		}
		
	}
	
	static final Random random=new Random();
	static final int mod=998244353;
	
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