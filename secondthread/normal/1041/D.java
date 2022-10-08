import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D2 {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		int h=fs.nextInt();
		Seg[] segs=new Seg[n];
		for (int i=0; i<n; i++)
			segs[i]=new Seg(fs.nextInt(), fs.nextInt());
		Arrays.sort(segs);
		int freeSpaces=0;
		for (int i=0; i<n; i++) {
			segs[i].freeBefore=freeSpaces;
			freeSpaces+=segs[i].freeSpaces();
		}
		long best=h;
		for (int startSeg=0; startSeg<n; startSeg++) {
			//binary search for last I can reach
			int min=startSeg, max=n-1;
			while (min!=max) {
				int mid=(min+max+1)/2;
				int fullDist=segs[mid].from-segs[startSeg].from-segs[mid].freeBefore+segs[startSeg].freeBefore;
				if (fullDist<h) {
					min=mid;
				}
				else {
					max=mid-1;
				}
			}
			long totalDist=segs[min].freeBefore-segs[startSeg].freeBefore+h+segs[min].freeSpaces();
			best=Math.max(best, totalDist);
		}
		System.out.println(best);
	}
	
	static class Seg implements Comparable<Seg> {
		int from, to;
		int freeBefore=0;
		public Seg(int from, int to) {
			this.from=from;
			this.to=to;
		}
		
		public int freeSpaces() {
			return to-from;
		}
		
		public int compareTo(Seg o) {
			return Integer.compare(from, o.from);
		}
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		
		public String next() {
			while (!st.hasMoreTokens())
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
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
	}
}