import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class _LiftLevel5C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		Vec[] points=new Vec[n];
		for (int i=0; i<n; i++) points[i]=new Vec(fs.nextInt(), fs.nextInt());
		Vec left=null, right=null, top=null, bottom=null;
		for (Vec v:points) {
			left=v.left(left);
			right=v.right(right);
			top=v.higher(top);
			bottom=v.lower(bottom);
		}
		long fourAns=((right.x-left.x)+(top.y-bottom.y))*2;
		long threeAns=0;
		for (Vec v:points) {
			threeAns=Math.max(threeAns, threeAns(v, left, right));
			threeAns=Math.max(threeAns, threeAns(v, left, top));
			threeAns=Math.max(threeAns, threeAns(v, left, bottom));
			threeAns=Math.max(threeAns, threeAns(v, right, top));
			threeAns=Math.max(threeAns, threeAns(v, right, bottom));
			threeAns=Math.max(threeAns, threeAns(v, top, bottom));
		}
		PrintWriter out=new PrintWriter(System.out);
		out.print(threeAns+" ");
		for (int i=4; i<=n; i++) {
			out.print(fourAns+" ");
		}
		out.println();
		out.close();
	}
	
	static long threeAns(Vec a, Vec b, Vec c) {
		long minX=a.x, minY=a.y, maxX=a.x, maxY=a.y;
		minX=Math.min(minX, b.x);
		minY=Math.min(minY, b.y);
		minX=Math.min(minX, c.x);
		minY=Math.min(minY, c.y);
		maxX=Math.max(maxX, b.x);
		maxY=Math.max(maxY, b.y);
		maxX=Math.max(maxX, c.x);
		maxY=Math.max(maxY, c.y);
		return 2*(maxX-minX+maxY-minY);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreElements()) {
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
	}
	
	static class Vec {
		long x,y;
		public Vec(long x, long y) {
			this.x=x;
			this.y=y;
		}
		Vec lower(Vec o) {
			if (o==null||y<o.y)return this;
			return o;
		}
		Vec higher(Vec o) {
			if (o==null||y>o.y)return this;
			return o;
		}
		Vec left(Vec o) {
			if (o==null||x<o.x)return this;
			return o;
		}
		Vec right(Vec o) {
			if (o==null||x>o.x)return this;
			return o;
		}
	}
}