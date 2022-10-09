import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;
import java.util.StringTokenizer;

public class D {

	static long MOD=1_000_000_007;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Vec[] points=new Vec[n];
		for (int i=0; i<n; i++)
			points[i]=new Vec(fs.nextLong(), fs.nextLong());
		if (n<5) {
			System.out.println("YES");
			return;
		}
		
		Random r=new Random();
		boolean[] marked=new boolean[n];
		Vec[] open=new Vec[n];
		outer: for (int tt=0; tt<50; tt++) {
			int first=r.nextInt(n);
			int second=r.nextInt(n);
			while (second==first)
				second=r.nextInt(n);
			Seg toTry=new Seg(points[first], points[second]);
			for (int i=0; i<n; i++)
				marked[i]=toTry.contains(points[i]);
			int openCount=0;
			for (int i=0; i<n; i++)
				if (!marked[i])
					open[openCount++]=points[i];
			if (openCount<3) {
				System.out.println("YES");
				return;
			}
			Seg other=new Seg(open[0], open[1]);
			for (int i=0; i<n; i++)
				if (other.contains(points[i]))
					marked[i]=true;
			for (boolean b:marked)
				if (!b)
					continue outer;
			System.out.println("YES");
			return;
		}
		System.out.println("NO");
	}
	
	static class Seg {
		Vec a, b;
		public Seg(Vec a, Vec b) {
			this.a=a;
			this.b=b;
		}
		
		public boolean contains(Vec o) {
			Vec dir=b.sub(a);
			Vec oDir=o.sub(a);
			return dir.cross(oDir)==0;
		}
	}
	
	static class Vec {
		long x, y;
		public Vec(long x, long y) {
			this.x=x;
			this.y=y;
		}
		
		public Vec add(Vec o) {
			return new Vec(x+o.x, y+o.y);
		}
		
		public Vec scale(long s) {
			return new Vec(x*s, y*s);
		}
		
		public Vec sub(Vec o) {
			return add(o.scale(-1));
		}
		
		public String toString() {
			return "("+x+", "+y+")";
		}
		
		public long cross(Vec o) {
			return x*o.y-y*o.x;
		}
		
		public long dot(Vec o) {
			return x*o.x+y*o.y;
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