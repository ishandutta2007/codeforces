import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int[] counts=new int[4];
		for (int b=0; b<4; b++) {
			int count=0;
			for (int y=0; y<n; y++) {
				String line=fs.next();
				for (int x=0; x<n; x++) {
					boolean white=(x+y)%2==0;
					boolean isW=line.charAt(x)=='0';
					if (white^isW)
						count++;
				}
			}
			counts[b]=count;
		}
		Arrays.sort(counts);
		long min=counts[0]+counts[1]+n*n+n*n-counts[2]-counts[3];
//		System.out.println(Arrays.toString(counts));
		System.out.println(min);
	}
	
	
	static class Rect {
		int x1, x2, y1, y2;
		public Rect(int x1, int y1, int x2, int y2) {
			this.x1=x1;
			this.x2=x2;
			this.y1=y1;
			this.y2=y2;
		}
		
		public Rect union(Rect o) {
			return new Rect(Math.max(x1, o.x1), Math.max(y1, o.y1), Math.min(x2, o.x2), Math.min(y2, o.y2));
		}
		
		public boolean valid() {
			return x1<=x2&&y1<=y2;
		}
	}
	
	static class Song implements Comparable<Song> {
		long uncompressed, compressed;
		public Song(long uncompressed, long compressed) {
			this.uncompressed=uncompressed;
			this.compressed=compressed;
		}
		
		public int compareTo(Song o) {
			long diff=(uncompressed-compressed);
			long oDiff=o.uncompressed-o.compressed;
			return Long.compare(oDiff, diff);
		}
	}
	
	static double eval(int first, int second) {
		return (first*(double)first+second*second)/(first*second);
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