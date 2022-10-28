import java.io.*;
import java.util.*;

public class R290qCFoxAndDinner {

	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = in.nextInt();
		
		int a[] = new int[n + 1];
		for(int i=1;i<=n;i++)
			a[i] = in.nextInt();
		
		int idx[] = new int[n + 1];
		int rev[] = new int[n + 1];
		int even = 0,odd = 0;
		for(int i=1;i<=n;i++)
			if(a[i] % 2 == 0)
				idx[i] = ++even;
			else
				idx[i] = ++odd;
		
		for(int i=1;i<=n;i++)
			if(a[i] % 2 == 1)
				idx[i] += even;
		
		for(int i=1;i<=n;i++)
			rev[idx[i]] = i;
		
		boolean prime[] = sieve(40000);
		
		if(even == odd){
			
			int nodes = 1 + even + odd + 1;
			int source = 0,sink = nodes - 1;
			
			int graph[][] = new int[nodes][nodes];
			int cap[][] = new int[nodes][nodes];
			
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if( a[i] % 2 == 0 && a[j] % 2 != 0 && prime[a[i] + a[j]])
						graph[idx[i]][idx[j]] = 1;
			
			for(int i=1;i<=n;i++)
				if(a[i] % 2 == 0)
					graph[source][idx[i]] = 2;
				else
					graph[idx[i]][sink] = 2;
		
			
			for(int i=0;i<nodes;i++)
				for(int j=0;j<nodes;j++)
					cap[i][j] = graph[i][j];
			
			int ans = maxFlow(cap,source,sink);
			
		//	System.out.println(Arrays.deepToString(graph));
		//	System.out.println(Arrays.deepToString(cap));
			
			if(ans == 2*even){
				ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
				boolean done[] = new boolean[n + 1];
				
				for(int i=1;i<=n;i++){
					if(!done[idx[i]]){
						ArrayList<Integer> path = new ArrayList<Integer>();
						dfs(idx[i],path,done,cap,graph,rev,n);
						list.add(path);
					}
				}
				
				w.println(list.size());
				for(ArrayList<Integer> path : list){
					w.print(path.size());
					for(int x : path)
						w.print(" " + x);
					w.println();
				}
			}
			
			else
				w.println("Impossible");
			
		}
		else
			w.println("Impossible");
		
		w.close();
	}
	
	public static void dfs(int curr,ArrayList<Integer> path,boolean vis[],int cap[][],int graph[][],int rev[],int n){
		if(vis[curr])
			return;
		vis[curr] = true;
		path.add(rev[curr]);
		for(int i=1;i<=n;i++){
			if(graph[curr][i] > 0 && cap[curr][i] == 0)
				dfs(i,path,vis,cap,graph,rev,n);
			if(graph[i][curr] > 0 && cap[i][curr] == 0)
				dfs(i,path,vis,cap,graph,rev,n);
		}
	}
	
	public static int maxFlow(int[][] cap, int s, int t) {
		for (int flow = 0;;) {
			int df = findPath(cap, new boolean[cap.length], s, t, Integer.MAX_VALUE);
			if (df == 0)	return flow;
			flow += df;
		}
	}

	static int findPath(int[][] cap, boolean[] vis, int u, int t, int f) {
		if (u == t)
			return f;
		vis[u] = true;
		for (int v = 0; v < vis.length; v++)
			if (!vis[v] && cap[u][v] > 0) {
				int df = findPath(cap, vis, v, t, Math.min(f, cap[u][v]));
				if (df > 0) {
					cap[u][v] -= df;
					cap[v][u] += df;
					return df;
				}
			}
		return 0;
	}

	
	public static boolean[] sieve(int n){
		boolean prime[] = new boolean[n+1];
		Arrays.fill(prime,true);
		prime[0] = prime[1] = false;
		
		for(int i=2;i*i<=n;i++)
			if(prime[i]) 
				for(int k=i*i;k<=n;k+=i) 
					prime[k] = false;
		
		return prime;
	}
	
	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar;
		private int snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			int res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}

			long res = 0;

			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));

			return res * sgn;
		}
		
		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}