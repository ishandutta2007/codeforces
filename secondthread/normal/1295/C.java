import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		outer:for (int tt=0; tt<T; tt++) {
			char[] s=fs.next().toCharArray(), t=fs.next().toCharArray();
			TreeSet<Integer>[] indeciesOf=new TreeSet[26];
			for (int i=0; i<26; i++) indeciesOf[i]=new TreeSet<>();
			for (int i=0; i<s.length; i++)
				indeciesOf[s[i]-'a'].add(i);
			int curIndex=s.length;
			int count=0;
			for (char c:t) {
				Integer index=indeciesOf[c-'a'].higher(curIndex);
				if (index==null) {
					curIndex=-1;
					count++;
					index=indeciesOf[c-'a'].higher(-1);
				}
				if (index==null) {
					System.out.println(-1);
					continue outer;
				}
				else {
					curIndex=index;
				}
			}
			System.out.println(count);
		}
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