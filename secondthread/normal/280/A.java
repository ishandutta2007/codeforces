import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.StringTokenizer;

public class _501 {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		double w=fs.nextInt(), h=fs.nextInt();
		int aDeg=fs.nextInt();
		if (aDeg==0 || aDeg==180) {
			System.out.println(w*h);
			return;
		}
		if (aDeg==90) {
			System.out.println(Math.min(w, h)*Math.min(h, w));
			return;
		}
		if (aDeg>90) {
			aDeg=180-aDeg;
		}

		Seg top=new Seg(new Vec(-w/2, h/2), new Vec(w/2, h/2));
		Seg bottom=new Seg(new Vec(-w/2, -h/2), new Vec(w/2, -h/2));
		Seg left=new Seg(new Vec(-w/2, -h/2), new Vec(-w/2, h/2));
		Seg right=new Seg(new Vec(w/2, -h/2), new Vec(w/2, h/2));
		Seg[] segs= {top, left, bottom, right};
		
		ArrayList<Vec> all=new ArrayList<>();
		for (Seg s:segs) {
			for (Seg t:segs) {
//				if (s==t) continue;
				Vec v=s.segIntersection(t.rotate(Math.toRadians(aDeg)));
				if (v!=null) all.add(v);
			}
		}
		Vec[] hull=ConvexHull.getHull(all);
//		System.out.println(Arrays.toString(hull));
		double aa=0;
		for (int i=0; i<hull.length; i++) {
			Vec now=hull[i], next=hull[(i+1)%hull.length];
			aa+=Math.abs(now.cross(next)/2);
		}
		
		
		System.out.println(Math.abs(aa));
	}

	static class ConvexHull {

		static Vec[] upperHull, lowerHull;

		// returns the hull in CCW order
		public static Vec[] getHull(ArrayList<Vec> pointsV) {
			Vec[] points=new Vec[pointsV.size()];
			for (int i=0; i<points.length; i++) points[i]=pointsV.get(i);
			points=points.clone();
			Arrays.sort(points);
			if (points.length<3)
				return upperHull=lowerHull=points;
			int n=points.length, j=2, k=2;
			Vec[] lo=new Vec[n], up=new Vec[n];
			lo[0]=points[0];
			lo[1]=points[1];
			for (int i=2; i<n; i++) {
				Vec p=points[i];
				while (j>1&&!right(lo[j-2], lo[j-1], p)) j--;
				lo[j++]=p;
			}
			up[0]=points[n-1];
			up[1]=points[n-2];
			for (int i=n-3; i>=0; i--) {
				Vec p=points[i];
				while (k>1&&!right(up[k-2], up[k-1], p)) k--;
				up[k++]=p;
			}

			Vec[] res=new Vec[j+k-2];
			for (int i=0; i<k; i++) res[i]=up[i];
			for (int i=1; i<j-1; i++) res[k+i-1]=lo[i];

			// if you need upper and lower hulls
			upperHull=new Vec[k];
			for (int i=0; i<k; i++) upperHull[i]=up[k-i-1];
			lowerHull=new Vec[j];
			for (int i=0; i<j; i++) lowerHull[i]=lo[i];

			return res;
		}

		// check if a->b->c are in the right order
		static boolean right(Vec a, Vec b, Vec c) {
			return b.sub(a).cross(c.sub(a))>0;
		}

	}

	
	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class Seg {
		Vec from, to, dir;
		
		public Seg(Vec from, Vec to) {
			this.from=from;
			this.to=to;
			dir=to.sub(from);
		}
		
		//line-line intersection
		public Vec lineIntersect(Seg o) {
			double det=o.dir.x*dir.y-dir.x*o.dir.y;
			double dist=(o.dir.x*(o.from.y-from.y)-
					o.dir.y*(o.from.x-from.x))/det;
			return from.add(dir.scale(dist));
		}
		
		public Vec getClosestTo(Vec o) {
			double percentThere=o.sub(from).dot(dir)/dir.mag2();
			return from.add(dir.scale(Math.max(0, Math.min(1, percentThere))));
		}
		
		public Vec projectToLine(Vec o) {
			return dir.scale(o.sub(from).dot(dir)/dir.mag2()).add(from);
		}
		
		public Seg rotate(double deg) {
			return new Seg(from.rotate(deg), to.rotate(deg));
		}
		//seg-seg intersection
		public Vec segIntersection(Seg o) {
			Vec intersect=lineIntersect(o);
			if(intersect == null) return null;
			return containsPoint(intersect)&&o.containsPoint(intersect)?intersect:null;
		}
		public boolean containsPoint(Vec o) {
			double distFromLine=dir.unit().cross(o.sub(from));
			if (!Vec.eq(distFromLine, 0)) return false;
			return Vec.eq(dir.mag(), from.sub(o).mag()+to.sub(o).mag());
		}
		
		
		public String toString() {
			return from+" -> "+to;
		}
	}

	static class Vec implements Comparable<Vec> {
		static final double EPS=1e-6;
		double x, y;
		public Vec(double x, double y) {this.x=x;this.y=y;}
		public Vec add(Vec o) {return new Vec(x+o.x, y+o.y);}
		public Vec sub(Vec o) {return new Vec(x-o.x, y-o.y);}
		public Vec scale(double s) {return new Vec(x*s, y*s);}
		public double dot(Vec o) {return x*o.x+y*o.y;}
		public double cross(Vec o) {return x*o.y-y*o.x;}
		public double mag2() {return dot(this);}
		public double mag() {return Math.sqrt(mag2());}
		public Vec unit() {return scale(1/mag());}
		public Vec rot90() {return new Vec(-y, x);}
		public Vec rot270() {return new Vec(y, -x);}
		
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
		
		static boolean eq(double a, double b) {
			return Math.abs(a-b)<EPS;
		}
		
		public int compareTo(Vec o) {
			if (x!=o.x)return Double.compare(x, o.x);
			return Double.compare(y, o.y);
		}
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