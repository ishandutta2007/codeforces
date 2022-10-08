import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class D {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		PrintWriter out=new PrintWriter(System.out);
		int n=fs.nextInt();
		int[] a=new int[3*n];
		for (int i=0; i<n; i++)
			a[i+2*n]=a[i+n]=a[i]=fs.nextInt();
		RMQ valuesRMQ=new RMQ(a);
		int[] lastLegal=new int[3*n];
		for (int i=0; i<3*n; i++) {
			int minAllowed=i, maxAllowed=3*n-1;
			while (minAllowed!=maxAllowed) {
				int mid=(minAllowed+maxAllowed+1)/2;
				int rangeMin=valuesRMQ.query(i, mid);
				if (legal(rangeMin, a[i])) {
					minAllowed=mid;
				}
				else {
					maxAllowed=mid-1;
				}
			}
			lastLegal[i]=minAllowed;
		}
		RMQ lastRMQ=new RMQ(lastLegal);
		for (int i=0; i<n; i++) {
			int minEnd=i, maxEnd=3*n-1;
			while (minEnd!=maxEnd) {
				int mid=(minEnd+maxEnd+1)/2;
				int rangeMin=lastRMQ.query(i, mid);
				if (rangeMin<mid) {
					maxEnd=mid-1;
				}
				else {
					minEnd=mid;
				}
			}
			int tracksHeard=minEnd-i+1;
			if (tracksHeard>=2*n) tracksHeard=-1;
			out.print(tracksHeard+" ");
		}
		out.println();
		out.close();
	}
	
	static boolean legal(int min, int curHappiness) {
		return min*2>=curHappiness;
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
	
	static class RMQ {
		int[] vs;
		int[][] lift;

		public RMQ(int[] vs) {
			this.vs = vs;
			int n = vs.length;
			int maxlog = Integer.numberOfTrailingZeros(Integer.highestOneBit(n)) + 2;
			lift = new int[maxlog][n];
			for (int i = 0; i < n; i++)
				lift[0][i] = vs[i];
			int lastRange = 1;
			for (int lg = 1; lg < maxlog; lg++) {
				for (int i = 0; i < n; i++) {
					lift[lg][i] = Math.min(lift[lg - 1][i], lift[lg - 1][Math.min(i + lastRange, n - 1)]);
				}
				lastRange *= 2;
			}
		}

		public int query(int low, int hi) {
			int range = hi - low + 1;
			int exp = Integer.highestOneBit(range);
			int lg = Integer.numberOfTrailingZeros(exp);
			return Math.min(lift[lg][low], lift[lg][hi - exp + 1]);
		}
	}


}