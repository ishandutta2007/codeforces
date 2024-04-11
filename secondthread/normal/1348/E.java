import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class DItSpacesaving {
	
	static long[][] dp;
	static int nShrubs, bucketSize;
	static long[] nRed, nBlue, redCS, blueCS;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		nShrubs=fs.nextInt(); bucketSize=fs.nextInt();
		long time=System.currentTimeMillis();
		nRed=new long[nShrubs]; nBlue=new long[nShrubs];
		for (int i=0; i<nShrubs; i++) {
			nRed[i]=fs.nextLong(); nBlue[i]=fs.nextLong();
		}
		redCS=new long[nShrubs+1]; blueCS=new long[nShrubs+1];
		for (int i=1; i<=nShrubs; i++) {
			redCS[i]=redCS[i-1]+nRed[i-1];
			blueCS[i]=blueCS[i-1]+nBlue[i-1];
		}
		dp=new long[2][bucketSize];
		for (int shrub=nShrubs-1; shrub>=0; shrub--) {
			for (int r=0; r<bucketSize; r++) {
				int redDelta=(int) ((redCS[shrub]-r)%bucketSize);
				int b=(int) ((blueCS[shrub]+redDelta)%bucketSize);

				long redRem=r+nRed[shrub], blueRem=b+nBlue[shrub];
				long best=0;
				final int max=(int) Math.min(bucketSize, nRed[shrub]);
				int min=(int) Math.max(0, bucketSize-nBlue[shrub]);
				int redRealModded=(int) (redRem-min)%bucketSize;
				int blueToTake=bucketSize-min;
				long redReal=redRem-min, blueReal=blueRem-blueToTake;
				long redRealFull=redReal/bucketSize;
				long blueRealFull=blueReal/bucketSize;
				long blueRealModded=blueReal%bucketSize;
				for (int redToTake=min; redToTake<=max; redToTake++, redRealModded--, blueToTake--, redReal--, blueReal++, blueRealModded++) {
					while (redRealModded<0) {
						redRealModded+=bucketSize;
						redRealFull--;
					}
					while (blueRealModded>=bucketSize) {
						blueRealModded-=bucketSize;
						blueRealFull++;
					}
//					long bonus=redReal/bucketSize+blueReal/bucketSize + 1;
					long bonus=redRealFull+blueRealFull+1;
					best=Math.max(best, bonus+dp[(shrub&1)^1][redRealModded]);
				}
				long bonus=redRem/bucketSize+blueRem/bucketSize;
				best=Math.max(best, bonus+dp[(shrub&1)^1][(int)(redRem%bucketSize)]);
				dp[shrub&1][r]=best;
			}
		}
		long ans=dp[0][0];
		System.out.println(ans);
		System.err.println(System.currentTimeMillis()-time);
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