import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class A {

	public static void main(String[] args) throws FileNotFoundException {
		FastScanner fs=new FastScanner();
		int a=fs.nextInt(), B=fs.nextInt(), c=fs.nextInt();
		
		Vec start=new Vec(fs.nextDouble(), fs.nextDouble()), end=new Vec(fs.nextDouble(), fs.nextDouble());
		double answer=start.manDist(end);
		if (a==0||B==0) {
			System.out.printf("%.11f\n", answer);
			return;
		}
		double m=-a/(double)B, b=-c/(double)B;
		Line l=new Line(m, b);
		Vec startP1=new Vec(start.x, l.evalAtX(start.x));
		Vec startP2=new Vec(l.evalAtY(start.y), start.y);
		Vec endP1=new Vec(end.x, l.evalAtX(end.x));
		Vec endP2=new Vec(l.evalAtY(end.y), end.y);
		answer=Math.min(answer, start.dist(startP1)+startP1.dist(endP1)+endP1.dist(end));
		answer=Math.min(answer, start.dist(startP2)+startP2.dist(endP1)+endP1.dist(end));
		answer=Math.min(answer, start.dist(startP1)+startP1.dist(endP2)+endP2.dist(end));
		answer=Math.min(answer, start.dist(startP2)+startP2.dist(endP2)+endP2.dist(end));
		System.out.printf("%.11f\n", answer);
	}
	
	static class Line {
		double m, b;
		public Line(double m, double b) {
			this.m=m;
			this.b=b;
		}
		
		public double evalAtX(double x) {
			return m*x+b;
		}
		
		public double evalAtY(double y) {
			return (y-b)/m;
		}
	}
	
	static class Vec {
		double x, y;
		public Vec(double x, double y) {
			this.x=x;
			this.y=y;
		}
		
		public double manDist(Vec o) {
			return Math.abs(x-o.x)+Math.abs(y-o.y);
		}
		
		public double dist(Vec o) {
			double dx=x-o.x, dy=y-o.y;
			return Math.sqrt(dx*dx+dy*dy);
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