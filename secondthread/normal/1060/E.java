import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class E {
	
	static long total=0;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		ArrayList<Integer>[] adj=new ArrayList[n];
		for (int i=0; i<n; i++) adj[i]=new ArrayList<>();
		for (int i=0; i<n-1; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		for (int i=0; i<n; i++) {
			if (adj[i].size()==1) {
				dfs(adj, i, -1, 0, 0, 0, 0);
				break;
			}
		}
		System.out.println(total);
	}
	
	
	//returns numEven, numOdd, sumEven, sumOdd
	static long[] dfs(ArrayList<Integer>[] adj, int node, int par, long sumEvenAbove, long sumOddAbove, int numEvenAbove, int numOddAbove) {
		total+=sumEvenAbove/2+(sumOddAbove-numOddAbove)/2+numOddAbove;
//		System.out.println("in dfs node "+node+" sumEvenAbove: "+sumEvenAbove+" sumOddAbove: "+sumOddAbove+" numEvenAbove: "+numEvenAbove+" numOddAbove: "+numOddAbove+" total: "+total);
		long numEvenDelta=0, numOddDelta=0, sumEvenDelta=0, sumOddDelta=0;
		for (int child:adj[node]) {
			if (child==par) continue;
			long newSumEvenAbove=sumOddAbove+numOddAbove;
			long newSumOddAbove=sumEvenAbove+numEvenAbove+1;
			int newNumEvenAbove=numOddAbove;
			int newNumOddAbove=numEvenAbove+1;
			long[] returned=dfs(adj, child, node, newSumEvenAbove, newSumOddAbove, newNumEvenAbove, newNumOddAbove);
			numEvenAbove+=returned[0];
			numOddAbove+=returned[1];
			sumEvenAbove+=returned[2];
			sumOddAbove+=returned[3];
			numEvenDelta+=returned[0];
			numOddDelta+=returned[1];
			sumEvenDelta+=returned[2];
			sumOddDelta+=returned[3];
		}
		long newNumEvenDelta=numOddDelta;
		long newNumOddDelta=numEvenDelta+1;
		long newSumEvenDelta=sumOddDelta+numOddDelta;
		long newSumOddDelta=sumEvenDelta+numEvenDelta+1;
		return new long[] {newNumEvenDelta, newNumOddDelta, newSumEvenDelta, newSumOddDelta};
	}
	
	static int[] bfs(ArrayList<Integer>[] adj, int from) {
		int n=adj.length;
		int[] dist=new int[n];
		Arrays.fill(dist, -1);
		ArrayDeque<Integer> bfs=new ArrayDeque<>();
		bfs.add(from);
		dist[from]=0;
		while (!bfs.isEmpty()) {
			int next=bfs.remove();
			for (int nn:adj[next]) {
				if (dist[nn]!=-1) continue;
				dist[nn]=dist[next]+1;
				bfs.add(nn);
			}
		}
		return dist;
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		
	}

}