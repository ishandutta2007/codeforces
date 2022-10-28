//package Practise;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Round260ABoredom {

	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
	    
	    long hash[] = new long[100005];
	          
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    for(int i=0;i<n;i++){
	    	hash[ip(st2.nextToken())]++;
	    	
	    }
	    int max = 0;
	    
	    long dp[] = new long[100001];
	    dp[1] = hash[1];
	    if(hash[1] != 0)
	    	max = 1;
	    dp[2] = Math.max(hash[1], 2*hash[2]);
	    if(hash[2] != 0)
	    	max = 2;
	    
	    for(int i=3;i<=100000;i++){
	    	dp[i] = Math.max(dp[i-2] + i*hash[i], dp[i-1]);
	    	if(hash[i]!=0)
	    		max = i;
	    }
	    
	    w.println(dp[max]);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}