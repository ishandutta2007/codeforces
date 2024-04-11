import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class CoveredPoints {
	static final boolean debug=false;

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		SegL[] segs=new SegL[n];
		for (int i=0; i<n; i++) {
			segs[i]=new SegL(new VecL(fs.nextInt(), fs.nextInt()), new VecL(fs.nextInt(), fs.nextInt()));
		}
		long total=0;
		for (int first=0; first<n; first++) {
			HashSet<VecL> alreadyUsed=new HashSet<VecL>();
			int toAdd=pointsIn(segs[first]);
			if (debug) System.out.println("\tPoint in "+segs[first]+": "+toAdd);
			for (int second=first+1; second<n; second++) {
				VecL intersect=segs[first].latticeIntersect(segs[second]);
				if (intersect!=null && !alreadyUsed.contains(intersect)) {
					if (debug)System.out.println("\tIntersects at "+intersect);
					alreadyUsed.add(intersect);
					toAdd--;
				}
			}
			if (debug) System.out.println("Seg "+segs[first]+" contained "+toAdd+" new points.");
			total+=toAdd;
		}
		System.out.println(total);

	}
	
	static int gcd(int a, int b) {
		a=Math.abs(a);
		b=Math.abs(b);
		return b==0?a:gcd(b, a%b);
	}
	
	static int gcd(long a, long b) {
		return gcd((int)a, (int)b);
	}
	
	static int pointsIn(SegL seg) {
		return gcd((int)(seg.dir.x), (int)(seg.dir.y))+1;
	}
	
	static class SegL {
		VecL from, to, dir;
		
		public SegL(VecL from, VecL to) {
			this.from=from;
			this.to=to;
			dir=to.sub(from);
		}
		
		//(assuming I go left to right)
		//returns:
		//	1 if point is above me
		//	0 if point is on me
		//	-1 if point is below me
		public long side(VecL o) {
			long cross=dir.cross(o.sub(from));
			return cross==0?0:cross/Math.abs(cross);
		}
		
		//returns true if this segl intersects the other, including at endpoints
		public boolean intersects(SegL o) {
			return side(o.from)!=side(o.to) && o.side(from)!=o.side(to);
		}
		
		public String toString() {
			return from+" -> "+to;
		}
		
		//returns the lattice point of intersection or null if it is nonlattice or does not exist 
		public VecL latticeIntersect(SegL o) {
			if (!intersects(o)) return null;
			int dirGCD=gcd(dir.x, dir.y), oDirGCD=gcd(o.dir.x, o.dir.y);
			VecL va=new VecL(dir.x/dirGCD, dir.y/dirGCD), vb=new VecL(o.dir.x/oDirGCD, o.dir.y/oDirGCD);
			if (va.x<0&&va.y<0) {
				va.x*=-1;
				va.y*=-1;
			}
			if (vb.x<0&&vb.y<0) {
				vb.x*=-1;
				vb.y*=-1;
			}
			if (va.equals(vb)) {
				return null;
			}
			long bottomScalar=va.x/gcd(va.x, va.y);
			long topScalar=va.y/gcd(va.x, va.y);
			long t2Scalar=-bottomScalar*vb.y + topScalar*vb.x;
			long t2Ans=bottomScalar*(o.from.y-from.y) - topScalar*(o.from.x-from.x);
			if (t2Ans%t2Scalar!=0)
				return null;
			long t2=t2Ans/t2Scalar;
			return new VecL(t2*vb.x+o.from.x, t2*vb.y+o.from.y);
		}
	}

	
	static class VecL {
		long x, y;
		
		public VecL(long x, long y) {
			this.x=x;
			this.y=y;
		}
		
		public VecL add(VecL o) {
			return new VecL(x+o.x, y+o.y);
		}
		
		public VecL scale(long s) {
			return new VecL(x*s, y*s);
		}
		
		public VecL sub(VecL o) {
			return add(o.scale(-1));
		}
		
		public long dot(VecL o) {
			return x*o.x+y*o.y;
		}
		
		public long cross(VecL o) {
			return x*o.y-y*o.x;
		}
		
		public long mag2() {
			return dot(this);
		}
		
		public boolean equals(Object oo) {
			VecL o=(VecL)oo;
			return x==o.x&&y==o.y;
		}
		
		public String toString() {
			return "("+x+", "+y+")";
		}
		
		public int hashCode() {
			return (int)x^((int)(y%8675309)>>>16+(int)y<<16);
		}
		
		public int compareTo(VecL o) {
			int xComp=Long.compare(x, o.x);
			return xComp==0?xComp:Long.compare(y, o.y);
		}
	}
	
	static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br=new BufferedReader(new InputStreamReader(System.in));
			st=new StringTokenizer("");
		}

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
	}

}