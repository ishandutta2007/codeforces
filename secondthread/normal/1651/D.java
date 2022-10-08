import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Random;
import java.util.StringTokenizer;

/*


  X
   Y 
     X
   Y
4
0 0
0 1
1 0
1 1

1
0 0

 */
public class D {

	static long toL(int a, int b) {
		return (long)(a+1e7)*(long)1e9+b;
	}
	static long[] allThings;
	static boolean contains(long[] a, long x) {
		int min=0, max=a.length-1;
		while (min<=max) {
			int mid=(min+max)>>1;
			if (a[mid]==x) return true;
			if (a[mid]>x) {
				max=mid-1;
			}
			else {
				min=mid+1;
			}
		}
		return false;
	}
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt();
		Vec[] oPoints=new Vec[n];
		allThings=new long[n];
		for (int i=0; i<n; i++) {
			oPoints[i]=new Vec(fs.nextInt(), fs.nextInt(), i);
			allThings[i]=toL(oPoints[i].x, oPoints[i].y);
		}
		Arrays.sort(allThings);
		ArrayList<Vec> bPoints=new ArrayList<>();
		for (Vec v:oPoints) {
			int[] dx= {-1, 1, 0, 0};
			int[] dy= {0, 0, -1, 1};
			for (int d=0; d<4; d++) {
				if (!contains(allThings, toL(v.x+dx[d], v.y+dy[d]))) {
					bPoints.add(new Vec(v.x+dx[d], v.y+dy[d], -1));
				}
			}
		}
		
		Vec[] allPoints=new Vec[bPoints.size()+oPoints.length];
		for (int i=0; i<bPoints.size(); i++)
			allPoints[i]=bPoints.get(i);
		for (int i=0; i<oPoints.length; i++)
			allPoints[i+bPoints.size()]=oPoints[i];
		
		//4 sweeps:
		//sweep by x, look at things with a smaller y, find smallest x+y
		ST st=new ST(0, 2_000_03);
		for (int i=0; i<4; i++) {
//			System.out.println("\n\nLooking in dir "+i);
			if (i!=0) st.clear();
			int xOffset=0;
			for (Vec v:allPoints) xOffset=Math.min(v.x, xOffset);
			Arrays.sort(allPoints, (a, b) -> {
				if (a.y!=b.y)
					return -Integer.compare(a.y, b.y);
				return -Integer.compare(a.x, b.x);
			});
			for (Vec v:allPoints) {
//				System.out.println("Processing "+v.x+" "+v.y);
				if (v.id==-1) {
					st.addVec(v, v.x-xOffset);
				}
				else {
					Vec closest=st.getMinXPlusY(v.x-xOffset, 5000_000);
//					System.out.println(closest);
					if (closest != null) {
						for (int ind=0; ind<v.candidates.length; ind++) {
							if (v.candidates[ind]==null) {
								v.candidates[ind]=closest;
								break;
							}
						}
					}
				}
			}
			for (Vec v:allPoints) v.rot90();
		}
		
		for (Vec v:oPoints) {
			Vec u=v.closest();
			out.println(u.x+" "+u.y);
		}
		out.close();
	}
	
	static class ST {
		int leftmost, rightmost;
		ST lChild, rChild;
		Vec minXPlusY;
		public ST(int l, int r) {
			this.leftmost=l;
			this.rightmost=r;
			if (l!=r) {
				int mid=l+((r-l)>>1);
				lChild=new ST(l, mid);
				rChild=new ST(mid+1, r);
			}
		}
		void addVec(Vec v, int x) {
			if (x<leftmost || x>rightmost) throw null;
			minXPlusY=better(minXPlusY, v);
			if (lChild!=null) {
				if (x<=lChild.rightmost)
					lChild.addVec(v, x);
				else 
					rChild.addVec(v, x);
			}
		}
		Vec getMinXPlusY(int l, int r) {
			if (l<=leftmost && r>=rightmost) return minXPlusY;
			if (l>rightmost || r<leftmost) return null;
			return better(lChild.getMinXPlusY(l, r), rChild.getMinXPlusY(l, r));
		}
		public void clear() {
			minXPlusY=null;
			if (lChild!=null) {
				lChild.clear();
				rChild.clear();
			}
		}
	}
	
	static Vec better(Vec a, Vec b) {
		if (a==null) return b;
		if (b==null) return a;
		int aVal=a.x+a.y, bVal=b.x+b.y;
		if (aVal<bVal) return a;
		return b;
	}
	
	static class Vec implements Comparable<Vec> {
		int x,y, id;//id is -1 if fake
		Vec[] candidates;
		public Vec(int x, int y, int id) {
			this.x=x;
			this.y=y;
			this.id=id;
			if (id!=-1) candidates=new Vec[4];
		}
		int dist(Vec o) {
			return Math.abs(y-o.y)+Math.abs(x-o.x);
		}
		public int compareTo(Vec o) {
			if (x!=o.x) { 
				return Integer.compare(x, o.x);
			}
			return Integer.compare(y, o.y);
		}
		Vec closest() {
			Vec ans=candidates[0];
			if (ans==null) throw null;
			for (Vec v:candidates)
				if (v!=null && dist(v)<dist(ans)) ans=v;
			return ans;
		}
		void rot90() {
			int newX=y;
			int newY=-x;
			x=newX;
			y=newY;
		}
	}
	
	static final int mod=1_000_000_007;
	
//	static void ruffleSort(int[] a) {
//		int n=a.length;//shuffle, then sort 
//		for (int i=0; i<n; i++) {
//			int oi=random.nextInt(n), temp=a[oi];
//			a[oi]=a[i]; a[i]=temp;
//		}
//		Arrays.sort(a);
//	}
	static long add(long a, long b) {
		return (a+b)%mod;
	}
	static long sub(long a, long b) {
		return ((a-b)%mod+mod)%mod;
	}
	static long mul(long a, long b) {
		return (a*b)%mod;
	}
	static long exp(long base, long exp) {
		if (exp==0) return 1;
		long half=exp(base, exp/2);
		if (exp%2==0) return mul(half, half);
		return mul(half, mul(half, base));
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