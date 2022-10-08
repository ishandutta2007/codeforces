import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/*
1
8 5
2 1 7 4
4 2

1
1 8
0 3 1 6
1 5

 */
public class B {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int W=fs.nextInt(), H=fs.nextInt();
			int x1=fs.nextInt(), y1=fs.nextInt(),
					x2=fs.nextInt(), y2=fs.nextInt();
			int w2=fs.nextInt(), h2=fs.nextInt();
			int w1=x2-x1, h1=y2-y1;
			
			int ans=Integer.MAX_VALUE;
			
			if (w2+w1<=W) {
				//place to left
				int nx1=w2;
				ans=Math.min(ans, nx1-x1);
				
				//place to right
				int nx2=W-w2;
				ans=Math.min(ans, x2-nx2);
			}
			if (h2+h1<=H) {
				//place below
				int ny1=h2;
				ans=Math.min(ans, ny1-y1);
				
				//place above
				int ny2=H-h2;
				ans=Math.min(ans, y2-ny2);
			}
			ans=Math.max(ans, 0);
			
			System.out.println(ans==Integer.MAX_VALUE?-1:ans);
		}
	}

	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
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