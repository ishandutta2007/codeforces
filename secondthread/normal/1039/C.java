import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class _507C {

	static long mod=1_000_000_007;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), m=fs.nextInt(), k=fs.nextInt();
		HashMap<Long, ArrayList<Edge>> map=new HashMap<>();
		long[] values=new long[n];
		for (int i=0; i<values.length; i++) values[i]=fs.nextLong();
		for (int i=0; i<m; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			if (!map.containsKey(values[a]^values[b])) map.put(values[a]^values[b], new ArrayList<>());
			map.get(values[a]^values[b]).add(new Edge(a, b));
		}
		long freeMoves=(1l<<k)-map.size();
		long choices=twoPow(n);
		long total=freeMoves%mod*choices%mod;
		RestorableDisjointSet dj=new RestorableDisjointSet(n);
		for (long val:map.keySet()) {
			ArrayList<Edge> edges=map.get(val);
			dj.save();
			int joins=0;
			for (Edge e:edges) {
				if (dj.find(e.from)==dj.find(e.to)) continue;
				dj.union(e.from, e.to);
				joins++;
			}
			dj.restore();
			total=(total+twoPow(n-joins))%mod;
		}
		System.out.println(total);
	}
	
	static long twoPow(long exp) {
		if (exp==0) return 1;
		long half=twoPow(exp/2);
		if (exp%2==0) return half*half%mod;
		return half*half%mod*2%mod;
	}
	

	static class Edge {
		int from, to;
		public Edge(int from, int to) {
			this.from=from;
			this.to=to;
		}
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		String next() {
			while (!st.hasMoreElements())
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
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	// Disjoint set but can set a save point and restore to it
	// Do not save twice in a row without restoring first
	static class RestorableDisjointSet {
		int[] s, s2, vs;
		int curv;
		public RestorableDisjointSet(int n) {
			s=new int[n];
			s2=new int[n];
			vs=new int[n];
			Arrays.fill(s, -1);
			curv=-1;
		}
		void save() {
			curv=1-curv;
		}
		void restore() {
			curv*=-1;
		}
		int find(int i) {
			return get(i)<0 ? i : set(i, find(get(i)));
		}
		int get(int i) {
			return vs[i]==curv ? s2[i] : s[i];
		}
		int set(int i, int v) {
			if (curv<0)
				return s[i]=v;
			vs[i]=curv;
			return s2[i]=v;
		}
		void union(int a, int b) {
			if (get(a=find(a))==get(b=find(b)))
				set(a, get(a)-1);
			if (get(a)<=get(b))
				set(b, a);
			else
				set(a, b);
		}
	}

}