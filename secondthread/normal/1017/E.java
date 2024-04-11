import java.util.*;
import java.io.*;

public class A {
	
	final static boolean debug=false;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n1=fs.nextInt(), n2=fs.nextInt();
		Vec[] vecs1=new Vec[n1], vecs2=new Vec[n2];
		for (int i=0; i<n1; i++)
			vecs1[i]=new Vec(fs.nextInt(), fs.nextInt());
		for (int i=0; i<n2; i++)
			vecs2[i]=new Vec(fs.nextInt(), fs.nextInt());
		ArrayList<Vec> h1=getHull(vecs1);
		ArrayList<Vec> h2=getHull(vecs2);
		if (debug) System.out.println(h1);
		if (debug) System.out.println(h2);
		if (h1.size()!=h2.size()) {
			System.out.println("NO");
			return;
		}
		long[][] h1Parts=getParts(h1), h2Parts=getParts(h2);
		if (debug)System.out.println("h1 parts:");
		for (int i=0; i<h1Parts.length; i++) {
			if (debug) System.out.println(h1Parts[i][0]+" "+h1Parts[i][1]+" "+h1Parts[i][2]);
		}
		if (debug)System.out.println("h2 parts:");
		for (int i=0; i<h2Parts.length; i++) {
			if (debug) System.out.println(h2Parts[i][0]+" "+h2Parts[i][1]+" "+h1Parts[i][2]);
		}
		if (works(h1Parts, h2Parts)) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
	}
	
	public static long[][] getParts(ArrayList<Vec> hull) {
		int n=hull.size();
		long[][] toReturn=new long[n][3];
		for (int i=0; i<n; i++) {
			Vec v1=hull.get((i+1)%n).sub(hull.get(i));
			Vec v2=hull.get((i+2)%n).sub(hull.get((i+1)%n));
			
			toReturn[i][0]=v1.mag2();
			toReturn[i][1]=v1.cross(v2);
			toReturn[i][2]=v1.dot(v2);
		}
		return toReturn;
	}
	
	private static boolean works(long[][] h1, long[][] h2) {
		int n=h1.length;
		long[][] full=new long[n+1+n+n][2];
		for (int i=0; i<n; i++) {
			full[i]=h1[i];
			full[n+1+i]=full[n+1+n+i]=h2[i];
		}
		full[n]=new long[] {-999999999999999l, -999999999999999l, -999999999999999l};
		int[] zVals=zValues(full);
		if (debug) System.out.println("z: "+Arrays.toString(zVals));
		for (int i=n; i<zVals.length; i++)
			if (zVals[i]>=n) return true;
		return false;
	}
	
	public static int[] zValues(long[][] s) {
	int n = s.length; 
	int[] z = new int[n];  z[0] = n;
	int L = 0, R = 0;
	int[] left = new int[n], right = new int[n];
	for(int i = 1; i < n; ++i) {
		if(i > R) {
			L = R = i;
			while(R < n && s[R-L][0] == s[R][0] && s[R-L][1] == s[R][1] && s[R-L][2] == s[R][2]) R++;
			z[i] = R - L;  R--;
		} else {
			int k = i-L;
			if(z[k] < R-i+1) z[i] = z[k];
			else {
				L = i;
				while(R < n && s[R-L][0] == s[R][0] && s[R-L][1]== s[R-L][1] && s[R-L][2]== s[R-L][2]) R++;
				z[i] = R - L;  R--;
			}
		}
		left[i] = L;  right[i] = R;
	}
	return z;
}
	
	// Returns the convex hull in COUNTER-CLOCKWISE order.  Vector: Compare X then Y.
public static ArrayList<Vec> getHull(Vec[] ps) {
    ArrayList<Vec> s = new ArrayList<>();
	for (Vec v:ps) s.add(v);
    Collections.sort(s);
    
    int n = s.size(), j = 2, k = 2;

    Vec[] lo = new Vec[n], up = new Vec[n];
    lo[0] = s.get(0);  lo[1] = s.get(1);
                
    for (int i = 2; i < n; i++) {
        Vec p = s.get(i);
        while (j > 1 && !RT(lo[j - 2], lo[j - 1], p))  j--;
        lo[j++] = p;
    }
                
    up[0] = s.get(n - 1);  up[1] = s.get(n - 2);

    for (int i = n - 3; i >= 0; i--) { // note difference
        Vec p = s.get(i);
        while (k > 1 && !RT(up[k - 2], up[k - 1], p))  k--;
        up[k++] = p;
    }
                
    ArrayList<Vec> res = new ArrayList<Vec>();
    for (int i = 0; i < k; i++) res.add(up[i]);
    for (int i = 1; i < j - 1; i++) res.add(lo[i]);

    return res;
}
static boolean RT(Vec a, Vec b, Vec c) { return b.sub(a).cross(c.sub(a)) > 0; }

	
	private static class Vec implements Comparable<Vec> {
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
		
		public long mag2() {
			return x*x+y*y;
		}
		
		public long dot(Vec o) {
			return x*o.x+y*o.y;
		}
		
		public long cross(Vec o) {
			return x*o.y-y*o.x;
		}
		
		public double angle() {
			return Math.atan2(y, x);
		}
		
		public int compareTo(Vec o) {
			if (x!=o.x)
				return Long.compare(x, o.x);
			return Long.compare(y, o.y);
		}
		
		public String toString() {
			return "("+x+", "+y+")";
		}
	}
	
	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
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