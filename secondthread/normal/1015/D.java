import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class D {

	static ArrayDeque<Integer> moveTo=new ArrayDeque<>();
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int moves=fs.nextInt();
		long totalDist=fs.nextLong();
		PrintWriter out=new PrintWriter(System.out);
		if (go(n, moves, totalDist, 1)) {
			out.println("YES");
			while (!moveTo.isEmpty()) {
				out.print(moveTo.remove()+" ");
			}
			out.println();
		}
		else {
			out.println("NO");
		}
		out.close();
	}
	
	static boolean go(int n, int moves, long totalDist, int pos) {
		if (moves==0) {
			return totalDist==0;
		}
		if (totalDist<moves) {
			return false;
		}
		
		if (totalDist>=(n-1)+(moves-1)) {
			if (pos==1) {
				moveTo.add(n);
				return go(n, moves-1, totalDist-(n-1), n);
			}
			else {
				moveTo.add(1);
				return go(n, moves-1, totalDist-(n-1), 1);
			}
		}
		else {
			if (totalDist==moves) {
				if (pos==1) {
					moveTo.add(2);
					return go(n, moves-1, totalDist-1, 2);
				}
				else {
					moveTo.add(pos-1);
					return go(n, moves-1, totalDist-1, pos-1);
				}
			}
			else {
				int nowDist=(int) (totalDist-(moves-1));
				if (pos==1) {
					moveTo.add(nowDist+1);
					return go(n, moves-1, totalDist-(nowDist), nowDist+1);
				}
				else {
					moveTo.add(n-nowDist);
					return go(n, moves-1, totalDist-(nowDist), n-nowDist);
				}
			}
		}
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