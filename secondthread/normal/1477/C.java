import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class CTest {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
//		int T=1000;
		int T=1;
		Random r=new Random(5);
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
//			int n=6;
			VecL[] points=new VecL[n];
			TreeSet<VecL> ts=new TreeSet<>();
			for (int i=0; i<n; i++) {
//				points[i]=new VecL(r.nextInt(15), r.nextInt(15));
				points[i]=new VecL(fs.nextLong(), fs.nextLong());
				if (ts.contains(points[i])) {
					i--;
					continue;
				}
				ts.add(points[i]);
			}
			for (int i=0; i<n; i++) points[i].id=i+1;
			
			for (int times=0; times<n; times++) {
				for (int i=0; i+2<points.length; i++) {
					if (points[i+1].sub(points[i]).dot(points[i+2].sub(points[i+1]))>=0) {
						// then currently >10 degrees,
						// a b c -> a c b
						VecL temp=points[i+1];
						points[i+1]=points[i+2];
						points[i+2]=temp;
					}
				}
			}
			for (int i=0; i+2<points.length; i++) {
				if (points[i+1].sub(points[i]).dot(points[i+2].sub(points[i+1]))>=0) throw null;
			}
			for (VecL v:points) {
				System.out.print(v.id+" ");
			}
			System.out.println();
		}
	}

	static class VecL implements Comparable<VecL> {
		long x, y;
		int id;
		public VecL(long x, long y) {this.x=x;this.y=y;}
		public VecL add(VecL o) {return new VecL(x+o.x, y+o.y);}
		public VecL sub(VecL o) {return new VecL(x-o.x, y-o.y);}
		public VecL scale(long s) {return new VecL(x*s, y*s);}
		public long dot(VecL o) {return x*o.x+y*o.y;}
		public long cross(VecL o) {return x*o.y-y*o.x;}
		public long mag2() {return dot(this);}
		public VecL rot90() {return new VecL(-y, x);}
		public VecL rot270() {return new VecL(y, -x);}
		public String toString() {return "("+x+", "+y+")";}
		public int hashCode() {return Long.hashCode(x<<13^(y*57));}
		
		public boolean equals(Object oo) {
			VecL o=(VecL)oo;
			return x==o.x&&y==o.y;
		}
		
		public int compareTo(VecL o) {
			if (x!=o.x) return Long.compare(x, o.x);
			return Long.compare(y, o.y);
		}
		
		//origin->q1, axes-> quadrant in ccw direction
		public int quadrant() {
			if (x==0||y==0)
				if (y==0) return x>=0 ? 1 : 3;
				else return y>=0 ? 2 : 4;
			if (x>0) return y>0 ? 1 : 4;
			else return y>0 ? 2 : 3;
		}
		
		public int radialCompare(VecL o) {
			if (quadrant()==o.quadrant())
				return -Long.signum(cross(o));
			return Integer.compare(quadrant(), o.quadrant());
		}
	}


	static void ruffleSort(int[] a) {
		int n=a.length;
		Random r=new Random();
		for (int i=0; i<a.length; i++) {
			int oi=r.nextInt(n), temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
		}
		Arrays.sort(a);
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