//package Round266Div2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class NumberOfWays {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    long a[] = new long[n];
	    long sum = 0;
	    for(int i=0;i<n;i++){
	    	a[i] = ip(st2.nextToken());
	    	sum += a[i];
	    }
	    
	    long ans = 0;
	    if(sum % 3 != 0)
	    	ans = 0;
	    else{
	    	long post[] = new long[n];
	    	long dp[] = new long[n];
	    	
	    	post[n-1] = a[n-1];
	    	if(post[n-1] == sum/3)
	    		dp[n-1] = 1;
	    	for(int i=n-2;i>=0;i--){
	    		post[i] = a[i] + post[i+1];
	    		dp[i] = dp[i+1];
	    		if(post[i] == sum/3)
	    			dp[i]++;
	    	}
	    	
	    	long s= 0;
	    	for(int i=0;i<n-2;i++){
	    		s += a[i];
	    		if(s == sum/3)
	    			ans += dp[i+2];
	    	}
	    }
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
}