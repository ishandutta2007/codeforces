import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.StringTokenizer;


public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		char[][] sequences=new char[n][];
		for (int i=0; i<n; i++)
			sequences[i]=fs.next().toCharArray();
		int[] sums=new int[n];
		boolean[] valid=new boolean[n];
		for (int line=0; line<n; line++) {
			int minSum=0;
			int sum=0;
			for (char c:sequences[line]) {
				sum+=((c=='(')?1:-1);
				minSum=Math.min(minSum, sum);
			}
			sums[line]=sum;
			valid[line]=minSum==0||minSum>=sum;
//			System.out.println("for line: "+line+" valid: "+valid[line]);
		}
		HashMap<Integer, Integer> validCounts=new HashMap<>();
		int ans=0;
		for (int i=0; i<n; i++) {
			if (!valid[i]) {
				continue;
			}
			if (validCounts.containsKey(-sums[i])) {
				if (validCounts.get(-sums[i])==1) {
					validCounts.remove(-sums[i]);
				}
				else {
					validCounts.put(-sums[i], validCounts.get(-sums[i])-1);
				}
				ans++;
			}
			else {
				validCounts.put(sums[i], validCounts.getOrDefault(sums[i], 0)+1);
			}
		}
		System.out.println(ans);
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