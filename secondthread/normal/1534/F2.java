import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int h=fs.nextInt(), w=fs.nextInt();
		char[][] board=new char[w][h];
		int[][] id=new int[w][h];
		int nNodes=0;
		
		for (int y=0; y<h; y++) {
			char[] line=fs.next().toCharArray();
			for (int x=0; x<w; x++) board[x][y]=line[x];
		}
		for (int x=0; x<w; x++)
			Arrays.fill(id[x], -1);
		
		for (int y=h-1; y>=0; y--)
			for (int x=0; x<w; x++)
				if (board[x][y]!='.')
					id[x][y]=nNodes++;
		
		SCCMagic scc=new SCCMagic(nNodes);
		
		int[] topInX=new int[w];
		Arrays.fill(topInX, -1);
		for (int y=h-1; y>=0; y--)
			for (int x=0; x<w; x++)
				if (board[x][y]!='.') {
					if (topInX[x]!=-1) scc.add(id[x][y], topInX[x]);
					if (x!=0 && topInX[x-1]!=-1) scc.add(id[x][y], topInX[x-1]);
					if (x!=w-1) {
						if (board[x+1][y]!='.') scc.add(id[x][y], id[x+1][y]);
						else if (topInX[x+1]!=-1) scc.add(id[x][y], topInX[x+1]);
					}
					if (y!=0 && board[x][y-1]!='.') scc.add(id[x][y], id[x][y-1]);
					
					topInX[x]=id[x][y];
				}
		int[] map=scc.go();
//		System.out.println(Arrays.toString(map));
		ArrayList<Integer>[] comp=scc.compressSCC();
		boolean[] hasIn=new boolean[comp.length];
		for (ArrayList<Integer> edges:comp)
			for (int i:edges)
				hasIn[i]=true;
		ArrayList<TopSCC> topSccs=new ArrayList<>();
		TopSCC[] allSccsByIndex=new TopSCC[comp.length];
		for (int i=0; i<hasIn.length; i++) if (!hasIn[i]) topSccs.add(allSccsByIndex[i]=new TopSCC(i));
		for (int x=0; x<w; x++) {
			for (int y=0; y<h; y++) {
				if (board[x][y]=='.') continue;
				if (!hasIn[map[id[x][y]]]) {
					//I am part of a top SCC
					TopSCC myScc=allSccsByIndex[map[id[x][y]]];
					if (myScc.y>y) {
						myScc.y=y;
						myScc.x=x;
					}
				}
			}
		}
		Collections.sort(topSccs);
		for (int i=0; i<topSccs.size(); i++) topSccs.get(i).sortedOrder=i;
		
		ArrayList<Integer>[] revComp=new ArrayList[comp.length];
		for (int i=0; i<revComp.length; i++) revComp[i]=new ArrayList<>();
		for (int i=0; i<revComp.length; i++)
			for (int j:comp[i])
				revComp[j].add(i);
		
		//bfs of SCCs in topological order
		ArrayDeque<Integer> bfs=new ArrayDeque<>();
		TopSCC[] leftmostCanReach=new TopSCC[revComp.length], rightmostCanReach=new TopSCC[revComp.length];
		int[] outDegree=new int[revComp.length];
		for (int i=0; i<revComp.length; i++) {
			outDegree[i]=revComp[i].size();
			if (outDegree[i]==0) {
				bfs.addLast(i);
			}
		}
		
		while (!bfs.isEmpty()) {
			int sccToProcess=bfs.removeFirst();
//			System.out.println("Processing SCC "+sccToProcess+" "+hasIn[sccToProcess]);
			if (!hasIn[sccToProcess]) {
				//this is a top SCC
				leftmostCanReach[sccToProcess]=rightmostCanReach[sccToProcess]=allSccsByIndex[sccToProcess];
			}
			else {
				//not a top
				for (int canReach:revComp[sccToProcess]) {
					leftmostCanReach[sccToProcess]=left(leftmostCanReach[sccToProcess], leftmostCanReach[canReach]);
					rightmostCanReach[sccToProcess]=right(rightmostCanReach[sccToProcess], rightmostCanReach[canReach]);
				}
			}
			for (int i:comp[sccToProcess]) {
				outDegree[i]--;
				if (outDegree[i]==0)
					bfs.addLast(i);
			}
		}
		
		//TODO: build all bunny ranges by the restricting nodes
		ArrayList<BunnyRange> ranges=new ArrayList<>();
		int[] reqs=fs.readArray(w);
		for (int x=0; x<w; x++) {
			if (reqs[x]==0) continue;
			for (int y=h-1; y>=0; y--) { 
				if (board[x][y]!='.') {
					reqs[x]--;
					if (reqs[x]==0) {
						//TODO: process this position as a restriction
						int myScc=map[id[x][y]];
//						System.out.println("Restriction at SCC "+myScc);
						ranges.add(new BunnyRange(leftmostCanReach[myScc].sortedOrder, rightmostCanReach[myScc].sortedOrder));
					}
				}
			}
		}
		
		Collections.sort(ranges);
//		System.out.println("Ranges: "+ranges);
		int count=0;
		int lastKill=Integer.MIN_VALUE;
		for (BunnyRange r:ranges) {
			//already dead
			if (lastKill>=r.l) continue;
			
			//otherwise, I'm the most restrictive alive, so kill my right
			count++;
			lastKill=r.r;
		}
		
		System.out.println(count);
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class BunnyRange implements Comparable<BunnyRange> {
		int l, r;
		public BunnyRange(int l, int r) {
			this.l=l;
			this.r=r;
		}
		public int compareTo(BunnyRange o) {
			return Integer.compare(r, o.r);
		}
		public String toString() {
			return "["+l+", "+r+"]";
		}
	}
	
	static class TopSCC implements Comparable<TopSCC> {
		int id;
		int x, y=Integer.MAX_VALUE;
		int sortedOrder;
		public TopSCC(int id) {
			this.id=id;
		}
		public int compareTo(TopSCC o) {
			return Integer.compare(x, o.x);
		}
	}
	
	static TopSCC left(TopSCC a, TopSCC b) {
		if (a==null) return b;
		if (b==null) return a;
		if (a.sortedOrder<b.sortedOrder) return a;
		return b;
	}
	static TopSCC right(TopSCC a, TopSCC b) {
		if (a==null) return b;
		if (b==null) return a;
		if (a.sortedOrder>b.sortedOrder) return a;
		return b;
	}
	
	//Tarjan Strongly Connected Components O(V + E)
	static class SCCMagic {
	  ArrayList<Integer>[] adj;
	  ArrayList<Integer>[] comp;
	  int n;
	  int idx, cs;
	  boolean[] u;
	  int[] pre, low, map;
	  ArrayDeque<Integer> s;
	  public SCCMagic(int nn) {
	    adj = new ArrayList[n = nn];
	    for (int curr = 0; curr < n; ++curr)
	      adj[curr] = new ArrayList<>();
	  }
	  void add(int v1, int v2) {
	    adj[v1].add(v2); 
	  }
	  int[] go() {
	  comp = new ArrayList[n];
	    idx = 1; cs = 0;
	    pre = new int[n]; low = new int[n]; map = new int[n];
	    u = new boolean[n];
	    s = new ArrayDeque<Integer>();
	    for (int i = 0; i < n; ++i)
	      if (pre[i] == 0)
	        dfs(i);
	    return map;
	  }

	  void dfs(int v) {
	    pre[v] = low[v] = idx++;
	    s.push(v);
	    u[v] = true;
	    for (int to : adj[v]) {
	      if (pre[to] == 0) {
	        dfs(to);
	        low[v] = Math.min(low[v], low[to]);
	      } else if (u[to]) {
	        low[v] = Math.min(low[v], pre[to]);
	      }
	    }
	    if (low[v] == pre[v]) {
	      int next;
	      comp[cs] = new ArrayList<>();
	      do {
	        next = s.pop();
	        u[next] = false;
	        map[next] = cs;
	        comp[cs].add(next);
	      } while (next != v);
	      cs++;
	    }
	  }

	  //# Make sure to call go() before calling this function.
	  // Function returns a new graph such that all SCCs are
	  // compressed into one node and only the edges connecting
	  // two components are in the new graph.
	  // nodeMapping is an integer array that will store the mapping
	  // for each node in the old graph into the new graph.//$
	  ArrayList[] compressSCC() {
	    ArrayList<Integer>[] g = new ArrayList[cs];
	    for(int i = 0; i < cs; i++) g[i] = new ArrayList<Integer>();
	    int[] added = new int[cs];
	    Arrays.fill(added, -1);
	    for(int i = 0; i < cs; i++) {
	      for(int v : comp[i]) {
	        for(int to : adj[v]) {
	          int mapTo = map[to];
	          if(mapTo != i && added[mapTo] != i) {
	            g[i].add(mapTo);
	            added[mapTo] = i;
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