import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class D {
	
	static int[] nSplitPerDay; 
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int toHit=fs.nextInt();
			for (int nNights=0; nNights<60; nNights++) {
				if (canHit(toHit, nNights)) {
					System.out.println(nNights);
					for (int i:nSplitPerDay)
						System.out.print(i+" ");
					System.out.println();
					break;
				}
			}
		}
	}
	
	static boolean canHit(int toHit, int nNights) {
		int nAlive=1;
		toHit-=nNights+1;
		if (toHit<0) throw null;
		nSplitPerDay=new int[nNights];
		for (int i=0; i<nNights; i++) {
			int bonusPerGuy=nNights-i;
			int bonusesAllowed=Math.min(nAlive, toHit/bonusPerGuy);
			nAlive+=bonusesAllowed;
			nSplitPerDay[i]=bonusesAllowed;
			toHit-=bonusPerGuy*bonusesAllowed;
		}
		return toHit==0;
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