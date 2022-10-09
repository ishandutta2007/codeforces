

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class B {

	public static void solve(FastScanner fs) {	
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int nGoods=fs.nextInt(), nCoins=fs.nextInt(), k=fs.nextInt();
			int[] prices=new int[nGoods];
			for (int i=0; i<nGoods; i++) prices[i]=fs.nextInt();
			sort(prices);
			
			long[] cs=new long[nGoods+1];
			long[][] modKCS=new long[k][nGoods/k+1+1];
			for (int i=0; i<nGoods; i++) cs[i+1]=cs[i]+prices[i];
			for (int mod=0; mod<k; mod++) {
				for (int i=0; mod+i*k<nGoods; i++) {
					modKCS[mod][i+1]=modKCS[mod][i]+prices[mod+i*k];
				}
			}
			
			//O(k)*(n/k)
			int best=0;
			for (int cuttoff=0; cuttoff<Math.min(k, nGoods); cuttoff++) {
				long moneyLeft=nCoins-cs[cuttoff];
				if (moneyLeft<0) continue;
				int count=cuttoff;
				for (int i=cuttoff-1+k; i<nGoods; i+=k) {
					if (moneyLeft>=prices[i]) {
						moneyLeft-=prices[i];
						count+=k;
					}
					else
						break;
				}
//				System.out.println("With cuttoff: "+cuttoff+" got "+count);
				best=Math.max(best, count);
				
			}
			System.out.println(best);
		}
	}

	
	static void sort(int[] a) {
		Random r=new Random();
		int n=a.length;
		for(int i=0; i<n; i++) {
			int o=r.nextInt(n);
			int t=a[o];
			a[o]=a[i];
			a[i]=t;
		}
		Arrays.sort(a);
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