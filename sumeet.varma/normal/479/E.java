import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class RidingInALift {

	static long dp[][];
	static long m = (long) (1e9 + 7);
	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    int a = ip(st1.nextToken());
	    int b = ip(st1.nextToken());
	    int K = ip(st1.nextToken());
	          
	    if(a > b){
	    	a = n - a + 1;
	    	b = n - b + 1;
	    }
	    
	    dp = new long[3][n+1];
	    
	    for(int i=1;i<b;i++){
	    	int right = b-i-1;
	    	int left = Math.min(i-1, b-i-1);
	    	dp[1][i] = right + left;
	    }
	    
	    for(int k=2;k<=K;k++){
	    	dp[2][1] = 0;
	    	for(int i=2;i<b-1;i++)
	    		dp[2][1] = (dp[2][1] + dp[1][i]);
	    	dp[2][1] %= m;
	    	
	    	for(int i=2;i<b-1;i++){
	    		long prev = dp[2][i-1] % m;
	    		long rem = dp[1][i];
	    		long t1= (i!=(b-1) ? dp[1][i-1] : 0) % m;
	    		long t2 = ((2*i-b>0) ? dp[1][2*i-b] : 0) % m;
	    		long t3 = (((2*i-b-1)>0 ? dp[1][2*i-b-1] : 0)) % m;
	    		dp[2][i] = (prev - rem + t1 - t2 - t3 + m + m + m + m ) % m;
	    	}
	    	
	    	for(int i=1;i<b;i++)
	    		dp[1][i] = dp[2][i];
	    }
	  
	    w.println(dp[1][a]);
	    
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}