import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

/*
4 4
1 2 1
2 3 1
3 1 2
1 4 3
3
1 1 3
1 2 4
4 1 2
 */
public class G {
	
	static long[] gcds;
	static long[] curDist;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int m=fs.nextInt();
		Node[] nodes=new Node[n];
		for (int i=0; i<n; i++) {
			nodes[i]=new Node(i);
		}
		SCC sccMagic=new SCC(n);
		for (int i=0; i<m; i++) {
			int from=fs.nextInt()-1, to=fs.nextInt()-1, cost=fs.nextInt();
			sccMagic.add(from, to);
			nodes[from].edges.add(new Edge(from, to, cost));
		}
		
		int[] map=sccMagic.go();
		Node[][] sccs=new Node[sccMagic.cs][];
		int[] sccCount=new int[sccMagic.cs];
		for (int i:map) sccCount[i]++;
		for (int i=0; i<sccMagic.cs; i++) sccs[i]=new Node[sccCount[i]];
		Arrays.fill(sccCount, 0);
		for (Node nn:nodes) {
			int scc=map[nn.id];
			nn.scc=scc;
			int pos=sccCount[scc]++;
			sccs[scc][pos]=nn;
		}
		
		curDist=new long[n];
		gcds=new long[sccs.length];
		Arrays.fill(curDist, -1);
		Arrays.fill(gcds, -1);
		boolean[] used=new boolean[n];
		for (int i=0; i<n; i++) {
			if (!used[i]) {
				dfs(i, 0, map, used, nodes);
			}
		}
		
//		System.out.println(Arrays.toString(gcds));
		int nQueries=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int qq=0; qq<nQueries; qq++) {
			int startAt=fs.nextInt()-1;
			int initialReading=fs.nextInt();
			int mod=fs.nextInt();
			long gcd=gcds[nodes[startAt].scc];
			long initialGCD=gcd;
			gcd=gcd(gcd, mod);
			int target=(mod-initialReading)%mod;
//			System.out.println("Looking for gcd: "+gcd+" target: "+target);
			if (initialGCD==-1) {
				if (target==0) {
					out.println("YES");
				}
				else {
					out.println("NO");
				}
			}
			else {
				if (target%gcd==0) {
					out.println("YES");
				}
				else {
					out.println("NO");
				}
			}
		}
		out.close();
		
	}
	
	//fill curDist and gcds with -1. Call dfs(node, 0) for each SCC
	static void dfs(int x, long curD, int[] scc, boolean[] used, Node[] nodes) {
	  curDist[x] = curD;
	  for(Edge e : nodes[x].edges) {
	    if(scc[e.to] != scc[x])continue;
	    if(curDist[e.to] != -1) {
	      long pathLength = Math.abs(curD+e.cost-curDist[e.to]);
	      if(gcds[scc[x]] == -1) gcds[scc[x]] = pathLength;
	      else gcds[scc[x]] = gcd(gcds[scc[x]], pathLength);
	    }
	    else if(!used[e.to]) dfs(e.to, curD+e.cost, scc, used, nodes);
	  }
	  //curDist[x] = -1;
	  used[x] = true;
	}
	
	static long gcd(long a, long b) {
		if (b==0) return a;
		return gcd(b, a%b);
	}

	
	static class Node {
		ArrayList<Edge> edges=new ArrayList<>();
		int id, scc;
		public Node(int id) {
			this.id=id;
		}
	}
	
	static class Edge {
		int from, to, cost;
		public Edge(int from, int to, int cost) {
			this.from=from;
			this.to=to;
			this.cost=cost;
		}
		public String toString() {
			return from+" -> "+to+" $"+cost;
		}
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	// Tarjan Strongly Connected Components O(V + E)
	static class SCC {
		ArrayList<Integer>[] adj;
		ArrayList<Integer>[] comp;
		int n;
		int idx, cs;
		boolean[] u;
		int[] pre, low, map;
		ArrayDeque<Integer> s;

		public SCC(int nn) {
			adj=new ArrayList[n=nn];
			for (int curr=0; curr<n; ++curr)
				adj[curr]=new ArrayList<>();
		}

		void add(int v1, int v2) {
			adj[v1].add(v2);
		}

		int[] go() {
			comp=new ArrayList[n];
			idx=1;
			cs=0;
			pre=new int[n];
			low=new int[n];
			map=new int[n];
			u=new boolean[n];
			s=new ArrayDeque<Integer>();
			for (int i=0; i<n; ++i)
				if (pre[i]==0)
					dfs(i);
			return map;
		}

		void dfs(int v) {
			pre[v]=low[v]=idx++;
			s.push(v);
			u[v]=true;
			for (int to:adj[v]) {
				if (pre[to]==0) {
					dfs(to);
					low[v]=Math.min(low[v], low[to]);
				} else if (u[to]) {
					low[v]=Math.min(low[v], pre[to]);
				}
			}
			if (low[v]==pre[v]) {
				int next;
				comp[cs]=new ArrayList<>();
				do {
					next=s.pop();
					u[next]=false;
					map[next]=cs;
					comp[cs].add(next);
				} while (next!=v);
				cs++;
			}
		}

		// # Make sure to call go() before calling this function.
		// Function returns a new graph such that all SCCs are
		// compressed into one node and only the edges connecting
		// two components are in the new graph.
		// nodeMapping is an integer array that will store the mapping
		// for each node in the old graph into the new graph.//$
		ArrayList[] compressSCC() {
			ArrayList<Integer>[] g=new ArrayList[cs];
			for (int i=0; i<cs; i++)
				g[i]=new ArrayList<Integer>();
			int[] added=new int[cs];
			Arrays.fill(added, -1);
			for (int i=0; i<cs; i++) {
				for (int v:comp[i]) {
					for (int to:adj[v]) {
						int mapTo=map[to];
						if (mapTo!=i&&added[mapTo]!=i) {
							g[i].add(mapTo);
							added[mapTo]=i;
						}
					}
				}
			}
			return g;
		}
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