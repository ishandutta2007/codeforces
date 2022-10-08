import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Random;
import java.util.StringTokenizer;

public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nSets=fs.nextInt(), nVerticies=fs.nextInt();
		ArrayList<Edge> edges=new ArrayList<>();
		int[] setCost=fs.readArray(nSets);
		int[] vertexCost=fs.readArray(nVerticies);
		long totalCost=0;
		for (int color=0; color<nSets; color++) {
			int size=fs.nextInt();
			int[] elements=fs.readArray(size);
			for (int i:elements) {
				i--;
				edges.add(new Edge(nVerticies+color, i, setCost[color]+vertexCost[i]));
				totalCost+=setCost[color]+vertexCost[i];
			}
		}
		Collections.sort(edges);
		//number, set
		DisjointSet dj=new DisjointSet(nVerticies+nSets);
		for (Edge e:edges) {
			if (dj.union(e.from, e.to)) totalCost-=e.cost;
		}
		System.out.println(totalCost);
	}
	
	static class DisjointSet {
		int[] s;
		
		public DisjointSet(int n) {
			Arrays.fill(s = new int[n], -1);
		}
		
		public int find(int i) {
			return s[i] < 0 ? i : (s[i] = find(s[i]));
		}
		
		public boolean union(int a, int b) {
			if ((a = find(a)) == (b = find(b))) return false;
			if(s[a] == s[b]) s[a]--;
			if(s[a] <= s[b]) s[b] = a; else s[a] = b;
			return true;
		}
	}

	
	static class Edge implements Comparable<Edge> {
		int from, to, cost;
		public Edge(int from, int to, int cost) {
			this.from=from;
			this.to=to;
			this.cost=cost;
		}
		
		public int compareTo(Edge o) {
			return -Integer.compare(cost, o.cost);
		}
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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