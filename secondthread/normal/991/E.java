

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class E {

	public static void solve(FastScanner fs) {
		String line=fs.next();
		int[] cs=new int[10];
		for (char c:line.toCharArray())
			cs[Integer.parseInt(c+"")]++;
		
		long[] totalWays=new long[20];
		totalWays[0]=1;
		for (int i=9; i>0; i--) {//which digit am I placing
			if (cs[i]==0) continue;
			long[] newTotalWays=new long[20];
			for (int toPlace=1; toPlace<=cs[i]; toPlace++) {//how many am I going to place?
				for (int totalNumbers=0; totalNumbers<20; totalNumbers++) {//how many numbers have been placed?
					if (totalWays[totalNumbers]==0) continue;
					int spots=totalNumbers+1;
					newTotalWays[totalNumbers+toPlace]+=totalWays[totalNumbers]*nChoosek(spots+toPlace-1, toPlace);
				}
			}
			totalWays=newTotalWays;
		}
		//TODO: handle 0
		if (cs[0]!=0) {
		long[] newTotalWays=new long[20];
		for (int toPlace=1; toPlace<=cs[0]; toPlace++) {//how many am I going to place?
			for (int totalNumbers=0; totalNumbers<20; totalNumbers++) {//how many numbers have been placed?
				if (totalWays[totalNumbers]==0) continue;
				int spots=totalNumbers;
				newTotalWays[totalNumbers+toPlace]+=totalWays[totalNumbers]*nChoosek(spots+toPlace-1, toPlace);
			}
		}
		totalWays=newTotalWays;
		}
		long ans=0;
		for (long i:totalWays)
			ans+=i;
		System.out.println(ans);
	}

	
	static long nChoosek(int n, int k) {
		return fact(n)/fact(k)/fact(n-k);
	}
	
	static long fact(int i) {
		if (i<2)
			return 1;
		return i*(long)fact(i-1);
			
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