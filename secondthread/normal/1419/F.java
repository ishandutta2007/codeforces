import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Vec[] points=new Vec[n];
		for (int i=0; i<n; i++) points[i]=new Vec(fs.nextInt(), fs.nextInt(), i);
		compress(points);
		//directions: URDL
		for (Vec v:points) {
			for (Vec u:points) {
				if (v==u) continue;
				if (v.x==u.x) {
					if (u.y<v.y) {
						if (v.better(0, u)) v.inDir[0]=u;
					}
					else {
						if (v.better(2, u)) v.inDir[2]=u;
					}
				}
				else if (v.y==u.y){
					if (u.x<v.x) {
						if (v.better(3, u)) v.inDir[3]=u;
					}
					else {
						if (v.better(1, u)) v.inDir[1]=u;
					}
				}
			}
		}
		
		if (!possible(points, (int)2e9)) {
			System.out.println(-1);
			return;
		}
		long min=(int)0, max=(int)2e9;
		while (min!=max) {
			int mid=(int) ((min+max)/2);
			if (possible(points, mid)) {
				max=mid;
			}
			else {
				min=mid+1;
			}
		}
		System.out.println(min);
	}
	
	static boolean possible(Vec[] points, int dist) {
		int n=points.length;
		DisjointSet dj=new DisjointSet(n);
		int parts=n;
		for (Vec v:points) {
			for (Vec o:v.inDir) if (o==null) continue; else {
				if (v.man(o)<=dist)
				if (dj.union(v.id, o.id)) parts--;
			}
		}
		
		if (parts==1) return true;
		for (Vec v:points) {
			for (Vec o:points) {
				int partsSaved=parts;
				dj.save();
				
				if (dj.find(v.id)!=dj.find(o.id)) {
					if (v.x==o.x || v.y==o.y) {
						if (v.man(o)<=dist*2) {
							if (dj.union(v.id, o.id)) parts--;
						}
					}
					else {
						//horizontally from v, vertically from u
						if (Math.abs(v.ox-o.ox)>dist || Math.abs(v.oy-o.oy)>dist) {
							//cant actually join them
						}
						else {
							if (dj.union(v.id, o.id)) parts--;
							int placedX=o.ox;
							int placedY=v.oy;
							Vec placed=new Vec(placedX, placedY, -1);
							if (v.inDir[1]!=null && placed.man(v.inDir[1])<=dist) {
								if (dj.union(v.id, v.inDir[1].id)) parts--;
							}
							if (v.inDir[3]!=null && placed.man(v.inDir[3])<=dist) {
								if (dj.union(v.id, v.inDir[3].id)) parts--;
							}
							
							if (o.inDir[0]!=null && placed.man(o.inDir[0])<=dist) {
								if (dj.union(o.id, o.inDir[0].id)) parts--;
							}
							if (o.inDir[2]!=null && placed.man(o.inDir[2])<=dist) {
								if (dj.union(o.id, o.inDir[2].id)) parts--;
							}
						}
					}
				}
				if (parts==1) return true;
				
				dj.restore();
				parts=partsSaved;
			}
		}
		return false;
	}
	
	// Disjoint set but can set a save point and restore to it
	// Do not save twice in a row without restoring first
	static class DisjointSet {
	    int[] s, s2, vs;
	    int curv;
	    public DisjointSet(int n) {
	        s = new int[n]; s2 = new int[n]; vs = new int[n];
	        Arrays.fill(s, -1);
	        curv = -1;
	    }
	    void save() { curv = 1 - curv; }
	    void restore() { curv *= -1; }
	    int find(int i) { return get(i) < 0 ? i : set(i, find(get(i))); }
	    int get(int i) { return vs[i] == curv ? s2[i] : s[i]; }
	    int set(int i, int v) {
	        if (curv < 0) return s[i] = v;
	        vs[i] = curv;
	        return s2[i] = v;
	    }
	    boolean union(int a, int b) {
	    	if (find(a)==find(b)) return false;
	        if (get(a = find(a)) == get(b = find(b))) set(a, get(a) - 1);
	        if (get(a) <= get(b)) set(b, a); else set(a, b);
	        return true;
	    }
	}


	
	static void compress(Vec[] points) {
		TreeSet<Integer> xs=new TreeSet<>(), ys=new TreeSet<>();
		for (Vec v:points) {
			xs.add(v.ox);
			ys.add(v.oy);
		}
		HashMap<Integer, Integer> xMap=new HashMap<>(), yMap=new HashMap<>();
		for (int x:xs) xMap.put(x, xMap.size());
		for (int y:ys) yMap.put(y, yMap.size());
		for (Vec v:points) {
			v.x=xMap.get(v.ox);
			v.y=yMap.get(v.oy);
		}
	}

	static class Vec {
		int x,y;
		int ox, oy;
		int id;
		Vec[] inDir=new Vec[4];
		
		public Vec(int ox, int oy, int id) {
			this.ox=ox;
			this.oy=oy;
			this.id=id;
		}
		
		public boolean better(int dir, Vec o) {
			if (inDir[dir]==null) return true;
			return man(o)<man(inDir[dir]);
		}
		
		public int man(Vec o) {return Math.abs(ox-o.ox)+Math.abs(oy-o.oy);}
		
	}
	
	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
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