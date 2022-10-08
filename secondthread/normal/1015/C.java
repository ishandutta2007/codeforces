import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nSongs=fs.nextInt();
		long totalCap=fs.nextLong();
		long curTotal=0, minTotal=0;
		Song[] songs=new Song[nSongs];
		for (int i=0; i<nSongs; i++) {
			int un=fs.nextInt();
			int comp=fs.nextInt();
			curTotal+=un;
			minTotal+=comp;
			songs[i]=new Song(un, comp);
		}
		Arrays.sort(songs);
		if (minTotal>totalCap) {
			System.out.println(-1);
			return;
		}
		for (int i=0; true; i++) {
			if (curTotal<=totalCap) {
				System.out.println(i);
				return;
			}
			else {
				curTotal-=songs[i].uncompressed;
				curTotal+=songs[i].compressed;
			}
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