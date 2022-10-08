import java.util.Arrays;
import java.util.Scanner;
/*
 * 
3 3 1
aba

 */
public class C {

	static int n, a, b;
	static char[] line;
	static int[][] matchLenDP;
	static long[] dp;
	
	public static void main(String[] args) {
		Scanner fs = new Scanner(System.in);
		matchLenDP=new int[5001][5001];
		dp=new long[5001];
		for (int i=0; i<matchLenDP.length; i++)
			Arrays.fill(matchLenDP[i], -1);
		Arrays.fill(dp, -1);
		
		n=fs.nextInt();
		a=fs.nextInt();
		b=fs.nextInt();
		String lineSt=fs.next();
		line=lineSt.toCharArray();
		
		long ans=go(0);
		System.out.println(ans);
	}
	
	public static long go(int i) {
		//MEMOIZE
		if (dp[i]!=-1)
			return dp[i];
		
		if (i==n)
			return 0;
		if (i==0)
			return a+go(i+1);
		long cost=a+go(i+1);
		int longestMatch=0;
		for (int start=0; start<i; start++) {
			int match=Math.min(i-start, matchLen(start, i));
			longestMatch=Math.max(longestMatch, match);
		}
		if (longestMatch!=0) {
			cost=Math.min(cost, b+go(i+longestMatch));
		}
		
		return dp[i]=cost;
	}
	
	public static int matchLen(int a, int b) {
		//MEMOIZE
		if (b==n||line[a]!=line[b])
			return 0;
		if (matchLenDP[a][b]!=-1)
			return matchLenDP[a][b];
		return matchLenDP[a][b]=1+matchLen(a+1, b+1);
	}
	

}