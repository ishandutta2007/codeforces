import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=1;//fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int nPoints=fs.nextInt(), nRects=fs.nextInt();
			int[] robberXs=new int[nPoints], 
					robberYs=new int[nPoints];
			for (int i=0; i<nPoints; i++) {
				robberXs[i]=fs.nextInt();
				robberYs[i]=fs.nextInt();
			}
			int[] highest=new int[3_000_000];
			Arrays.fill(highest, -1);
			for (int i=0; i<nRects; i++) {
				int rx=fs.nextInt(), ry=fs.nextInt();
				for (int j=0; j<nPoints; j++) {
					int x=rx-robberXs[j];
					int y=ry-robberYs[j];
					if (x>=0 && y>=0)
						highest[x]=Math.max(highest[x], y);
				}
			}
			int best=Integer.MAX_VALUE;
			int minY=0;
			for (int x=highest.length-1; x>=0; x--) { 
				best=Math.min(best, x+1+minY);
				minY=Math.max(minY, highest[x]+1);
			}
			best=Math.min(best, minY);
			System.out.println(best);
		}
	}

	static class Rect implements Comparable<Rect> {
		int x, y;
		public Rect(int x, int y) {
			this.x=x;
			this.y=y;
		}
		
		public int compareTo(Rect o) {
			if (x!=o.x) return Integer.compare(x, o.x);
			return Integer.compare(y, o.y);
		}
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