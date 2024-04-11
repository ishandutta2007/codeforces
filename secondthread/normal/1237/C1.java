import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Vec[] a=new Vec[n];
		for (int i=0; i<n; i++) a[i]=new Vec(fs.nextInt(), fs.nextInt(), fs.nextInt(), i);
		TreeSet<Vec> exist=new TreeSet<>();
		for (Vec v:a) exist.add(v);
		TreeMap<Integer, TreeMap<Integer, TreeMap<Integer, Vec>>> xyz=new TreeMap<>();
		for (Vec v:a) {
			if (!xyz.containsKey(v.x)) xyz.put(v.x, new TreeMap<>());
			TreeMap<Integer, TreeMap<Integer, Vec>> yz=xyz.get(v.x);
			if (!yz.containsKey(v.y)) yz.put(v.y, new TreeMap<>());
			TreeMap<Integer, Vec> z=yz.get(v.y);
			z.put(v.z, v);
		}
		for (TreeMap<Integer, TreeMap<Integer, Vec>> yz:xyz.values()) {
			for (TreeMap<Integer, Vec> z:yz.values()) {
				while (z.size()>1) {
					Vec first=z.firstEntry().getValue();
					z.remove(z.firstKey());
					Vec second=z.firstEntry().getValue();
					z.remove(z.firstKey());
					first.dead=second.dead=true;
					System.out.println(first.index+" "+second.index);
				}
			}
		}
		TreeMap<Integer, TreeMap<Integer, Vec>> xy=new TreeMap<>();
		for (Vec v:a) {
			if (v.dead)
				continue;
			if (!xy.containsKey(v.x)) xy.put(v.x, new TreeMap<>());
			TreeMap<Integer, Vec> y=xy.get(v.x);
			y.put(v.y, v);
		}
		for (TreeMap<Integer, Vec> y:xy.values()) {
			while (y.size()>1) {
				Vec first=y.firstEntry().getValue();
				y.remove(y.firstKey());
				Vec second=y.firstEntry().getValue();
				y.remove(y.firstKey());
				first.dead=second.dead=true;
				System.out.println(first.index+" "+second.index);
			}
		}
		ArrayList<Vec> points=new ArrayList<>();
		for (Vec v:a) if (!v.dead) points.add(v);
		Collections.sort(points);
		for (int i=0; i<points.size(); i+=2) {
			System.out.println(points.get(i).index+" "+points.get(i+1).index);
		}
	}

	static class Vec implements Comparable<Vec> {
		int index;
		boolean dead=false;
		int x, y, z;
		public Vec(int x, int y, int z, int index) {
			this.x=x;
			this.y=y;
			this.z=z;
			this.index=index+1;
		}
		
		public int compareTo(Vec o) {
			if (x!=o.x) return Integer.compare(x, o.x);
			if (y!=o.y) return Integer.compare(y, o.y);
			return Integer.compare(z, o.z);
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
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