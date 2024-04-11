import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		test:for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			Point[] points=new Point[n+1];
			for (int i=0; i<n; i++)
				points[i]=new Point(fs.nextInt(), fs.nextInt());
			points[n++]=new Point(0, 0);
			Arrays.sort(points);
			for (int i=0; i+1<n; i++) {
				if (points[i].y>points[i+1].y) {
					System.out.println("NO");
					continue test;
				}
			}
			System.out.println("YES");
			for (int i=0; i+1<n; i++) {
				for (int x=points[i].x; x<points[i+1].x; x++)
					System.out.print('R');
				for (int x=points[i].y; x<points[i+1].y; x++)
					System.out.print('U');
			}
			System.out.println();
		}
	}

	static class Point implements Comparable<Point> {
		int x, y;

		public Point(int x, int y) {
			this.x=x;
			this.y=y;
		}

		public int compareTo(Point o) {
			if (x!=o.x)
				return Integer.compare(x, o.x);
			return Integer.compare(y, o.y);
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