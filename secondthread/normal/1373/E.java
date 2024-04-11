import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;
/*
1
132 3

1
99 0

1
42 7

 */

public class EDP {
	
	static int[][][] dp=new int[1000][10][151];

	public static void main(String[] args) {
		FastScanner fs=new FastScanner();
		for (int i=0; i<dp.length; i++)
			for (int j=0; j<dp[i].length; j++)
				Arrays.fill(dp[i][j], -1);
		int T=fs.nextInt();
		for (int tt=0; tt<T; tt++) {
			int targetSum=fs.nextInt(), k=fs.nextInt();
			if (dp(999, k, targetSum)) {
//				System.out.println("Possible");
				buildback(999, k, targetSum, false);
			}
			else {
				System.out.println("-1");
			}
		}
	}
	
	
	//returns whether this is possible
	static boolean dp(int digit, int k, int targetSum) {
		if (digit==0) {
			for (int start=0; start+k<10; start++) {
				int sum=0;
				for (int i=0; i<=k; i++) {
					sum+=start+i;
				}
				if (sum==targetSum) {
					return true;
				}
			}
			return false;
		}
		if (targetSum<0) return false;
		if (dp[digit][k][targetSum]!=-1) return dp[digit][k][targetSum]==1;
		for (int toPlace=0; toPlace<10; toPlace++) {
			int sumLeft=targetSum-toPlace*(k+1);
			if (dp(digit-1, k, sumLeft)) {
				dp[digit][k][targetSum]=1;
				return true;
			}
			if (toPlace!=9) {
				//bunch of 9s, then other stuff
				for (int first=10-k; first<10; first++) {
					int sum=0;
					for (int i=0; i<=k; i++) {
						if (first+i<10) {
							sum+=toPlace+(9*(digit-1))+(first+i);
						}
						else {
							sum+=(toPlace+1)+0+(first+i-10);
						}
					}
					if (sum==targetSum) {
						dp[digit][k][targetSum]=1;
						return true;
					}
				}
			}
		}
		dp[digit][k][targetSum]=0;
		return false;
	}
	
	static void buildback(int digit, int k, int targetSum, boolean placed) {
		if (digit==0) {
			for (int start=0; start+k<10; start++) {
				int sum=0;
				for (int i=0; i<=k; i++) {
					sum+=start+i;
				}
				if (sum==targetSum) {
					System.out.println(start);
					return;
				}
			}
			throw null;
		}
		if (targetSum<0) throw null;;
		for (int toPlace=0; toPlace<10; toPlace++) {
			int sumLeft=targetSum-toPlace*(k+1);
			if (dp(digit-1, k, sumLeft)) {
				dp[digit][k][targetSum]=1;
				boolean newPlaced=toPlace!=0 || placed;
				if (newPlaced) {
					System.out.print(toPlace);
				}
				buildback(digit-1, k, sumLeft, newPlaced);
				return;
			}
			if (toPlace!=9) {
				//bunch of 9s, then other stuff
				for (int first=10-k; first<10; first++) {
					int sum=0;
					for (int i=0; i<=k; i++) {
						if (first+i<10) {
							sum+=toPlace+(9*(digit-1))+(first+i);
						}
						else {
							sum+=(toPlace+1)+0+(first+i-10);
						}
					}
					if (sum==targetSum) {
//						System.out.println("First is "+first+" targetSum: "+targetSum);
						boolean newPlaced=toPlace!=0 || placed;
						if (newPlaced) {
							System.out.print(toPlace);
						}
						for (int i=0; i<digit-1; i++) {
							System.out.print(9);
						}
						System.out.println(first);
						return;
					}
				}
			}
		}
		throw null;
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