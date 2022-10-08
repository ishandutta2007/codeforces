import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int startFloor=fs.nextInt();
		int endFloor=fs.nextInt();
		int elFloor=fs.nextInt();
		int walkTime=fs.nextInt();
		int elTime=fs.nextInt();
		int elOpenTime=fs.nextInt();
		long tWalk=Math.abs(startFloor-endFloor)*walkTime;
		long tEl=elOpenTime*3+(Math.abs(startFloor-endFloor)+Math.abs(startFloor-elFloor))*elTime;
		System.out.println(tWalk<tEl?"NO":"YES");
	}
	
	static boolean valid(int x, int y, boolean[][] board) {
		if (x<0||y<0||x>=board.length||y>=board[x].length||!board[x][y])
			return false;
		return true;
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