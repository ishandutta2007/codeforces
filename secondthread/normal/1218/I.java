import java.io.*;
import java.util.*;

public class I {

	public static void main(String[] args) {
		new I();
	}

	I() {
		FastScanner fs = new FastScanner();
		int N = fs.nextInt();
		int[][] initial = new int[N][N];
		for(int i = 0; i < N; i++) {
			String str = fs.next();
			for(int j = 0; j < N; j++) {
				initial[i][j] = str.charAt(j) - '0';
			}
		}
		
		int[][] goal = new int[N][N];
		for(int i = 0; i < N; i++) {
			String str = fs.next();
			for(int j = 0; j < N; j++) {
				goal[i][j] = str.charAt(j) - '0';
			}
		}
		
		int[] bar = new int[N];
		String forBar = fs.next();
		for(int i = 0; i < N; i++) bar[i] = forBar.charAt(i) - '0';
		
		//[0, n) = rows
		//[n, 2*n) = cols
		TwoSat sat = new TwoSat(2 * N);
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				
				
				
				if(goal[i][j] == initial[i][j]) { //shouldn't change
					boolean rowWorks = false, colWorks = false;
					if((initial[i][j] ^ bar[j]) != goal[i][j]) rowWorks = true;
					if((initial[i][j] ^ bar[i]) != goal[i][j]) colWorks = true;

//					System.out.println(i + " " + j + " Row: " + rowWorks + " Col: " + colWorks);
					
					if(rowWorks && !colWorks) {
						sat.addImpl(true, i, false, i);
					}
					else if(!rowWorks && colWorks) {
						sat.addImpl(true, j+N, false, j+N);
					}
					else if(rowWorks && colWorks) {
						sat.addImpl(true, i, true, j+N);
						sat.addImpl(true, j+N, true, i);
					}
				}
				else { //should change
					boolean rowWorks = false, colWorks = false;
					if((initial[i][j] ^ bar[j]) == goal[i][j]) rowWorks = true;
					if((initial[i][j] ^ bar[i]) == goal[i][j]) colWorks = true;
					
					if(!rowWorks && !colWorks) {
						System.out.println(-1);
						return;
					}
					
					if(rowWorks && !colWorks) {
						sat.addImpl(false, i, true, i);
					}
					else if(!rowWorks && colWorks) {
						sat.addImpl(false, j+N, true, j+N);
					}
					else {
						sat.addXor(true, i, true, j+N);
					}
				}
				
			}
		}
		
		boolean works = sat.solve();
		if(!works) {
			System.out.println(-1);
			return;
		}
		
		
		int cnt = 0;
		PrintWriter out = new PrintWriter(System.out);
		for(int i = 0; i < N; i++) {
			if(sat.getVal(i)) cnt++;
		}
		for(int i = 0; i < N; i++) {
			if(sat.getVal(i+N)) cnt++;
		}
		
		out.println(cnt);
		for(int i = 0; i < N; i++) {
			if(sat.getVal(i)) out.println("row " + i);
		}
		for(int i = 0; i < N; i++) {
			if(sat.getVal(i+N)) out.println("col " + i);
		}
		
		
		out.close();
	}
	
	class TwoSat {
		int n, n2; byte[] vals, cvals; SCC scc;
		TwoSat(int nn) {
			n2 = 2 * (n = nn); 
			scc = new SCC(n2);
			vals = new byte[n2];
		}
		void addImpl(boolean va, int a, boolean vb, int b) {
			a <<= 1; b <<= 1;
			if(!va) a++; if(!vb) b++;
			scc.add(a, b); scc.add(b ^ 1, a ^ 1);
		}
		void addXor(boolean va, int a, boolean vb, int b) {
			addImpl(!va, a, vb, b);
			addImpl(va, a, !vb, b);
		}
		boolean getVal(int v) { 
			return vals[v << 1] == 1;
		}
		boolean solve() {
			int[] map = scc.go();
			for(int i = 0; i < n; i++) if(map[2 * i] == map[2 * i + 1]) return false;
			for(int i = 0; i < n2; i++) vals[i] = (byte)-1;
			for(int i = 0; i < scc.cs; i++) {
				for(int v : scc.comp[i]) {
					if(vals[v] == -1) {
						vals[v] = 1;
					}
					vals[v ^ 1] = (byte)(vals[v] ^ 1);
				}
			}
			return true;
		}
	}
	
	class SCC {
		ArrayList<Integer>[] adj, comp;
		int n, idx, cs;
		boolean[] u;
		int[] pre, low, map;
		ArrayDeque<Integer> s;
		SCC(int nn) {
			n = nn;
			adj = new ArrayList[n];
			for(int i = 0; i < n; i++) {
				adj[i] = new ArrayList<Integer>();
			}
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
			for(int i = 0; i < n; i++) {
				if(pre[i] == 0) {
					dfs(i);
				}
			}
			return map;
		}
		void dfs(int v) {
			pre[v] = low[v] = idx++;
			s.push(v);
			u[v] = true;
			for(int to : adj[v]) {
				if(pre[to] == 0) {
					dfs(to);
					low[v] = Math.min(low[v], low[to]);
				}
				else if(u[to]) {
					low[v] = Math.min(low[v], pre[to]);
				}
			}
			if(low[v] == pre[v]) {
				int next;
				comp[cs] = new ArrayList<Integer>();
				do {
					next = s.pop();
					u[next] = false;
					map[next] = cs;
					comp[cs].add(next);
				} while(next != v);
				cs++;
			}
		}
	}
	
	class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}

}