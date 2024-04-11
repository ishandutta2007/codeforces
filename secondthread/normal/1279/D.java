

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class D {

	static int mod=998244353;
	
	public static void solve(FastScanner fs) {
		//7/8
		//3/4 times item 1 is picked
		//1/2 of the time item 2 is picked, it goes to the right person
		int nKids=fs.nextInt();
		long[] chancePicked=new long[1_000_000];
		long[] timesWanted=new long[1_000_000];
		long nInv=modInv(nKids);
		for (int i=0; i<nKids; i++) {
			int nWants=fs.nextInt();
			long nWantsInv=modInv(nWants);
			for (int j=0; j<nWants; j++) {
				int present=fs.nextInt()-1;
				chancePicked[present]=(chancePicked[present]+nInv*nWantsInv)%mod;
				timesWanted[present]++;
			}
		}
		long ans=0;
		for (int i=0; i<1_000_000/*TODO*/; i++) {
			long chanceWanted=timesWanted[i]*nInv%mod;
			ans=(ans+chancePicked[i]*chanceWanted)%mod;
		}
		System.out.println(ans);
	}

	
	static long modInv(int x) {
		return modPow(x, mod-2);
//		return 1/(double)x;
	}
	
	static long modPow(int base, int exp) {
		if (exp==0) return 1;
		long half=modPow(base, exp/2);
		if (exp%2==0) return half*half%mod;
		return half*half%mod*base%mod;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		FastScanner scanner = new FastScanner(System.in);
		solve(scanner);
	}
	

	private static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++)
				a[i]=nextInt();
			return a;
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++)
				a[i]=nextLong();
			return a;
		}
	}
}