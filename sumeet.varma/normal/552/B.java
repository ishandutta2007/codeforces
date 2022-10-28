import java.io.*;
import java.util.*;

public class R308qB {

	public static void main(String args[] ) throws Exception {
		   
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    PrintWriter w = new PrintWriter(System.out);
	    
	    int n = ip(br.readLine());
	    
	    int len = Integer.toString(n).length();
	    
	    long ans = 0;
	    
	    for(int i=1;i<len;i++)
	    	ans += i * 1L * (Math.pow(10, i) - Math.pow(10, i-1));
	        
	    ans += len * 1L * (n - Math.pow(10, len-1) + 1);
	    
	    w.println(ans);
	    w.close(); 
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}
	
	public static long lp(String s){
		return Long.parseLong(s);
	}
}