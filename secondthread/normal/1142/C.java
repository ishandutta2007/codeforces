import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		HashMap<Integer, Integer> maxY=new HashMap<>();
		int n=fs.nextInt();
		for (int i=0; i<n; i++) {
			int x=fs.nextInt(), y=fs.nextInt();
			maxY.put(x, Math.max(maxY.getOrDefault(x, y), y));
		}
		
		VecL[] points=new VecL[maxY.size()];
		n=0;
		for (int x:maxY.keySet()) {
			long y=maxY.get(x);
			points[n++]=new VecL(x, y-x*(long)x);
		}
		if (n==1) {
			System.out.println(0);
			return;
		}
		
//		System.out.println(Arrays.toString(points));
		
		Arrays.sort(points);
		VecL[] up=new VecL[n];
		int size=0;
		up[size++]=points[0];
		up[size++]=points[1];
		for (int i=2; i<n; i++) {
			VecL p=points[i];
			while (size>1 && !okay(up[size-2], up[size-1], p)) size--;
			up[size++]=p;
		}
		System.out.println(size-1);
	}
	
	static boolean okay(VecL a, VecL b, VecL c) {
		return b.sub(a).cross(c.sub(a))<0;
	}

	static class VecL implements Comparable<VecL>{
		long x, y;
		public VecL(long x, long y) {
			this.x=x;
			this.y=y;
		}
		VecL add(VecL o) {return new VecL(x+o.x, y+o.y);}
		VecL sub(VecL o) {return new VecL(x-o.x, y-o.y);}
		long dot(VecL o) {return x*o.x + y*o.y;}
		long cross(VecL o) {return x*o.y - y*o.x;}
		public String toString() {
			return "("+x+", "+y+")";
		}
		public int compareTo(VecL o) {
			return Long.compare(x, o.x);
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

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
	
}