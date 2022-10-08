import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*

 */
public class C2 {
	
	static double[] a, cs;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt();
		a=new double[n];
		cs=new double[n+1];
		for (int i=0; i<n; i++) a[i]=fs.nextInt();
		for (int i=1; i<=n; i++) cs[i]=a[i-1]+cs[i-1];
		
		BenQueue bq=new BenQueue();
		int[] bestEnds=new int[n];
		for (int i=n-1; i>=0; i--) {
			bq.addFront(i);
			while (bq.size()>1) {
				int first=bq.getFront();
				bq.removeFront();
				int second=bq.getFront();
				if (getAverage(i, second)<getAverage(i, first)) {
					//then remove the first one
				}
				else {
					bq.addFront(first);
					break;
				}
			}
			bestEnds[i]=bq.getFront();
		}
		
		PrintWriter out=new PrintWriter(System.out);
		for (int ind=0; ind<n; ind++) {
			int end=bestEnds[ind];
			for (int x=ind; x<=end; x++) {
				out.println(getAverage(ind, end));
			}
			ind=end;
		}
		out.close();
	}
	
	//gets the average, inclusive
	static double getAverage(int from, int to) {
		double sum=cs[to+1]-cs[from];
		return sum/(to-from+1);
	}
	
	static class BenQueue {
		int[] arr=new int[1_000_001];
		int frontInd, endInd;
		public BenQueue() {
			frontInd=(endInd=1_000_000)+1;
		}
		
		public void addFront(int i) {
			arr[--frontInd]=i;
		}
		public int getFront() {
			if (isEmpty()) throw null;
			return arr[frontInd];
		}
		public void removeFront() {
			if (isEmpty()) throw null;
			frontInd++;
		}
		public int get(int i) {
			if (frontInd+i>endInd) throw null;
			return arr[frontInd+i];
		}
		public boolean isEmpty() {
			return size()==0;
		}
		public int size() {
			return endInd-frontInd+1;
		}
	}
	
	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			while (!st.hasMoreElements())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}
	
}