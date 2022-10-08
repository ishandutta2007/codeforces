import java.util.*;
import java.io.*;

public class A {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		//find shortest path
		/*
		if any node along the shortest path contains 2 or more nodes, take that, distance never changes
		
		otherwise, all nodes on the shortest path have a subtree of size at most 1
		you are only ever going to take the deepest in any subtree
		find the distance to the deepest part of every subtree
		iterate backwards, storing the farthest one.
		dist=max(dist, distFromStartToMyDeepest+distFromOtherDeepestToFinish)
		
		*/
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt(), q=fs.nextInt();
		ArrayList<Edge>[] adj=new ArrayList[n];
		for (int i=0; i<n; i++) adj[i]=new ArrayList<>();
		for (int i=1; i<n; i++) {
			int from=fs.nextInt()-1, to=fs.nextInt()-1, cost=fs.nextInt();
			adj[from].add(new Edge(to, cost));
			adj[to].add(new Edge(from, cost));
		}
		
		long[] from0=bfs(adj, n, 0);
		long[] fromN=bfs(adj, n, n-1);
		long diam=fromN[0];
		boolean[] isOnDiam=new boolean[n];
		for (int i=0; i<n; i++) isOnDiam[i]=from0[i]+fromN[i]==diam;
		ArrayList<DiamNode> diamNodes=new ArrayList<>();
		for (int i=0; i<n; i++) if (isOnDiam[i]) diamNodes.add(new DiamNode(i, from0[i]));
		Collections.sort(diamNodes);
		
		int[] nodeIndexInDiam=new int[diamNodes.size()];
		for (int i=0; i<diamNodes.size(); i++) 
			nodeIndexInDiam[i]=diamNodes.get(i).index;
		int[] spotInDiam=new int[n];
		for (int i=0; i<nodeIndexInDiam.length; i++)
			spotInDiam[nodeIndexInDiam[i]]=i;
		
		int[] marks=new int[n];
		Arrays.fill(marks, -1);
		for (int i:nodeIndexInDiam)
			markBFS(adj, n, marks, i, isOnDiam);
		int[] numMarkedWith=new int[n];
		for (int i:marks)
			numMarkedWith[i]++;
		
		long bestOtherDiam=0;
		for (int i:numMarkedWith)
			if (i>2)
				bestOtherDiam=diam;
		
		long[] farthestTotal=new long[nodeIndexInDiam.length];
		for (int i=0; i<n; i++)
			farthestTotal[spotInDiam[marks[i]]]=Math.max(farthestTotal[spotInDiam[marks[i]]], from0[i]+fromN[i]);
		
		long[] maxDistFromStart=new long[nodeIndexInDiam.length], maxDistFromEnd=new long[nodeIndexInDiam.length];
		for (int i=0; i<nodeIndexInDiam.length; i++) {
			maxDistFromStart[i]=(farthestTotal[i]-diam)/2+from0[nodeIndexInDiam[i]];
			maxDistFromEnd[i]=(farthestTotal[i]-diam)/2+fromN[nodeIndexInDiam[i]];
		}
		int oldBest=nodeIndexInDiam.length-1;
		int secondOldBest=-1;
		if (numMarkedWith[nodeIndexInDiam[oldBest]]!=1) secondOldBest=oldBest;
		
		for (int i=oldBest-1; i>=0; i--) {
			if (numMarkedWith[nodeIndexInDiam[i]]==1) {
				if (oldBest==i+1) {
					if (secondOldBest!=-1) {
						bestOtherDiam=Math.max(bestOtherDiam, maxDistFromStart[i]+maxDistFromEnd[secondOldBest]);
					}
				}
				else {
					bestOtherDiam=Math.max(bestOtherDiam, maxDistFromStart[i]+maxDistFromEnd[oldBest]);
				}
				secondOldBest=oldBest;
				if (maxDistFromEnd[i]>maxDistFromEnd[oldBest])
					oldBest=i;
			}
			else {
				bestOtherDiam=Math.max(bestOtherDiam, maxDistFromStart[i]+maxDistFromEnd[oldBest]);
				if (maxDistFromEnd[i]>maxDistFromEnd[oldBest])
					secondOldBest=oldBest=i;
			}
		}
		
		//answer queries
		for (int i=0; i<q; i++) {
			long dist=fs.nextInt();
			out.println(Math.min(diam, dist+bestOtherDiam));
		}
		out.close();
		
		//System.out.println("On diam: "+Arrays.toString(isOnDiam));
		//System.out.println("NumMarkedWith: "+Arrays.toString(numMarkedWith));
		//System.out.println("max dist from start: "+Arrays.toString(maxDistFromStart));
		//System.out.println("max dist from end: "+Arrays.toString(maxDistFromEnd));
	}
	
	private static long[] bfs(ArrayList<Edge>[] adj, int n, int from) {
		long[] dist=new long[n];
		ArrayDeque<Integer> bfs=new ArrayDeque<>();
		Arrays.fill(dist, -1);
		dist[from]=0;
		bfs.add(from);
		while (!bfs.isEmpty()) {
			int next=bfs.remove();
			for (Edge e:adj[next]) {
				if (dist[e.to]!=-1) continue;
				dist[e.to]=dist[next]+e.cost;
				bfs.add(e.to);
			}
		}
		return dist;
	}
	
	private static void markBFS(ArrayList<Edge>[] adj, int n, int[] marks, int from, boolean[] isOnDiam) {
		ArrayDeque<Integer> bfs=new ArrayDeque<>();
		bfs.add(from);
		marks[from]=from;
		while (!bfs.isEmpty()) {
			int next=bfs.remove();
			for (Edge e:adj[next]) {
				if (isOnDiam[e.to]||marks[e.to]!=-1)
					continue;
				marks[e.to]=from;
				bfs.add(e.to);
			}
		}
	}
	
	static class DiamNode implements Comparable<DiamNode> {
		int index;
		long distFromStart;
		
		public DiamNode(int index, long distFromStart) {
			this.index=index;
			this.distFromStart=distFromStart;
		}
		
		public int compareTo(DiamNode o) {
			return Long.compare(distFromStart, o.distFromStart);
		}
	}
	
	private static class Edge {
		int to, cost;
		
		public Edge(int to, int cost) {
			this.to=to;
			this.cost=cost;
		}
	}

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
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
			String str = "";
			try {
				str = br.readLine();
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