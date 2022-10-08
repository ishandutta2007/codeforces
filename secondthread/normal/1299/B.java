import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*
 */
public class B {

	static long[] xCoords, yCoords;

	public static void main(String[] args) {
		FastScanner fs = new FastScanner();
		int n=fs.nextInt();
		VecL[] points=new VecL[n];
		for (int i=0; i<n; i++) points[i]=new VecL(fs.nextLong(), fs.nextLong());
		if (n%2!=0) {
			System.out.println("NO");
			return;
		}
		int p1=0, p2=n/2;
		while (p1<n) {
			VecL d1=points[(p1+1)%n].sub(points[p1]);
			VecL d2=points[(p2+1)%n].sub(points[p2]);
			if (d1.cross(d2)!=0) {
				System.out.println("NO");
				return;
			}
			if (-d1.dot(d2)!=d1.mag2()) {
				System.out.println("NO");
				return;
			}
			p1=p1+1;
			p2=(p2+1)%n;
		}
		
		System.out.println("YES");
	}

	static class VecL implements Comparable<VecL> {
		long x, y;

		public VecL(long x, long y) {
			this.x = x;
			this.y = y;
		}

		public VecL add(VecL o) {
			return new VecL(x + o.x, y + o.y);
		}

		public VecL sub(VecL o) {
			return new VecL(x - o.x, y - o.y);
		}

		public VecL scale(long s) {
			return new VecL(x * s, y * s);
		}

		public long dot(VecL o) {
			return x * o.x + y * o.y;
		}

		public long cross(VecL o) {
			return x * o.y - y * o.x;
		}

		public long mag2() {
			return dot(this);
		}

		public VecL rot90() {
			return new VecL(-y, x);
		}

		public VecL rot270() {
			return new VecL(y, -x);
		}

		public String toString() {
			return "(" + x + ", " + y + ")";
		}

		public int hashCode() {
			return Long.hashCode(x << 13 ^ (y * 57));
		}

		public boolean equals(Object oo) {
			VecL o = (VecL) oo;
			return x == o.x && y == o.y;
		}

		public int compareTo(VecL o) {
			if (x != o.x)
				return Long.compare(x, o.x);
			return Long.compare(y, o.y);
		}

		// origin->q1, axes-> quadrant in ccw direction
		public int quadrant() {
			if (x == 0 || y == 0)
				if (y == 0)
					if (x >= 0)
						return 1;
					else
						return 3;
				else if (y >= 0)
					return 2;
				else
					return 4;
			if (x > 0)
				if (y > 0)
					return 1;
				else
					return 4;
			else if (y > 0)
				return 2;
			else
				return 3;
		}

		public int radialCompare(VecL o) {
			if (quadrant() == o.quadrant())
				return -Long.signum(cross(o));
			return Integer.compare(quadrant(), o.quadrant());
		}

	}

	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			while (!st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

}