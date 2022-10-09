
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {

	public static void solve(FastScanner fs) {
		//TODO: stack trick!
		int T=fs.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for (int tt=0; tt<T; tt++) {
			int nNodes=fs.nextInt(), nEdges=fs.nextInt();
			int fair1=fs.nextInt()-1, fair2=fs.nextInt()-1;
			Node[] nodes=new Node[nNodes];
			MagicComponents magic=new MagicComponents(nNodes);
			for (int i=0; i<nNodes; i++) nodes[i]=new Node();
			for (int i=0; i<nEdges; i++) {
				int a=fs.nextInt()-1, b=fs.nextInt()-1;
				nodes[a].adj.add(nodes[b]);
				nodes[b].adj.add(nodes[a]);
				magic.addEdge(a, b);
			}
			magic.run();
			for (int i:magic.cuts)
				nodes[i].articulation=true;
			if (!nodes[fair1].articulation || !nodes[fair2].articulation) {
				out.println(0);
				continue;
			}
			nodes[fair1].bfsOut(nodes);
			long aCount=0, bCount=0;
			for (Node nn:nodes) {
//				System.out.println("Node bfsNum: "+nn.bfsNum);
				if (nn.bfsNum!=nodes[fair1].bfsNum && nn.bfsNum != nodes[fair2].bfsNum) {
					aCount++;
				}
			}
			nodes[fair2].bfsOut(nodes);
			for (Node nn:nodes) {
				if (nn.bfsNum!=nodes[fair1].bfsNum && nn.bfsNum != nodes[fair2].bfsNum) {
					bCount++;
				}
			}
//			System.out.println(aCount+" "+bCount);
			out.println(aCount*bCount);
		}
		out.close();
	}

	static class Node {
		ArrayList<Node> adj=new ArrayList<>();
		int index;
		boolean articulation=false;
		int bfsNum=-1;
		
		void bfsOut(Node[] nodes) {
			for (Node n:nodes) n.bfsNum=-1;
			bfsNum=0;
			int counter=1;
			for (Node n:adj) {
				if (n.bfsNum!=-1) continue;
				ArrayDeque<Node> bfs=new ArrayDeque<>();
				bfs.add(n);
				n.bfsNum=counter;
				while (!bfs.isEmpty()) {
					Node next=bfs.remove();
					for (Node nn:next.adj) {
						if (nn.bfsNum==-1) {
							nn.bfsNum=counter;
							bfs.add(nn);
						}
					}
				}
				counter++;
			}
		}
	}
	
	// Bi-connected Components: Remove any edge, still connected
	// Two-Connected Components: Remove any vertex, still connected
	// Articulation or cut points
	static class Edge {
		int u, v, id;
		public Edge(int U, int V, int i) {
			u=U;
			v=V;
			id=i;
		}
	}
	static class MagicComponents { // Stack Trick!
		int num, n, edges;
		int[] dfsNum, low, vis;
		ArrayList<Integer> cuts;
		ArrayList<Edge> bridges, adj[];
		ArrayList<ArrayList<Edge>> bccs;
		ArrayDeque<Edge> eStack;

		MagicComponents(int N) {
			adj=new ArrayList[n=N];
			for (int i=0; i<n; i++)
				adj[i]=new ArrayList<>();
			edges=0;
		}

		void addEdge(int u, int v) {
			adj[u].add(new Edge(u, v, edges));
			adj[v].add(new Edge(v, u, edges++));
		}

		void run() {
			vis=new int[n];
			dfsNum=new int[n];
			low=new int[n];
			bridges=new ArrayList<>();
			cuts=new ArrayList<>();
			bccs=new ArrayList<>();
			eStack=new ArrayDeque<>();
			num=0;

			for (int i=0; i<n; i++) {
				if (vis[i]!=0)
					continue;
				dfs(i, -1);
			}
		}

		void dfs(int node, int par) {
			dfsNum[node]=low[node]=num++;
			vis[node]=1;
			int nChild=0;
			for (Edge e:adj[node]) {
				if (e.v==par)
					continue;
				if (vis[e.v]==0) {
					++nChild;
					eStack.push(e);
					dfs(e.v, node);
					low[node]=Math.min(low[node], low[e.v]);
					if (low[e.v]>=dfsNum[node]) {
						if (dfsNum[node]>0||nChild>1)
							cuts.add(node);
						if (low[e.v]>dfsNum[node]) {
							bridges.add(e);
							pop(node);
						}
						else
							pop(node);
					}
				}
				else if (vis[e.v]==1) {
					low[node]=Math.min(low[node], dfsNum[e.v]);
					eStack.push(e);
				}
			}
			vis[node]=2;
		}

		void pop(int u) {
			ArrayList<Edge> list=new ArrayList<>();
			for (;;) {
				Edge e=eStack.pop();
				list.add(e);
				if (e.u==u)
					break;
			}
			bccs.add(list);
		}

		// # Make sure to call run before calling this function.
		// Function returns a new graph such that all two connected
		// components are compressed into one node and all bridges
		// in the previous graph are the only edges connecting the
		// components in the new tree.
		// map is an integer array that will store the mapping
		// for each node in the old graph into the new graph. //$
		MagicComponents componentTree(int[] map) {
			boolean[] vis=new boolean[edges];
			for (Edge e:bridges)
				vis[e.id]=true;

			int numComp=0;
			Arrays.fill(map, -1);
			for (int i=0; i<n; ++i) {
				if (map[i]==-1) {
					ArrayDeque<Integer> q=new ArrayDeque<>();
					q.add(i);
					map[i]=numComp;
					while (!q.isEmpty()) {
						int node=q.poll();
						for (Edge e:adj[node]) {
							if (!vis[e.id]&&map[e.v]==-1) {
								vis[e.id]=true;
								map[e.v]=numComp;
								q.add(e.v);
							}
						}
					}
					++numComp;
				}
			}

			MagicComponents g=new MagicComponents(numComp);
			Arrays.fill(vis, false);
			for (int i=0; i<n; ++i) {
				for (Edge e:adj[i]) {
					if (!vis[e.id]&&map[e.v]<map[e.u]) {
						vis[e.id]=true;
						g.addEdge(map[e.v], map[e.u]);
					}
				}
			}

			return g;
		}

		// # Make sure to call run before calling this function.
		// Function returns a new graph such that all biconnected
		// components are compressed into one node. Cut nodes will
		// be in multiple components, so these nodes will also have
		// their own component by themselves. Edges in the graph
		// represent components to articulation points
		// map is an integer array that will store the mapping
		// for each node in the old graph into the new graph.
		// Cut points to their special component, and every other node
		// to their specific component. //$
		MagicComponents bccTree(int[] map) {
			int[] cut=new int[n];
			Arrays.fill(cut, -1);
			int size=bccs.size();
			for (int i:cuts)
				map[i]=cut[i]=size++;
			MagicComponents g=new MagicComponents(size);
			int[] used=new int[n];
			for (int i=0; i<bccs.size(); ++i) {
				ArrayList<Edge> list=bccs.get(i);
				for (Edge e:list) {
					for (int node:new int[]{e.u, e.v}) {
						if (used[node]!=i+1) {
							used[node]=i+1;
							if (cut[node]!=-1)
								g.addEdge(i, cut[node]);
							else
								map[node]=i;
						}
					}
				}
			}
			return g;
		}
	}

	public B() {
		FastScanner scanner=new FastScanner(System.in);
		solve(scanner);
	}
	
	public static void main(String[] args) throws InterruptedException {
		Thread t=new Thread(null, null, "T", 1<<28) {
			public void run() {
				new B();
			}
		};
		t.start();
		t.join();
	}

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br=new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st==null||!st.hasMoreElements()) {
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str="";
			try {
				str=br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}