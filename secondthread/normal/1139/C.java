import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class _548C {
	
	static final long mod=1_000_000_007;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		long ways=fastPow(n, k);
		ArrayList<Integer>[] adj=new ArrayList[n];
		for (int i=0; i<n; i++) adj[i]=new ArrayList<>();
		boolean[] seen=new boolean[n];
		ArrayList<Integer> sizes=new ArrayList<>();
		for (int i=1; i<n; i++) {
			int a=fs.nextInt()-1, b=fs.nextInt()-1, c=fs.nextInt();
			if (c==1) continue;
			adj[a].add(b);
			adj[b].add(a);
		}
		for (int base=0; base<n; base++) {
			if (seen[base]) continue;
			ArrayDeque<Integer> bfs=new ArrayDeque<>();
			bfs.add(base);
			seen[base]=true;
			int size=1;
			while (!bfs.isEmpty()) {
				int next=bfs.remove();
				for (int i:adj[next]) {
					if (seen[i])continue;
					seen[i]=true;
					size++;
					bfs.add(i);
				}
			}
			sizes.add(size);
		}
		for (int i:sizes) {
			ways=((ways-fastPow(i, k))%mod+mod)%mod;
		}
		System.out.println(ways);
	}
	
	static long fastPow(int base, int pow) {
		if (pow==0)
			return 1;
		long half=fastPow(base, pow/2);
		if (pow%2==0)
			return half*half%mod;
		return half*half%mod*base%mod;
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
	}

}