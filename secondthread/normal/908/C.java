

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class C {

	private static double r, EPS=1e-10;
	
	public static void solve(FastScanner fs) {	
		int n=fs.nextInt();
		r=fs.nextInt();
		int[] xCoords=fs.readArray(n);
		
		ArrayList<Point> placed=new ArrayList<>();
		for (int x:xCoords) {
			double maxY=r;
			for (Point p:placed)
				maxY=Math.max(maxY, getNewY(p, x));
			placed.add(new Point(x, maxY));
		}
		for (Point p:placed) {
			System.out.printf("%.9f ", p.y);
		}
		
	}
	
	private static double getNewY(Point circleCenter, int x) {
		double dx=Math.abs(x-circleCenter.x);
		if (dx>r+r)
			return 0;
		if (dx<EPS)
			return circleCenter.y+r+r;
		double hypot=r+r;
		return circleCenter.y+Math.sqrt(hypot*hypot-(double)dx*dx);
	}

	
	static class Point {
		double x;
		double y;
		public Point(double x, double y) {
			this.x=x;
			this.y=y;
		}
 	}
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}