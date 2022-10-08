import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;
/*

Every space has a cost c_i
Travel to j by flight

Min(c_i + (i-j)^2)
Min( [c_i + i^2] (-2i)*j) + j^2



 */
public class E2 {

	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt(), nRoads=fs.nextInt(), nFlights=fs.nextInt();
		ArrayList<Edge>[] graph=new ArrayList[n];
		for (int i=0; i<n; i++) graph[i]=new ArrayList<>();
		for (int i=0; i<nRoads; i++) {
			int from=fs.nextInt()-1, to=fs.nextInt()-1, cost=fs.nextInt();
			graph[from].add(new Edge(from, to, cost));
			graph[to].add(new Edge(to, from, cost));
		}
		long[] distanceTo=new long[n];
		Arrays.fill(distanceTo, Long.MAX_VALUE/2);
		distanceTo[0]=0;
		dij(distanceTo, graph, n);
		for (int i=0; i<nFlights; i++) {
			convexHull(distanceTo, n);
			dij(distanceTo, graph, n);
		}
		for (int i=0; i<n; i++) {
			out.print(distanceTo[i]+" ");
		}
		out.println();
		out.close();
	}
	
	static void dij(long[] distanceTo, ArrayList<Edge>[] graph, int n) {
		PriorityQueue<State> states=new PriorityQueue<>();
		for (int i=0; i<n; i++)
			states.add(new State(i, distanceTo[i]));
		while (!states.isEmpty()) {
			State next=states.remove();
			if (distanceTo[next.node]!=next.cost) continue;
			for (Edge e:graph[next.node]) {
				long newDistance=next.cost+e.cost;
				if (distanceTo[e.to]>newDistance) {
					distanceTo[e.to]=newDistance;
					states.add(new State(e.to, distanceTo[e.to]));
				}
			}
		}
	}
	
	static void convexHull(long[] distanceTo, int n) {
		long[] minCostToFlyTo=new long[n];
//		Every space has a cost c_i
//		Travel to j by flight
//
//		Min(c_i + (i-j)^2)
//		Min( [c_i + i^2] (-2i)*j) + j^2

		ConvexHullLinear dp=new ConvexHullLinear(n, -1, 1, false);
		for (int to=0; to<n; to++) {
			//add my line
			long b=distanceTo[to] + to*(long)to;
			long m=-2*to;
			dp.add(m, b);
		}
		for (int i=0; i<n; i++) {
			minCostToFlyTo[i]=dp.query(i) + i*(long)i;
		}
		for (int i=0; i<n; i++) {
			distanceTo[i]=Math.min(distanceTo[i], minCostToFlyTo[i]);
		}
	}
	
	static class State implements Comparable<State> {
		int node;
		long cost;
		public State(int node, long cost) {
			this.node=node;
			this.cost=cost;
		}
		public int compareTo(State o) {
			return Long.compare(cost, o.cost);
		}
	}
	
	static class Edge {
		int from, to, cost;
		public Edge(int from, int to, int cost) {
			this.from=from;
			this.to=to;
			this.cost=cost;
		}
	}
	
	/*Linear version of Convex hull optimization. Written by Joshua Fair
	Constructor(a, b, c, d):
	a = max number of lines that will be added
	b = 1 if lines are added in increasing slope and -1 if added in decreasing order
	c =
	    -1 if points are queried in order from large X to small X
	    0 if the query points are in no specific order
	    1 if the points are queries in order from small X to large X
	d = true if the queries are max, and false if the queries are min
	!!! If you add lines in one order and query points in the opposite order, it will only be linear if all lines are 
	added before any points are queried !!!
	*/
	static class ConvexHullLinear {
	    boolean upd, isMin;
	    int type, inc, s, p;
	    long[] ms,bs;
	    public ConvexHullLinear(int numLines, int ii, int tt, boolean mm) {
	        s = -1;
	        p = 0;
	        ms = new long[numLines];
	        bs = new long[numLines];
	        inc = ii;
	        type = tt;
	        isMin = !mm;
	        upd = false;
	        if(isMin) inc = -inc;
	    }
	    public void add(long m, long b) {
	        if(isMin) { m=-m; b=-b; }
	        if(s >= 0 && ms[s] == m && b <= bs[s]) return;
	        upd = true;
	        s++;
	        ms[s] = m;
	        bs[s] = b;
	        while((s > 0 && ms[s] == ms[s-1] && bs[s] >= bs[s-1])
	            || (s-2 >= 0 && bad(s-2,s-1,s))) {
	            ms[s-1] = m;
	            bs[s-1] = b;
	            s--;
	        }
	    }
	    public long query(long x) {
	        return wrapper(x) * (isMin ? -1 : 1);
	    }
	    public long wrapper(long x) {
	        if(p > s || (upd && type*inc < 0)) p = s;
	        upd = false;
	        if(type == 0) { //Binary search in log(n)
	            int lo = 0;
	            int hi = s;
	            while(lo < hi) {
	                int mid = lo + (hi-lo)/2;
	                if(eval(mid,x) < eval(mid+1,x)) lo = mid+1;
	                else hi = mid;
	            }
	            return eval(lo,x);
	        }
	        else if(type*inc < 0) { //search from p -> 0
	            while(p >= 1 && eval(p,x) < eval(p-1,x)) p--;
	            return eval(p, x);
	        }
	        else { //search from p -> s
	            while(p < s && eval(p,x) < eval(p+1,x)) p++;
	            return eval(p, x);
	        }
	    }
	    public boolean bad(int l1, int l2, int l3) {
	        if(inc == 1) return intersect(l2,l3) <= intersect(l1,l2);
	        return intersect(l2,l3) >= intersect(l1,l2);
	    }
	    public double intersect(int l1, int l2) {
	        return (double)(bs[l2]-bs[l1])/(double)(ms[l1]-ms[l2]);
	    }
	    public long eval(int l1, long x) { 
	        return ms[l1]*x + bs[l1]; 
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