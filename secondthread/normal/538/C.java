import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class C {
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nDays=fs.nextInt(), nRecords=fs.nextInt();
		int best=0;
		int[] recordTimes=new int[nRecords];
		int[] recordHeights=new int[nRecords];
		for (int i=0; i<nRecords; i++) {
			recordTimes[i]=fs.nextInt();
			recordHeights[i]=fs.nextInt();
		}
		best=recordHeights[0];
		for (int i=0; i+1<nRecords; i++) {
			int dTime=recordTimes[i+1]-recordTimes[i];
			int dHeight=recordHeights[i+1]-recordHeights[i];
			if (Math.abs(dHeight)>dTime) {
				System.out.println("IMPOSSIBLE");
				return;
			}
			int curRes=Math.max(recordHeights[i+1], recordHeights[i])+(dTime-Math.abs(dHeight))/2;
			best=Math.max(best, curRes);
		}
		best=Math.max(best, recordHeights[0]+recordTimes[0]-1);
		best=Math.max(best, recordHeights[nRecords-1]-recordTimes[nRecords-1]+nDays);
		System.out.println(best);
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
		
		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
		
		public long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}

}