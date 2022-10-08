import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;


public class C {

	static String answers="180\r\n" + 
			"90\r\n" + 
			"60\r\n" + 
			"45\r\n" + 
			"36\r\n" + 
			"30\r\n" + 
			"180\r\n" + 
			"45\r\n" + 
			"20\r\n" + 
			"18\r\n" + 
			"180\r\n" + 
			"15\r\n" + 
			"180\r\n" + 
			"90\r\n" + 
			"12\r\n" + 
			"45\r\n" + 
			"180\r\n" + 
			"10\r\n" + 
			"180\r\n" + 
			"9\r\n" + 
			"60\r\n" + 
			"90\r\n" + 
			"180\r\n" + 
			"15\r\n" + 
			"36\r\n" + 
			"90\r\n" + 
			"20\r\n" + 
			"45\r\n" + 
			"180\r\n" + 
			"6\r\n" + 
			"180\r\n" + 
			"45\r\n" + 
			"60\r\n" + 
			"90\r\n" + 
			"36\r\n" + 
			"5\r\n" + 
			"180\r\n" + 
			"90\r\n" + 
			"60\r\n" + 
			"9\r\n" + 
			"180\r\n" + 
			"30\r\n" + 
			"180\r\n" + 
			"45\r\n" + 
			"4\r\n" + 
			"90\r\n" + 
			"180\r\n" + 
			"15\r\n" + 
			"180\r\n" + 
			"18\r\n" + 
			"60\r\n" + 
			"45\r\n" + 
			"180\r\n" + 
			"10\r\n" + 
			"36\r\n" + 
			"45\r\n" + 
			"60\r\n" + 
			"90\r\n" + 
			"180\r\n" + 
			"3\r\n" + 
			"180\r\n" + 
			"90\r\n" + 
			"20\r\n" + 
			"45\r\n" + 
			"36\r\n" + 
			"30\r\n" + 
			"180\r\n" + 
			"45\r\n" + 
			"60\r\n" + 
			"18\r\n" + 
			"180\r\n" + 
			"5\r\n" + 
			"180\r\n" + 
			"90\r\n" + 
			"12\r\n" + 
			"45\r\n" + 
			"180\r\n" + 
			"30\r\n" + 
			"180\r\n" + 
			"9\r\n" + 
			"20\r\n" + 
			"90\r\n" + 
			"180\r\n" + 
			"15\r\n" + 
			"36\r\n" + 
			"90\r\n" + 
			"60\r\n" + 
			"45\r\n" + 
			"180\r\n" + 
			"4\r\n" + 
			"180\r\n" + 
			"45\r\n" + 
			"60\r\n" + 
			"90\r\n" + 
			"36\r\n" + 
			"15\r\n" + 
			"180\r\n" + 
			"90\r\n" + 
			"20\r\n" + 
			"9\r\n" + 
			"180\r\n" + 
			"30\r\n" + 
			"180\r\n" + 
			"45\r\n" + 
			"12\r\n" + 
			"90\r\n" + 
			"180\r\n" + 
			"5\r\n" + 
			"180\r\n" + 
			"18\r\n" + 
			"60\r\n" + 
			"45\r\n" + 
			"180\r\n" + 
			"30\r\n" + 
			"36\r\n" + 
			"45\r\n" + 
			"20\r\n" + 
			"90\r\n" + 
			"180\r\n" + 
			"6\r\n" + 
			"180\r\n" + 
			"90\r\n" + 
			"60\r\n" + 
			"45\r\n" + 
			"36\r\n" + 
			"10\r\n" + 
			"180\r\n" + 
			"45\r\n" + 
			"60\r\n" + 
			"18\r\n" + 
			"180\r\n" + 
			"15\r\n" + 
			"180\r\n" + 
			"90\r\n" + 
			"8\r\n" + 
			"45\r\n" + 
			"180\r\n" + 
			"30\r\n" + 
			"180\r\n" + 
			"9\r\n" + 
			"60\r\n" + 
			"90\r\n" + 
			"180\r\n" + 
			"10\r\n" + 
			"36\r\n" + 
			"90\r\n" + 
			"60\r\n" + 
			"45\r\n" + 
			"180\r\n" + 
			"12\r\n" + 
			"180\r\n" + 
			"45\r\n" + 
			"20\r\n" + 
			"90\r\n" + 
			"36\r\n" + 
			"15\r\n" + 
			"180\r\n" + 
			"90\r\n" + 
			"60\r\n" + 
			"18\r\n" + 
			"180\r\n" + 
			"20\r\n" + 
			"180\r\n" + 
			"45\r\n" + 
			"24\r\n" + 
			"90\r\n" + 
			"180\r\n" + 
			"30\r\n" + 
			"180\r\n" + 
			"36\r\n" + 
			"40\r\n" + 
			"45\r\n" + 
			"180\r\n" + 
			"60\r\n" + 
			"72\r\n" + 
			"90\r\n" + 
			"120\r\n" + 
			"180\r\n" + 
			"360\r\n" + 
			"";
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=1; tt<=T; tt++) {
			System.out.println(answers.split("\r\n")[fs.nextInt()-1]);
			/*if (tt==90) {
				System.out.println("at 90: ");
			}
			boolean found=false;
			for (int i=3; i<=360; i++) {
				if (check(i, tt)) {
					System.out.println(i);
					found=true;
					break;
				}
			}
			if (!found) {
				System.out.println("???");
			}*/
//			int angle=fs.nextInt();
//			if (angle==179) {
//				System.out.println(360);
//				continue;
//			}
//			if (angle>90) {
//				System.out.println(180);
//				continue;
//			}
//			long gcd=gcd(angle, 180);
//			System.out.println(180/gcd);
		}
	}
	
	static long gcd(long a, long b) {
		return b==0?a:gcd(b, a%b);
	}
	
	static boolean check(int n, int degrees) {
//		System.out.println("Trying n: "+n);
		Vec[] points=new Vec[n];
		for (int i=0; i<n; i++) {
			points[i]=new Vec(1, 0).rotate(Math.PI*2*i/n);
		}
		double EPS=1e-6;
		for (int i=1; i<n; i++) {
			for (int j=1; j<n; j++) {
				Vec v1=points[i].sub(points[0]);
				Vec v2=points[j].sub(points[0]);
				double angleBetween=Math.toDegrees(Math.acos(v1.dot(v2)/(v1.mag()*v2.mag())));
				angleBetween=(angleBetween%360+360)%360;
//				if (n==180)System.out.println("\t for points "+points[0]+" "+points[i]+" "+points[j]+" got "+angleBetween);
				if (Math.abs(angleBetween-degrees)<EPS) {
					return true;
				}
			}
		}
		return false;
	}
	
	
	static class FastScanner {
		StringTokenizer st = new StringTokenizer("");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		public String next() {
			while (!st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

	}
	
	static class Vec {
		static final double EPS=1e-6;
		double x, y;
		
		public Vec(double x, double y) {
			this.x=x;
			this.y=y;
		}
		
		public Vec add(Vec o) {
			return new Vec(x+o.x, y+o.y);
		}
		
		public Vec scale(double s) {
			return new Vec(x*s, y*s);
		}
		
		public Vec sub(Vec o) {
			return add(o.scale(-1));
		}
		
		public double dot(Vec o) {
			return x*o.x+y*o.y;
		}
		
		public double cross(Vec o) {
			return x*o.y-y*o.x;
		}
		
		public double mag2() {
			return dot(this);
		}
		
		public double mag() {
			return Math.sqrt(mag2());
		}
		
		public Vec unit() {
			return scale(1/mag());
		}
		
		public Vec rot90() {
			return new Vec(y, -x);
		}
		
		public Vec rotate(double theta) {
			double PI=Math.PI;
			double newX=x*Math.cos(theta)+y*Math.cos(PI/2+theta);
			double newY=x*Math.sin(theta)+y*Math.sin(PI/2+theta);
			return new Vec(newX, newY);
		}
		
		//angle between 0 and 2PI
		public double angle() {
			return (Math.atan2(y, x)+2*Math.PI)%(2*Math.PI);
		}
		
		public String toString() {
			DecimalFormat df=new DecimalFormat("#.##");
			return "("+df.format(x)+", "+df.format(y)+")";
		}
		
		
	}

	
}