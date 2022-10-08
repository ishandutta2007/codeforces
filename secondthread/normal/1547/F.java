import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class F {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int n=fs.nextInt();
			int[] a=fs.readArray(n);
			int[] a2=new int[n+n];
			for (int i=0; i<n; i++) a2[i]=a2[i+n]=a[i];
			RMQ rmq=new RMQ(a2);
			int min=0, max=n;
			while (min!=max) {
				int mid=(min+max)/2;
				//TODO: check if all equal
				ArrayList<Integer> answers=new ArrayList<>();
				for (int i=0; i<n; i++) answers.add(rmq.query(i, i+mid));
				Collections.sort(answers);
				if (answers.get(0)==(int)answers.get(answers.size()-1)) {
					max=mid;
				}
				else {
					min=mid+1;
				}
			}
			System.out.println(min);
		}
	}
	
	static int gcd(int a, int b) {
		if (b==0) return a;
		return gcd(b, a%b);
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
					lift[lg][i] = gcd(lift[lg - 1][i], lift[lg - 1][Math.min(i + lastRange, n - 1)]);
				}
				lastRange *= 2;
			}
		}

		public int query(int low, int hi) {
			int range = hi - low + 1;
			int exp = Integer.highestOneBit(range);
			int lg = Integer.numberOfTrailingZeros(exp);
			return gcd(lift[lg][low], lift[lg][hi - exp + 1]);
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