//package Round267Div2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class GerogeAndJob {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    int t = 1;
	    
	    while(t-- > 0) {
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	int n = ip(st1.nextToken());
	    	int m = ip(st1.nextToken());
	    	int K = ip(st1.nextToken());
	          
	        StringTokenizer st2 = new StringTokenizer(br.readLine());
	        int p[] = new int[n];
	        long pre[] = new long[n];
	        for(int i=0;i<n;i++){
	       	   p[i] = ip(st2.nextToken());
	       	   pre[i] = p[i] + pre[Math.max(0,i-1)];
	        }
	      /*  
	        long dp[][] = new long[K+1][n];
	        
	        for(int k=1;k<=K;k++){
	        	dp[1][m-1] = pre[m-1];
	        	for(int i=m;i<n;i++){
	        		dp[k][i] = Math.max(dp[k][i-1], dp[k-1][i-m] + pre[i] - pre[i-m]);
	        	}
	        }
	        
	        */
	        long dp[][] = new long[3][n];
	        for(int k=1;k<=K;k++){
	        	dp[2][m-1] = pre[m-1];
	        	for(int i=m;i<n;i++){
	        		dp[2][i] = Math.max(dp[2][i-1], dp[1][i-m] + pre[i] - pre[i-m]);
	        	}
	        	for(int i=0;i<n;i++)
	        		dp[1][i] = dp[2][i];
	        }
	        w.println(dp[1][n-1]);
	    }
	        
	    w.close();
	        
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}