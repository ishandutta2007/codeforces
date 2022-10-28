import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class IncreaseSequence {
	
	static int n,h;
	static int a[];
	static long dp[][];
	static long mod = (long)(1e9 + 7);
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    n = ip(st1.nextToken());
		h = ip(st1.nextToken());
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = ip(st2.nextToken());
	        
	    dp = new long[n][n+1];
	    for(int i=0;i<n;i++)
	    	Arrays.fill(dp[i], -1);
	    
	    w.println(solve(0,0));
	    w.close(); 
	}
	
	public static long solve(int curr,int open){
		if(curr == n) return open == 0 ? 1 : 0;
		
		if(dp[curr][open] == -1){
			if(a[curr] + open == h-1)
				dp[curr][open] = solve(curr+1,open+1) + (open+1)*solve(curr+1,open);
			else if(a[curr] + open == h)
				dp[curr][open] = (open == 0 ? 0 : open*solve(curr+1,open-1)) + solve(curr+1,open);
			else
				dp[curr][open] = 0;
			if(dp[curr][open] >= mod)
				dp[curr][open] %= mod;
		}
		
		return dp[curr][open];
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}