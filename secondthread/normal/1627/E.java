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
import java.util.TreeSet;

/*

 */
public class E {

	static TreeSet<Node> allNodes=new TreeSet<>();
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			allNodes.clear();
			int h=fs.nextInt(), w=fs.nextInt(), nLadders=fs.nextInt();
			int[] moveCostAtX=fs.readArray(h);
			Node start=get(0, 0);
//			Node[] ends=new Node[w];
//			for (int i=0; i<w; i++) ends[i]=get(h-1, i);
			Node end=get(h-1, w-1);
			for (int i=0; i<nLadders; i++) {
				Ladder l=new Ladder(fs.nextInt()-1, fs.nextInt()-1, fs.nextInt()-1, fs.nextInt()-1, fs.nextInt());
				Node from=get(l.low, l.sx), to=get(l.hi, l.ex);
				from.edges.add(new Edge(from, to, -l.health));
			}
			for (Node nn:allNodes) {
//				if (nn.floor==h-1) break;
				Node next=allNodes.higher(nn);
				if (next==null || next.floor!=nn.floor) continue;
				nn.edges.add(new Edge(nn, next, moveCostAtX[nn.floor]*(long)(next.x-nn.x)));
				next.edges.add(new Edge(next, nn, moveCostAtX[nn.floor]*(long)(next.x-nn.x)));
			}
			
			PriorityQueue<State> pq=new PriorityQueue<>();
			pq.add(new State(start, 0));
			start.dist=0;
			while (!pq.isEmpty()) {
				State curState=pq.remove();
				if (curState.cost!=curState.at.dist) continue;
				for (Edge ee:curState.at.edges) {
					long newCost=ee.cost+curState.cost;
					if (newCost<ee.to.dist) {
						ee.to.dist=newCost;
						pq.add(new State(ee.to, newCost));
					}
				}
			}
			long ans=end.dist;
//			for (Node nn:ends) {
//				ans=Math.min(ans, nn.dist);
//			}
			System.out.println(ans>=Long.MAX_VALUE/2?"NO ESCAPE":(""+ans));
		}
	}
	
	static Node get(int floor, int x) {
		Node test=new Node(floor, x);
		Node ceil=allNodes.ceiling(test);
		if (ceil!=null && ceil.x==test.x&& ceil.floor==test.floor) return ceil;
		allNodes.add(test);
		return test;
	}
	static Node getNextOnFloor(int floor, int x) {
		Node test=new Node(floor, x);
		Node ceil=allNodes.ceiling(test);
		if (ceil==null) return null;
		if (ceil.floor==test.floor) return ceil;
		return null;
	}
	
	
	static class Node implements Comparable<Node> {
		int floor;
		int x;
		long dist=Long.MAX_VALUE/2;
		ArrayList<Edge> edges=new ArrayList<>();
		public Node(int floor, int x) {
			this.floor=floor;
			this.x=x;
		}
		public int compareTo(Node o) {
			if (floor!=o.floor) return Integer.compare(floor, o.floor);
			return Integer.compare(x, o.x);
		}
	}
	
	static class Edge {
		Node from;
		Node to;
		long cost;
		public Edge(Node from, Node to, long cost) {
			this.from=from;
			this.to=to;
			this.cost=cost;
		}
	}
	
	static class State implements Comparable<State> {
		Node at;
		long cost;
		public State(Node at, long cost) {
			this.at=at;
			this.cost=cost;
		}
		public int compareTo(State o) {
			if (at.floor!=o.at.floor) return Integer.compare(at.floor, o.at.floor);
			return Long.compare(cost, o.cost);
		}
	}
	
	static class Ladder {
		int low, hi, health;
		int sx, ex;
		public Ladder(int low, int sx, int high, int ex, int health) {
			this.low=low;
			this.hi=high;
			this.health=health;
			this.sx=sx;
			this.ex=ex;	
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