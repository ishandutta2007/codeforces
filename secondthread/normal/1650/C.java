import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt(), m=fs.nextInt();
			Point[] points=new Point[m];
			for (int i=0; i<m; i++) points[i]=new Point(fs.nextInt(), fs.nextInt(), i+1);
			Arrays.sort(points, (a, b) -> a.val-b.val);
			Point[] take=new Point[n*2];
			for (int i=0; i<n*2; i++) take[i]=points[i];
			Arrays.sort(take, (a, b) -> a.x-b.x);
			long ans=0;
			for (Point p:take) ans+=p.val;
			System.out.println(ans);
			for (int i=0; i<n; i++) {
				System.out.println(take[i].id+" "+take[2*n-i-1].id);
			}
			System.out.println();
		}
	}
	
	static class Point {
		int x;
		int val;
		int id;
		public Point(int x, int val, int id) {
			this.x=x;
			this.val=val;
			this.id=id;
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
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
	}

}