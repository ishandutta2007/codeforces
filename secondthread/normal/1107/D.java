import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class D {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		boolean[][] board=new boolean[n][n];
		int[] conv=new int[400];
		String hex="0123456789ABCDEF";
		for (int i=0; i<hex.length(); i++) conv[hex.charAt(i)]=i;
		for (int y=0; y<n; y++) {
			char[] line=fs.next().toCharArray();
			for (int x=0; x<n; x++) {
				board[x][y]=(conv[line[x/4]]&(1<<(3-(x&3))))!=0;
			}
		}
		
//		for (int y=0; y<n; y++) {
//			for (int x=0; x<n; x++) System.out.print(board[x][y]?1:0);
//			System.out.println();
//		}
		
		
		int[][] cs=new int[n+1][n+1];
		for (int x=1; x<=n; x++)
			for (int y=1; y<=n; y++)
				cs[x][y]=cs[x-1][y]+cs[x][y-1]-cs[x-1][y-1]+(board[x-1][y-1]?1:0);
		
		int maxK=0;
		outer: for (int toTry=1; toTry<=n; toTry++) {
			if (n%toTry!=0) continue;
			int nBlocks=n/toTry;
			for (int i=0; i<nBlocks; i++) {
				for (int j=0; j<nBlocks; j++) {
					int x=i*toTry, y=j*toTry;
					int count=rangeSum(x, y, x+toTry-1, y+toTry-1, cs);
//					System.out.println("Tried "+x+" "+y+" got count "+count+" "+toTry);
					if (count!=0 && count!=toTry*toTry) {
						continue outer;
					}
				}
			}
			maxK=toTry;
		}
		System.out.println(maxK);
	}
	
	
	static int rangeSum(int x1, int y1, int x2, int y2, int[][] cs) {
		int ans=cs[x2+1][y2+1]-cs[x2+1][y1]-cs[x1][y2+1]+cs[x1][y1];
//		System.out.println("range sum "+x1+" "+y1+" "+x2+" "+y2+" gives "+ans);
		return ans;
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