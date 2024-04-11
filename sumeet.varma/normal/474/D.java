//package CodeStarLongJan2015;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Alien {

	static long ans[];
	static long MOD = 1000000007;
	static long pre[];
	
	public static void main(String args[] ) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st = new StringTokenizer(br.readLine());
	    int t = ip(st.nextToken());
	    int k = ip(st.nextToken());
	    
	    ans = new long[1000001];
	    
	    for(int i=1;i<k;i++)
	    	ans[i] = 1;
	    ans[k] = 2;
	    
	    for(int i=k+1;i<=1000000;i++)
	    	ans[i] = (ans[i-1] + ans[i-k]) % MOD;
	    
	    pre = new long[1000001];
	    for(int i=1;i<=1000000;i++)
	    	pre[i] = (ans[i] + pre[i-1]) % MOD;
	    
	    while(t-- > 0) {
	    	StringTokenizer st1 = new StringTokenizer(br.readLine());
	    	int a = ip(st1.nextToken());
	    	int b = ip(st1.nextToken());
	           
	        w.println((pre[b] - pre[a-1] + MOD) % MOD);
	    }
	        
	    w.close();
	        
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}