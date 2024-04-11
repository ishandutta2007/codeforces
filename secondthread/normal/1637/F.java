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
public class F {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
//		int T=fs.nextInt();
//		for (int tt=0; tt<T; tt++) {
		int n=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++)
			nodes[i]=new Node(i, fs.nextInt());
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			nodes[a].adj.add(nodes[b]);
			nodes[b].adj.add(nodes[a]);
		}
		if (n==2) {
			System.out.println(2*Math.max(nodes[0].value, nodes[1].value));
			return;
		}
		
		//TODO: handle the case where the biggest value is a leaf
		Node max=null;
		Node maxLeaf=nodes[0];
		for (Node nn:nodes) {
			if (nn.value>maxLeaf.value) maxLeaf=nn;
			if (nn.adj.size()<2) continue;
			if (max==null || nn.value>max.value) max=nn;
		}
		if (maxLeaf.value>max.value) {
			max=maxLeaf.adj.get(0);
			max.value=maxLeaf.value;
		}
		max.dfs(null);
//		System.out.println("Max has value: "+max.value+" "+max);
		
		long ans=max.goRoot();
		System.out.println(ans);
//		}
	}
	
	static class Node implements Comparable<Node> {
		ArrayList<Node> adj=new ArrayList<>();
		int index, value;
		int subtreeMax;
		long costCovered=-1;
		long costUncovered=-1;
		
		public Node(int index, int value) {
			this.index=index;
			this.value=value;
		}
		
		public void dfs(Node from) {
			if (from!=null)
				adj.remove(from);
			for (Node nn:adj) nn.dfs(this);
			subtreeMax=value;
			for (Node nn:adj) subtreeMax=Math.max(subtreeMax, nn.subtreeMax);
		}
		
		public long goRoot() {
			//COLOR TWO KIDS
			for (Node nn:adj) {
				nn.goParCovered();
				nn.goParNotCovered();
			}
			Collections.sort(adj);
//			System.out.println("Looking at kids");
//			for (Node nn:adj) {
//				System.out.println(nn+" covered"+nn.costCovered+" uncovered: "+nn.costUncovered);
//			}
			long ans=value+value;
			for (int i=0; i<adj.size(); i++) {
				long toAdd=(i<2?adj.get(i).costCovered:adj.get(i).costUncovered);
				ans+=toAdd;
			}
			return ans;
		}
		public long goParCovered() {
			if (costCovered!=-1) {
				return costCovered;
			}
			if (adj.size()==0) {
				// have the parent who uses it pay for it
				return costCovered=0;
			}
			for (Node nn:adj) {
				nn.goParCovered();
				nn.goParNotCovered();
			}
			Collections.sort(adj);
			long ans=0;
			for (int i=0; i<adj.size(); i++) {
				ans+=(i<1?adj.get(i).costCovered:adj.get(i).costUncovered);
			}
			return costCovered=ans;
		}
		public long goParNotCovered() {
			if (costUncovered!=-1) {
				return costUncovered;
			}
			if (adj.size()==0) {
				// have the parent who uses it pay for it
				return costUncovered=value;
			}
			for (Node nn:adj) {
				nn.goParCovered();
				nn.goParNotCovered();
			}
			Collections.sort(adj);
			long ans=0;
			if (value==subtreeMax) {
				//NEED TO PAY FOR MYSELF
				ans+=value;
				for (int i=0; i<adj.size(); i++) {
					ans+=(i<1?adj.get(i).costCovered:adj.get(i).costUncovered);
				}
			}
			else {
				//I'll be covered by my kids
				for (int i=0; i<adj.size(); i++) {
					ans+=(i<0?adj.get(i).costCovered:adj.get(i).costUncovered);
				}
			}
			return costUncovered=ans;
		}
		public int compareTo(Node o) {
			//want the things that save the most by being covered to be first
			long mySave=costCovered-costUncovered;
			long oSave=o.costCovered-o.costUncovered;
			return Long.compare(mySave, oSave);
		}
		public String toString() {
			return 1+index+"";
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