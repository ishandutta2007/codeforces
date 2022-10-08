import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int h=fs.nextInt(), w=fs.nextInt();
			int[][] a=new int[w][h];
			for (int y=0; y<h; y++)
				for (int x=0; x<w; x++)
					a[x][y]=fs.nextInt();
			boolean[][] used=new boolean[w][h];
			long cost=0;
			for (int x=0; x<w; x++) {
				for (int y=0; y<h; y++) {
					if (used[x][y]) continue;
					ArrayList<Integer> parts=new ArrayList<>();
					int ox=w-1-x;
					int oy=h-1-y;
					int[] xs= {x, x, ox, ox}, ys= {y, oy, y, oy};
					for (int d=0; d<4; d++) {
						int nx=xs[d], ny=ys[d];
						if (!used[nx][ny]) {
							parts.add(a[nx][ny]);
							used[nx][ny]=true;
						}
					}
					Collections.sort(parts);
					int split=parts.get(parts.size()/2);
					for (int i:parts) cost+=Math.abs(i-split);
				}
			}
			System.out.println(cost);
		}
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
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