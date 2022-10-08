import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class E {

	static long[][] dp;
	static int[][][] cs;
	
	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		int nRows=fs.nextInt(), n=fs.nextInt();
		//TODO: input + precomp
		//delta[l][r][mid]
		int[][][] delta=new int[n+3][n+3][n];
		for (int i=0; i<nRows; i++) {
			int nIntervals=fs.nextInt();
			for (int j=0; j<nIntervals; j++) {
				int leftmost=fs.nextInt()-1, rightmost=fs.nextInt()-1;
				for (int mid=leftmost; mid<=rightmost; mid++) {
					//increment l<leftmost and r>rightmost
					delta[0][rightmost+2][mid]++;
					delta[leftmost+1][rightmost+2][mid]--;
//					System.out.println("Adding delta at mid: "+mid+" +1: "+(0)+" "+(rightmost+1)+" -1: "+(leftmost+1)+" "+(rightmost+1)));
				}
			}
		}
		cs=new int[n+4][n+4][n];
		for (int mid=0; mid<n; mid++) 
			for (int i=1; i<cs.length; i++)
				for (int j=1; j<cs[i].length; j++)
					cs[i][j][mid]=cs[i-1][j][mid]+cs[i][j-1][mid]-cs[i-1][j-1][mid]+delta[i-1][j-1][mid];
		
		dp=new long[n+5][n+5];
		for (int i=0; i<dp.length; i++) Arrays.fill(dp[i], -1);
//		System.out.println(ifPlace(0, 4, 1)+" looking for "+2);
		long ans=go(-1, n);
		System.out.println(ans);
	}
	
	static long ifPlace(int l, int r, int mid) {
		return cs[l+2][r+2][mid];
	}
	
	static long go(int l, int r) {
		if (dp[l+1][r+1]!=-1) return dp[l+1][r+1];
		if (l==r-1) {
			return 0;
		}
		long best=0;
		for (int mid=l+1; mid<r; mid++) {
			long curWidth=ifPlace(l, r, mid);
			best=Math.max(best, curWidth*curWidth + go(l, mid) + go(mid, r));
		}
		return dp[l+1][r+1]=best;
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