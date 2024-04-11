import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/*
10 2
0123456789
a??ab????b
 */
public class E {

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int n=fs.nextInt(), k=fs.nextInt();
		char[] a=fs.next().toCharArray();
		int min=0, max=n;
		while (min!=max) {
			int mid=(min+max+1)/2;
			if (solve(mid, a, k)) {
				min=mid;
			}
			else {
				max=mid-1;
			}
		}
		System.out.println(min);
	}
	static boolean solve(int requiredJump, char[] a, int k) {
		int n=a.length;
		int[][] prefixSumForChar = new int[k][n+1];
		for (int i=1; i<=n; i++) {
			for (int c=0; c<k; c++) {
				prefixSumForChar[c][i]=prefixSumForChar[c][i-1];
				if (a[i-1]==c+'a' || a[i-1]=='?') prefixSumForChar[c][i]++;
			}
		}
		int[][] nextPlaceForIndex=new int[k][n+1];
		for (int c=0; c<k; c++) nextPlaceForIndex[c][n]=n+1;
		for (int i=n-1; i>=0; i--) {
			for (int c=0; c<k; c++) {
				nextPlaceForIndex[c][i]=nextPlaceForIndex[c][i+1];
				if (i+requiredJump<=n && prefixSumForChar[c][i+requiredJump]-prefixSumForChar[c][i]==requiredJump)
					nextPlaceForIndex[c][i]=i;
			}
		}
		
		int[] earliestReachable=new int[1<<k];
		for (int mask=1; mask<1<<k; mask++) {
			earliestReachable[mask]=n+1;
			for (int last=0; last<k; last++) {
				if ((mask&(1<<last))==0) continue;
				int from=mask-(1<<last);
				int fromEnd=earliestReachable[from];
				if (fromEnd>=n) continue;
				int myStart=nextPlaceForIndex[last][fromEnd];
				earliestReachable[mask]=Math.min(earliestReachable[mask], myStart+requiredJump);
			}
		}
		return earliestReachable[(1<<k)-1]<=n;
	}

	static final Random random=new Random();
	
	static void ruffleSort(int[] a) {
		int n=a.length;//shuffle, then sort 
		for (int i=0; i<n; i++) {
			int oi=random.nextInt(n), temp=a[oi];
			a[oi]=a[i]; a[i]=temp;
		}
		Arrays.sort(a);
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