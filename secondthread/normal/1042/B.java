import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class B {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int[] cost=new int[1<<3];
		int oo=1_000_000_00;
		Arrays.fill(cost, oo);
		int n=fs.nextInt();
		for (int i=0; i<n; i++) {
			int c=fs.nextInt();
			String type=fs.next();
			int mask=0;
			for (char cc:type.toCharArray()) {
				if (cc=='A') mask|=1;
				if (cc=='B') mask|=2;
				if (cc=='C') mask|=4;
			}
			cost[mask]=Math.min(cost[mask], c);
		}
		int bestTotal=Integer.MAX_VALUE;
		for (int i=0; i<1<<3; i++) {
			for (int j=0; j<1<<3; j++) {
				for (int k=0; k<1<<3; k++) {
					int mask=i|j|k;
					if (mask!=7)
						continue;
					int total=0;
					if (i!=0)
						total+=cost[i];
					if (j!=0)
						total+=cost[j];
					if (k!=0)
						total+=cost[k];
					bestTotal=Math.min(bestTotal, total);
				}
			}
		}
		
		System.out.println(bestTotal<oo?bestTotal:-1);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
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
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
	
}