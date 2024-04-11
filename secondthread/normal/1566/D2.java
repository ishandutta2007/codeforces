import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
/*
1
1 2
1 2

3 2
1 1 2 2 3 3
3 3
3 4 4 1 1 1 1 1 2
2 2
1 1 2 1
4 2
50 50 50 50 3 50 50 50
4 2
6 6 6 6 2 2 9 6
2 9
1 3 3 3 3 3 1 1 3 1 3 1 1 3 3 1 1 3

 */
public class D2 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), m=fs.nextInt();
			int[][] grid=new int[n][m];
			int[] a=fs.readArray(n*m);
			int[] sorted=a.clone();
			sort(sorted);
			int index=0;
			for (int y=0; y<n; y++)
				for (int x=0; x<m; x++)
					grid[y][x]=sorted[index++];
			HashMap<Integer, PriorityQueue<Point>> map=new HashMap<>();
			for (int y=0; y<n; y++) {
				for (int x=0; x<m; x++) {
					Point p=new Point(x, y, grid[y][x]);
					if (!map.containsKey(grid[y][x]))
						map.put(grid[y][x], new PriorityQueue<>());
					map.get(grid[y][x]).add(p);
				}
			}
			
			int ans=0;
			boolean[][] used=new boolean[n][m];
			for (int i:a) {
				Point p = map.get(i).remove();
				used[p.y][p.x]=true;
				for (int x=0; x<p.x; x++) if (used[p.y][x]) ans++;
			}
			System.out.println(ans);
		}
	}
	
	static class Point implements Comparable<Point> {
		int x, y, value;
		public Point(int x, int y, int val) {
			this.x=x;
			this.y=y;
			this.value=val;
		}
		public int compareTo(Point o) {
			if (y!=o.y) {
				return Integer.compare(y, o.y);
			}
			return Integer.compare(o.x, x);
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