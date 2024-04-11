import java.io.*;
import java.util.*;

public class R239qDLongPath {

	static int n;
	static int p[];
	static long dp[],prefix[];
	static long mod = (long)(1e9 + 7);
	
	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	   
	    n = ip(br.readLine());
	    
	    StringTokenizer st2 = new StringTokenizer(br.readLine());
	    p = new int[n+1];
	    for(int i=1;i<=n;i++)
	    	p[i] = ip(st2.nextToken());
	        
	    dp = new long[n+1];
	    prefix = new long[n+1];
	   
	    for(int i=1;i<=n;i++){
	    	dp[i] =( 1 + prefix[i-1] - prefix[p[i] - 1] + i - p[i] + 1000 * mod) % mod;
	    	prefix[i] = (prefix[i-1] + dp[i] + 1000 * mod) % mod;
	    }
	    
	    w.println((prefix[n] + n + 1000 * mod) % mod);
	    w.close(); 
	}
	
	
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}