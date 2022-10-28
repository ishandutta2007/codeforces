//package Round266Div2;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class CheapTravel {

	public static void main(String args[] ) throws Exception {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	        
	    StringTokenizer st1 = new StringTokenizer(br.readLine());
	    int n = ip(st1.nextToken());
		int m = ip(st1.nextToken());
	    int a = ip(st1.nextToken());
	    int b = ip(st1.nextToken());
	    
	    long ans = 0;
	    
	    if(b < a*m){
	    	ans = (n/m)*b;
	    	n %= m;
	    	ans += Math.min(n*a, b);
	    }
	    else
	    	ans = a*n;
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
}