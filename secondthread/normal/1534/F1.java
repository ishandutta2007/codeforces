import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) throws InterruptedException {
	    Thread t=new Thread(null, null, "T", 1<<28) {
	        public void run() {
	        	F();
	        }
	    };
	    t.start();
	    t.join();
	}
	static void F() {
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
		
		SCC scc=new SCC(nNodes);
		
		int[] topInX=new int[w];
		Arrays.fill(topInX, -1);
		for (int y=h-1; y>=0; y--)
			for (int x=0; x<w; x++)
				if (board[x][y]!='.') {
//					System.out.println("At "+x+" "+y);
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
		int count=0;
		for (boolean b:hasIn) if (!b) count++;
		System.out.println(count);
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	//Tarjan Strongly Connected Components O(V + E)
	static class SCC {
	  ArrayList<Integer>[] adj;
	  ArrayList<Integer>[] comp;
	  int n;
	  int idx, cs;
	  boolean[] u;
	  int[] pre, low, map;
	  ArrayDeque<Integer> s;
	  public SCC(int nn) {
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